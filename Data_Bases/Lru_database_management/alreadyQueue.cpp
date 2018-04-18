#include <queue>
#include <iostream>
using namespace std;
int const numberOfFrames = 6;
int clockHand = -1;

class Node{
	public:
		int pageNo;
		int frameNo;
		Node(int apageNo,int aframeNo){
			pageNo = apageNo;
			frameNo = aframeNo;
		};
};

void advanceClock() {
	//we devide with the number o frames in order to have number only between [1,number of frames]
	clockHand = (clockHand+1)%numberOfFrames;
	//we use this variable in order to iterate all the frames in the bufferpool
	//cout << clockHand << "\n";
	
}

deque<Node*> LRU_algorithm(int apageNo , deque<Node*> q){
	//take the first node of the queue
	deque<Node*> q2 = q;
	int count = 0;
	advanceClock();
	while(count < q.size() && count < numberOfFrames){
		Node* current = q2.front();
		//cout << "frame: " << current->frameNo << endl;
		//cout << "page: " << current->pageNo << endl;
		if(/*(current->frameNo != NULL) &&*/ (current->pageNo != NULL)){//is wrong because it means that the value was not found
			//cout << "front page: " << current->pageNo << endl;
			//check if you found the record that you want
			if (current->pageNo == apageNo){
				//if you found it then you put it at the end of the queue
				cout << "page: " << current->pageNo  << " already inside the list" << endl;	
				 // erase the first 3 elements:
  				q.erase(q.begin()+count);				
				q.push_back(current);
				break;
			}
			else{
				//otherwise you continue the loop
				q2.pop_front();
				
			}		
		}
		count++;
	}
	//cout << "count: " << count << endl;
	//cout << "size: " << q.size() << endl;
	//if we reached the end of the queue it means that we did not find the element that we searched for , so we add it at the end of the queue
	if (count == q.size() && count < numberOfFrames){
		cout << "element not found " << endl;
		//make a new node for this element
		Node* giannis = new Node(apageNo,clockHand);
		//push it at the back of the queue , which means that this is the element (frame) that we used recently
		q.push_back(giannis);
	}
	//this means that we did not find the element in the queue and the queue is full , se we have to erase tha least recently used element which is in the beggining of the queue
	else if(count == q.size() && count == numberOfFrames){
		//pop the first element
		cout << "pop the first element of the queue: " << q.front()->pageNo << endl;
		int tmp = q.front()->frameNo;
		q.pop_front();
		//and push the new element as the last element of the queue
		Node* newNode = new Node(apageNo,tmp);
		q.push_back(newNode);
	}
	return q;
}

void printList(deque<Node*> listOfRecords){
	cout << "myqueue contains: " << endl;
	for (deque<Node*>::iterator it = listOfRecords.begin(); it!=listOfRecords.end();++it){
		Node* newNode = *it;
		cout << " " << newNode->pageNo << " ";
	} 
	cout << "\n";
	for (deque<Node*>::iterator it = listOfRecords.begin(); it!=listOfRecords.end();++it){
		Node* newNode = *it;
		cout << " " << newNode->frameNo << "   ";
	} 
	cout << "\n";
	cout << "\n";
	cout << "\n";
}

int main(){
	deque<Node*> listOfRecords;
	/*Node* giannis = new Node(1,2);
	listOfRecords.push_back(giannis);
	Node* kwstas = new Node(10,65);
	listOfRecords.push_back(kwstas);
	Node* manos = new Node(100,43);
	listOfRecords.push_back(manos);
	Node* panos = new Node(40,12);
	listOfRecords.push_back(panos);
	Node* petros = new Node(32,28);
	listOfRecords.push_back(petros);*/

	printList(listOfRecords);
	cout << "incoming page: 50" << endl;
	listOfRecords = LRU_algorithm(50 ,  listOfRecords);
	printList(listOfRecords);
	//Node* gamaw = new Node(50,50);
	//listOfRecords.push_back(gamaw);
	cout << "incoming page: 40" << endl;
	listOfRecords = LRU_algorithm(40 ,  listOfRecords);
	printList(listOfRecords);
	cout << "incoming page: 60" << endl;
	listOfRecords = LRU_algorithm(60 ,  listOfRecords);
	printList(listOfRecords);
	cout << "incoming page: 80" << endl;
	listOfRecords = LRU_algorithm(80 ,  listOfRecords);
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
