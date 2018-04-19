#include <iostream>
#include <list>
using namespace std;


class QueueEmptyException{
	public:
		QueueEmptyException()
		{
			cout << "Queue empty" << endl;	
		}
};

class Node{
	public:
		int pageNo;
		int frameNo;
		Node* next;
};

class ListQueue{
	private:
		Node* front;
		Node* back;
		int count;
		//list<Node*> listOfRecords;

	public:
		ListQueue(){
			front = NULL;
			back = NULL;
			count = 0;
			//std::list<Node> listOfRecords;		
		}

	void printList(ListQueue q){
		int count = 0;
		Node* current = q.Front();
		while(count < q.Size()){
			cout << "page: " << current->pageNo << " , frame: " << current->frameNo << endl;
			current = current->next;
			count++;
		}
	}


	
	bool elementFound(int apageNo , int aframeNo, ListQueue q){
		//take the first node of the queue
		Node* current = q.Front();
		int count = 0;
		while(count < q.Size()){
			// << "frame: " << current->frameNo << endl;
			//cout << "page: " << current->pageNo << endl;
			if((current->frameNo != NULL) && (current->pageNo != NULL)){//is wrong because it means that the value was not found
				//check if you found the record that you want
				if (current->pageNo == apageNo){
					//if you found it then you put it at the end of the queue
					cout << "page: " << current->pageNo << " , frame: " << current->frameNo << " already inside the list" << endl;
					cout << "print the new list" << endl;					
					back->next = current;
					back = current;
					break;
				}
				else{
					//otherwise you continue the loop
					current = current->next;
					count++;
				}		
			}
		}
	}

	void Enqueue(int apageNo , int aframeNo){
		//Create new Node
		Node* tmp = new Node();
		tmp->pageNo = apageNo;
		tmp->frameNo = aframeNo;
		tmp->next = NULL;

		if ( isEmpty() ){
			//Add the first element
			front = back = tmp;
			//listOfRecords.push_back(back);
		}
		else{
			//Append to the list
			back->next = tmp;
			back = tmp;
			//listOfRecords.push_back(back);
		}
		count++;
	}

	int Dequeue(){
		if( isEmpty() ){
			throw new QueueEmptyException();		
		}	
		Node* tmp = front;
		//Move the front pointer to the next node
		front = front->next;
		count--;
		delete tmp;	
	}

	Node* Front(){
		if( isEmpty() ){throw new QueueEmptyException();}
		return front;
	}

	int Size(){
		return count;
	}

	bool isEmpty(){
		return (count == 0);
	}
};


int main(){
	ListQueue q;
	try{
		if (q.isEmpty() ){
			cout << "Queue is empty" << endl;
		}

		//Enqueue pages
		//page , frame
		q.Enqueue(1,2);
		q.Enqueue(4,89);
		q.Enqueue(6,128);

		q.printList(q);
		q.elementFound(4,89,q);
		q.printList(q);

		cout << "Size of queue: " << q.Size() << endl;

		//Front Element
		Node* node  = q.Front();
		cout << node->pageNo << endl;
		Node* nextNode = node->next;
		cout << nextNode->pageNo << endl;
		
	}
	catch(...){
		cout << "Some exception occured" << endl;
	}
}
