#include<iostream>
using namespace std;
// definiton of structure Node
struct Node {
	int data;
	struct Node *next;
};
// linked List class definiton.
class LinkedList {
	struct Node *start;
public:
	LinkedList();
	void insertAt(int,int);
	void deleteSpec(int);
	void traverseForward();
	void traverseBackward();
	void reverse();
	~LinkedList();
	friend void print(struct Node *);
};
// default constructor allocates NULL to start pointer
LinkedList::LinkedList() {
	start = NULL;
}
// destructor deletes the memory to each element in list;
LinkedList::~LinkedList() {
	struct Node *temp;
	while (start != NULL) {
		temp = start;
		start = temp->next;
		delete temp;
	}
}
// insertAt() function takes two elements as inputs, first the element to be inserted and second the position at which element to be inserted.
void LinkedList::insertAt(int x, int pos) {
	if (start != NULL) {
		int count=0;
		struct Node *temp;
		temp = new Node;
		temp->data = x;
		
		struct Node *curr;
		curr = start;
		while (curr!=NULL && count < pos-1) {
			curr = curr->next;
			count = count + 1;
		}
		if (curr != NULL) {
			if (pos == 0) {
				temp->next = start;
				start = temp;
			}
			else {
				temp->next = curr->next;
				curr->next = temp;
			}
		}
		else {
			cout << "cannot insert at that position";
		}
	}
	else {
		if (pos != 0) {
			cout << "cannot insert at that position:";
		}
		else {
			struct Node *temp;
			temp = new Node;
			temp->data = x;
			temp->next = start;
			start = temp;
		}
	}



}
// deleteSpec function takes an integer as input, function searches the list for that element and deletes if it founds.
void LinkedList::deleteSpec(int x) {
	if (start != NULL) {
		if (start->data == x) {
			struct Node *temp;
			temp = start;
			start = temp->next;
			delete temp;
		}
		else {
			struct Node *curr;
			curr = start;
			while (curr->next != NULL && curr->next->data != x)
				curr = curr->next;
			//cout << "hello";
			if (curr->next != NULL) {
				struct Node *temp;
				temp = curr->next;
				curr->next = temp->next;
				delete temp;

			}
			else
				cout << "element not found";

		}
	}
	else
		cout << "LinkedList is empty" << endl;
}
// traverseforward funtion traverse through all the elements in forward direction.
void LinkedList::traverseForward() {
	struct Node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
}
// traverseBackward function traverse through all the elements of list in reverse direction.
void LinkedList::traverseBackward() {
	if (start != NULL)
		print(start);
}
// print function used to print elements of list
void print(struct Node *curr) {
	if (curr != NULL) {
		print(curr->next);
		cout << curr->data << " ";
	}
}
// reverse function reverses the list
void LinkedList::reverse() {
	struct Node *rev = NULL;
	struct Node *temp;
	while (start != NULL) {
		temp = start;
		start = temp->next;
		temp->next = rev;
		rev = temp;
	}
	start = rev;
}
int main() {
	int x, s, op;
	LinkedList ll;
	while (1) {
		cout << "select an option:\n1.insert at position\n2. de;ete specific element\n3.traverse Forward\n 4.traverse backward\n 5.reverse\n 6.exit\n";
		cin >> op;
		switch (op) {
		case 1:
			int pos;
			cout << "enter element to be inserted and at which position\n";
			cin >> x >> pos;
			ll.insertAt(x, pos);
			break;
		case 2:
			cout << "enter element to be deleted\n";
			cin >> x;
			ll.deleteSpec(x);
			break;
		case 3:
			ll.traverseForward();
			break;
		case 4:
			ll.traverseBackward();
			break;
		case 5:
			ll.reverse();
			break;
		case 6:
			exit(0);
		default:
			cout << "enter valid option";
			break;
		}

	}
}