#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};
class List {
	struct Node *start;
public:
	List();
	void insertFirst(int);
	void insertLast(int);
	void insertAfter(int, int);
	void insertBefore(int, int);
	int deleteFirst();
	int deleteLast();
	void deleteSpec(int);
	void traverseForward();
	void traverseBackward();
	void reverse();
	void selfAdjusting(int);
	~List();
	friend void print(struct Node *);
};
List::List() {
	start = NULL;
}
List::~List() {
	struct Node *temp;
	while (start != NULL) {
		temp = start;
		start = temp->next;
		delete temp;
	}
}
void List::insertFirst(int x) {
	struct Node *temp;
	temp = new Node;
	temp->data = x;
	temp->next = start;
	start = temp;

}
void List::insertLast(int x) {
	struct Node *temp;
	temp = new Node;
	temp->data = x;
	temp->next = NULL;
	if (start != NULL) {
		struct Node *curr;
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;

	}
	else {
		start = temp;
	}

}
void List::insertAfter(int s, int x) {
	if (start != NULL) {
		struct Node *curr, *temp;
		curr = start;
		while (curr != NULL && curr->data != s)
			curr = curr->next;
		if (curr != NULL) {
			temp = new Node;
			temp->data = x;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "element not found" << endl;
	}
	else
		cout << "list is empty" << endl;
}

void List::insertBefore(int s, int x) {
	if (start != NULL) {
		if (start->data == s) {
			struct Node *temp;
			temp = new Node;
			temp->data = x;
			temp->next = start;
			start = temp;
		}
		else {
			struct Node *curr;
			curr = start;
			while (curr->next != NULL && curr->next->data != s)
				curr = curr->next;
			if (curr->next != NULL) {
				struct Node * temp;
				temp = new Node;
				temp->data = x;
				temp->next = curr->next;
				curr->next = temp;
			}
			else
				cout << "element not found" << endl;
		}



	}
	else
		cout << "list is empty" << endl;

}

int List::deleteFirst() {
	int x = -999;
	if (start != NULL) {
		struct Node *temp;
		temp = start;
		start = start->next;
		x = temp->data;
		delete temp;
	}
	else {
		cout << "list is empty";
	}
	return x;
}
int List::deleteLast() {
	int x = -999;
	if (start != NULL) {
		if (start->next == NULL) {
			x = start->data;
			delete start;
			start = NULL;
		}
		else {
			struct Node *curr;
			curr = start;
			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			delete curr->next;
			curr->next = NULL;
		}
	}
	else {
		cout << "list is empty";
	}
	return x;
}
void List::deleteSpec(int x) {
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
		cout << "list is empty" << endl;
}
void List::traverseForward() {
	struct Node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
}
void List::traverseBackward() {
	if (start != NULL)
		print(start);
}
void print(struct Node *curr) {
	if (curr != NULL) {
		print(curr->next);
		cout << curr->data << " ";
	}
}
void List::selfAdjusting(int s) {
	
	if (start != 0) {
		struct Node *temp, *curr;
		curr = start;
		while (curr->next != NULL && curr->next->data != s)
			curr = curr->next;
		if (curr->next != NULL) {
			temp = curr->next;
			curr->next = temp->next;
			temp->next = start;
			start = temp;
		}
		else {
			cout << "given element not found";
		}
	}
	else
		cout << "no elements in the list";
}
void List::reverse() {
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
	List ll;
	while (1) {
		cout << "choose the choice:" << endl;
		cout << "1.insert at begining" << endl;
		cout << "2.insert at end" << endl;
		cout << "3.insert after an element" << endl;
		cout << "4.insert before an element" << endl;
		cout << "5.delete at begining" << endl;
		cout << "6.delete at end" << endl;
		cout << "7.delete a specific element" << endl;
		cout << "8.forward traversal" << endl;
		cout << "9.backward traversal" << endl;
		cout << "10.reverse the list" << endl;
		cout << "11. self adjusting list" << endl;
		cout << "12.exit" << endl;
		cin >> op;
		switch (op) {
		case 1:
			cout << "enter the element to be inserted:";
			cin >> x;
			ll.insertFirst(x);
			break;
		case 2:
			cout << "enter the element to be inserted:";
			cin >> x;
			ll.insertLast(x);
			break;
		case 3:
			cout << "enter the element to be inserted and afer which element";
			cin >> x >> s;
			ll.insertAfter(s, x);
			break;
		case 4:
			cout << "enter element to be inserted and before which element ";
			cin >> x >> s;
			ll.insertAfter(s, x);
			break;
		case 5:
			x = ll.deleteFirst();
			cout << "deleted element is:" << x;
			break;
		case 6:
			x = ll.deleteLast();
			cout << "deleted element is:" << x;
			break;
		case 7:
			cout << "enter the lement to be deleted:";
			cin >> x;
			ll.deleteSpec(x);
			break;
		case 8:
			ll.traverseForward();
			break;
		case 9:
			ll.traverseBackward();
			break;
		case 10:
			ll.reverse();
			break;
		case 11:
			cout << "enter the element to be adjusted";
			cin >> x;
			ll.selfAdjusting(x);
			break;
		case 12:
			exit(0);
		default:
			cout << "choose valid option" << endl;
		}
	}
}

