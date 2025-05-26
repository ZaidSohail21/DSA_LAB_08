#include "LinkedList.h"

class myDLL :public LinkedList
{
	
public:
	void insertAtTail(int);
	void insertAtHead(int);
	void insertAtPosition(int value, int position);
	void displayFromHead();
	void displayFromTail();
	bool isEmpty();
	int deleteFromTail();
	int deleteFromHead();
	void deleteAtPosition(int );
	bool deleteValue(int);
	bool search(int);
	int count();
	/*


	bool search(int);

	*/
	//void insertSorted(int);
};


bool myDLL::deleteValue(int value)
{
	if (isEmpty())
		return false;

	else if (head == tail) //single node
	{
		if (head->data == value)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return true;
		}

		else
			return false;
	}

	else if (head->data == value)
	{
		deleteFromHead();
		return true;
	}

	else if (tail->data == value)
	{
		deleteFromTail();
		return true;
	}

	else
	{
		Node* temp = head;

		while (1)
		{
			if (temp->data == value)
				break;

			else
				temp = temp->next;

			if (temp == tail)
				return false;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		temp = nullptr;

		return true;
	}

}

int myDLL::deleteFromHead()
{
	if (isEmpty())
		return NULL;

	if (head == tail) //single node case
	{
		int returningValue = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		int returningValue = head->data;

		head = head->next;
		delete head->prev;
		head->prev = nullptr;

		return returningValue;

	}
}

int myDLL::count()
{
	if (isEmpty())
		return NULL;

	if (head == tail) //single node case
	{
		
		return 1;
	}

	else
	{
		int c = 1;
		Node* temp = head;
		while (temp != tail) {
			temp = temp->next;
			c++;
		}
		return c;

	}
}
void myDLL::insertAtPosition(int value, int position)
{
	if (position <= 0)
	{
		cout << "Invalid position!" << endl;
		return;
	}

	if (position == 1)
	{
		insertAtHead(value);
		return;
	}

	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;
	nn->prev = nullptr;

	Node* temp = head;

	for (int i = 1; temp != nullptr && i < position - 1; i++)
	{
		temp = temp->next;
	}

	if (!temp)
	{
		cout << "Position out of bounds, inserting at tail." << endl;
		insertAtTail(value);
		return;
	}

	nn->next = temp->next;
	nn->prev = temp;

	if (temp->next) {
		temp->next->prev = nn;
	}
	temp->next = nn;

	if (temp == tail) {
		tail = nn;
	}
}

void myDLL::deleteAtPosition(int position)
{
	if (position <= 0 || head == nullptr)
	{
		cout << "Invalid position!" << endl;
		return;
	}

	if (position == 1)
	{
		Node* temp = head;
		head = head->next;

		if (head)
			head->prev = nullptr;

		else
			tail = nullptr;

		delete temp;
		temp = nullptr;

		return;
	}

	Node* temp = head;

	for (int i = 1; temp != nullptr && i < position; i++)
	{
		temp = temp->next;
	}

	if (!temp)
	{
		cout << "Position out of bounds!" << endl;
		return;
	}

	if (temp->prev)
		temp->prev->next = temp->next;

	if (temp->next)
		temp->next->prev = temp->prev;

	if (temp == tail)
		tail = temp->prev;

	delete temp;
}

int myDLL::deleteFromTail()
{
	if (isEmpty())
		return NULL;

	if (head == tail) //single node case
	{
		int returningValue = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		int returningValue = tail->data;
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
		return returningValue;

	}
}

void myDLL::insertAtTail(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;
	nn->prev = nullptr;

	if (head == nullptr && tail == nullptr) //empty LL
	{
		head = nn;
		tail = nn;
	}

	else //non-empty LL
	{
		nn->prev = tail;
		tail->next = nn;
		tail = nn;
	}
}

void myDLL::insertAtHead(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;
	nn->prev = nullptr;

	if (head == nullptr && tail == nullptr) //empty LL
	{
		head = nn;
		tail = nn;
	}

	else //non-empty LL
	{
		nn->next = head;
		head->prev = nn;
		head = nn;

	}
}

bool myDLL::isEmpty()
{
	return head == nullptr && tail == nullptr;
}

void myDLL::displayFromHead()
{
	if (head == nullptr && tail == nullptr)
		cout << "LL is empty" << endl;

	else
	{
		Node* temp = head;

		while (1)
		{
			cout << temp->data << endl;
			temp = temp->next;

			if (temp == nullptr)
				break;
		}
	}
}

void myDLL::displayFromTail()
{
	if (head == nullptr && tail == nullptr)
		cout << "LL is empty" << endl;

	else
	{
		Node* temp = tail;

		while (1)
		{
			cout << temp->data << endl;
			temp = temp->prev;

			if (temp == nullptr)
				break;
		}
	}
}
bool myDLL::search(int value)
{
	Node* temp = head;
	while (temp)
	{
		if (temp->data == value)
			return true;

		temp = temp->next;
	}
	return false;
}


//void myDLL::insertSorted(int value)
//{
//	if (isEmpty())
//	{
//		Node*nn = nullptr;
//		nn = new Node;
//		nn->data = value;
//		nn->next = nullptr;
//
//		head = nn;
//		tail = nn;
//	}
//
//	else if (value <= head->data)
//		insertAtHead(value);
//
//	else if (value >= tail->data)
//		insertAtTail(value);
//
//	else	// insert in between
//	{
//		Node*nn = nullptr;
//		nn = new Node;
//		nn->data = value;
//		nn->next = nullptr;
//
//
//		Node*temp = head;
//
//		while(1)
//		{
//			if (temp->data<value && temp->next->data>=value)
//				break;
//
//			else
//				temp = temp->next;
//		}
//
//		nn->next = temp->next;
//		temp->next = nn;
//	}
//
//}
