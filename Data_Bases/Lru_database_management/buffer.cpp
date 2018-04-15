/**
 * @author See Contributors.txt for code contributors and overview of BadgerDB.
 *
 * @section LICENSE
 * Copyright (c) 2012 Database Group, Computer Sciences Department, University of Wisconsin-Madison.
 */

#include <queue>
#include <memory>
#include <iostream>
#include "buffer.h"
#include "exceptions/buffer_exceeded_exception.h"
#include "exceptions/page_not_pinned_exception.h"
#include "exceptions/page_pinned_exception.h"
#include "exceptions/bad_buffer_exception.h"
#include "exceptions/hash_not_found_exception.h"

using namespace std;
int numberOfFrames;
deque<int> listOfRecords;
int count = 0;

namespace badgerdb { 

BufMgr::BufMgr(std::uint32_t bufs)
	: numBufs(bufs) {
	bufDescTable = new BufDesc[bufs];
	numberOfFrames = bufs;

  for (FrameId i = 0; i < bufs; i++) {
  	bufDescTable[i].frameNo = i;
  	bufDescTable[i].valid = false;
  }

  bufPool = new Page[bufs];

  int htsize = ((((int) (bufs * 1.2))*2)/2)+1;
  hashTable = new BufHashTbl (htsize);  // allocate the buffer hash table

  clockHand = bufs - 1;
}

/* 
 Write all the modified pages to disk and free the memory
 allocated for buf description and the hashtable.
*/
BufMgr::~BufMgr() {
  for(FrameId i =0; i<numBufs;i++){
    if(bufDescTable[i].dirty == true)
      bufDescTable[i].file->writePage(bufPool[i]);
    }
  free(bufDescTable);
  delete[] bufPool;
  free(hashTable);
}

/* 
 Increment the clockhand within the circular buffer pool .
*/
void BufMgr::advanceClock() {
	//we devide with the number o frames in order to have number only between [1,number of frames]
	clockHand = (clockHand+1)%numBufs;
	//we use this variable in order to iterate all the frames in the bufferpool
	//cout << clockHand << "\n";
	
}


void printList(deque<int> listOfRecords){
	cout << "myqueue contains: " << endl;
	for (deque<int>::iterator it = listOfRecords.begin(); it!=listOfRecords.end();++it){
		cout << " " << *it << " ";
	} 
	cout << "\n";
	cout << "\n";
	cout << "\n";
}

//LRU ALGORITHM
void BufMgr::allocBuf(FrameId & frame) {	
	//declare the pulse of the clock
	//clock algorithm
	//cout << "page number: " << bufDescTable[clockHand].pageNo << "\n";
	//cout << "frame number: " << bufDescTable[clockHand].frameNo << "\n";
	//cout << "corresponding fle number: " << bufDescTable[clockHand].file << "\n";
	//cout << "pin count" << bufDescTable[clockHand].pinCnt << "\n";
	std::uint32_t clockCount = 0;
	while(1){
		//one step forward
		advanceClock();
			//check the specific page(clockHand) if it is valid
		if(bufDescTable[clockHand].valid == true){
			//If this page has been pinned at least once 
			

			//If this page has been pinned at least once 
			if(bufDescTable[clockHand].pinCnt > 0){
				//if this page has already been pinned , we continue to the next
				clockCount++;
				int tmp = listOfRecords.front();
				listOfRecords.pop_front();
				listOfRecords.push_back(tmp);
				//if every pages is being pinned in buffer pool, throw exception
				if(clockCount > numBufs){
					throw BufferExceededException();
				}
				//continue the loop
				continue;
			}
			if (count < numberOfFrames){
			//i put the frames inside , the buffer pool is not full yet
				listOfRecords.push_back(bufDescTable[clockHand].frameNo);
				count++;
				
			//if the specific page is not valid
			}
			else{
				//this means that the buffer pool is full and we need to allocate a frame , using the LRU algorithm
				int tmp = listOfRecords.front();
				listOfRecords.pop_front();
				listOfRecords.push_back(tmp);
				clockHand = tmp;
			}
			//}
			//if the page is dirty the call the function flushFile, we write the information to the file(in the end at the disk)
			if(bufDescTable[clockHand].dirty == true){
				flushFile(bufDescTable[clockHand].file);
				//initialize the dirty variable to false(which means that we do not have to write this information that this page contains to the disk)
				bufDescTable[clockHand].dirty = false;
			}
			else{
				//if the page is not dirty , it means that has already write this information to the file , se i remove it 
				//se we remove this entry from the hashTable
				hashTable->remove(bufDescTable[clockHand].file, bufDescTable[clockHand].pageNo);
			}
			break;
		}
		else{
			if (count < numberOfFrames){
			//i put the frames inside , the buffer pool is not full yet
				listOfRecords.push_back(bufDescTable[clockHand].frameNo);
				count++;
			}
			else{
				//this means that the buffer pool is full and we need to allocate a frame , using the LRU algorithm
				int tmp = listOfRecords.front();
				listOfRecords.pop_front();
				listOfRecords.push_back(tmp);
				clockHand = tmp;
			}
			break;
		}
	}

//take the frame number of the frame that is being used right now
//and return the frame by reference


frame = bufDescTable[clockHand].frameNo;

}

/*
 This function reads a page of a file from the buffer pool
 if it exists. Else, fetches the page from disk, allocates
 a frame in the bufpool by calling allocBuf function and
 returns the Page. 
*/
void BufMgr::readPage(File* file, const PageId pageNo, Page*& page) {


		FrameId frameNo;
		try {
			//search for the requested page in the hashtable
			hashTable->lookup(file, pageNo, frameNo);
			//if the page is found , set the reference bit True
			bufDescTable[frameNo].refbit = true;
			//point that this page has been pinned one more time
			bufDescTable[frameNo].pinCnt++;
			// return the page by reference     
			page = &bufPool[frameNo];
		}
		catch (HashNotFoundException h) {
			//we did not find the page in the hashtable, this means that we a have a buffer miss
			//because of this we need to read this specific page from the disk
			Page p = file->readPage(pageNo);
			//now we have to allocate a new buffer frame in oder to place the page from the disk
			//maybe here we have a BufferExceededException, if we can not allocate a new frame , which means that he memory
			//is full
			allocBuf(frameNo);
			// add the page to buffer pool
			bufPool[frameNo] = p;
			// insert the record in hash table
			hashTable->insert(file, pageNo, frameNo);
			// set arguments , initialize the frame fields (pinCnt=1, valid=1, refbit=1, dirty=0)
			bufDescTable[frameNo].Set(file, pageNo);
			// return the page by reference
			page = &bufPool[frameNo];
		}
  
}

/*
 This function decrements the pincount for a page from the buffer pool.
 Checks if the page is modified, then sets the dirty bit to true.
 If the page is already unpinned throws a PageNotPinned exception.
*/
void BufMgr::unPinPage(File* file, const PageId pageNo, const bool dirty) {

		FrameId frameNo;
		// look up hashtable
		// ATTENTION: this line might throw BufferExceededException
		hashTable->lookup(file, pageNo, frameNo);
		// find this frame in bufDescTable
		BufDesc frame = bufDescTable[frameNo];
		// if this page is already unpinned, throw exception
		if (frame.pinCnt <= 0) 
			throw PageNotPinnedException(file->filename(), pageNo, frameNo);
		// set the dirty bit if we need to
		if (dirty) 
			bufDescTable[frameNo].dirty = true;
		// decrement pin count
		bufDescTable[frameNo].pinCnt--;
		
		 
}

/*
 Checks for all the pages which belong to the file in the buffer pool.
 If the page is modified, then writes the file to disk and clears it
 from the Buffer manager. Else, if its being referenced by other
 services, then throws a pagePinnedException.
 Else if the frame is not valid then throws a BadBufferException.
*/
void BufMgr::flushFile(const File* file) {
		// traverse the buffer
		for(uint32_t i = 0; i < numBufs; i++){
			BufDesc frame = bufDescTable[i];
			// if the current frame belongs to the desired file
			if (frame.file == file ) {
				// if the frame is not valid, throw BadBufferException
				if (!frame.valid) 
					throw BadBufferException(frame.frameNo, frame.dirty, frame.valid, frame.refbit);
				// if the frame is pinned, throw PagePinnedException
				if (frame.pinCnt > 0) 
					throw PagePinnedException(file->filename(), frame.pageNo, frame.frameNo);
				// if the frame is dirty, write it to disk, then set dirty to false
				if (frame.dirty) {
					Page p = bufPool[frame.frameNo];
					bufDescTable[i].file->writePage(p);
					bufDescTable[i].dirty = false;
				}
				// remove the page from hashtable
				hashTable->remove(file, frame.pageNo);
				// clear the buffer frame
				bufDescTable[i].Clear();
			} 
		}
  
}

/*
 This function allocates a new page and reads it into the buffer pool.
*/
void BufMgr::allocPage(File* file, PageId &pageNo, Page*& page) {
	

		FrameId frameNo;
		// allocate a new page in file
		Page p = file->allocatePage();
		// allocate a buffer frame
		// ATTENTION: this line might throw BufferExceededException
		allocBuf(frameNo);
		// put the new page in buffer
		bufPool[frameNo] = p;
		// insert a new entry in hashtable
		hashTable->insert(file, p.page_number(), frameNo);
		// call Set()
		bufDescTable[frameNo].Set(file, p.page_number());
		// set return values
		pageNo = p.page_number();
		page = &bufPool[frameNo];
}

/* This function is used for disposing a page from the buffer pool
   and deleting it from the corresponding file
*/
void BufMgr::disposePage(File* file, const PageId PageNo) {
 

		FrameId frameNo;
		// try to find the page in hash table
		// ATTENTION: this line might throw HashNotFoundException
		hashTable->lookup(file,PageNo,frameNo);
		// remove the hash table record
		hashTable->remove(file,PageNo);
		// clear the corresponding buffer frame
		bufDescTable[frameNo].Clear();
		// delete this page on disk
		file->deletePage(PageNo);
	
}

void BufMgr::printSelf(void) 
{
  BufDesc* tmpbuf;
	int validFrames = 0;
  
  for (std::uint32_t i = 0; i < numBufs; i++)
	{
  	tmpbuf = &(bufDescTable[i]);
		std::cout << "FrameNo:" << i << " ";
		tmpbuf->Print();

  	if (tmpbuf->valid == true)
    	validFrames++;
  }

	std::cout << "Total Number of Valid Frames:" << validFrames << "\n";
}

}
