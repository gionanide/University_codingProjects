#include <queue>
#include <iostream>
using namespace std;
int const numberOfFrames = 6;
int clockHand = -1;
int count = 0;



deque<int> LRU_algorithm(int frameNo,deque<int> q){
	//take the first node of the queue
	deque<int> q2 = q;
	//cout << "count: " << count << endl;
	//cout << "size: " << q.size() << endl;
	//if we reached the end of the queue it means that we did not find the element that we searched for , so we add it at the end of the queue
	if (count < numberOfFrames){
		//cout << "element not found " << endl;
		//make a new node for this element
		int giannis = frameNo;
		//push it at the back of the queue , which means that this is the element (frame) that we used recently
		q.push_back(giannis);
		count++;
	}
	//this means that we did not find the element in the queue and the queue is full , se we have to erase tha least recently used element which is in the beggining of the queue
	else{
		//pop the first element
		cout << "pop the first element of the queue: " << q.front() << endl;
		int tmp = q.front();
		cout << "frame i am going to allocate: " << tmp << endl;
		q.pop_front();
		//and push the new element as the last element of the queue
		int newFrame = frameNo;
		q.push_back(newFrame);
	}
	return q;
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

int main(){
	deque<int> listOfRecords;
	printList(listOfRecords);
	cout << "incoming page: 50" << endl;
	listOfRecords = LRU_algorithm(0 ,  listOfRecords);
	printList(listOfRecords);
	//Node* gamaw = new Node(50,50);
	//listOfRecords.push_back(gamaw);
	cout << "incoming page: 40" << endl;
	listOfRecords = LRU_algorithm(1 ,  listOfRecords);
	printList(listOfRecords);
	cout << "incoming page: 60" << endl;
	listOfRecords = LRU_algorithm(2 ,  listOfRecords);
	printList(listOfRecords);
	cout << "incoming page: 80" << endl;
	listOfRecords = LRU_algorithm(3 ,  listOfRecords);
	printList(listOfRecords);
	cout << "incoming page: 90" << endl;
	listOfRecords = LRU_algorithm(90 ,  listOfRecords);
	printList(listOfRecords);
	cout << "incoming page: 100" << endl;
	listOfRecords = LRU_algorithm(100 , listOfRecords);
	printList(listOfRecords);
	cout << "incoming page: 40" << endl;
	listOfRecords = LRU_algorithm(40 ,  listOfRecords);
	printList(listOfRecords);
	cout << "incoming page: 80" << endl;
	listOfRecords = LRU_algorithm(80 ,  listOfRecords);
	printList(listOfRecords);
	cout << "incoming page: 32" << endl;
	listOfRecords = LRU_algorithm(32 ,  listOfRecords);
	printList(listOfRecords);
	cout << "incoming page: 190" << endl;
	listOfRecords = LRU_algorithm(190 , listOfRecords);
	printList(listOfRecords);
	cout << "incoming page: 80" << endl;
	listOfRecords = LRU_algorithm(80 ,  listOfRecords);
	printList(listOfRecords);

}
