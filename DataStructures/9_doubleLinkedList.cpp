#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
};
class doubleLL {
	struct node *start;
public:
	doubleLL() {
		start = NULL;
	}
	void insertFirst(int x) {
		struct Node *temp;
		temp = new Node;
		temp->data = x;
		temp->prev = NULL;
		temp->next = start;
		if (start != NULL) {
			start->prev = temp;
		}
		start = temp;
	}
	void insertLast(int x) {
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
			temp->prev = temp;
		}
		else {
			temp->prev = NULL;
			start = temp;
		}
	}
	void insertAfter(int s, int x) {
		if (start != NULL) {
			struct Node *curr;
			curr = start;
			while (curr != NULL &&curr->data != s)
				curr = curr->next;
			if (curr != NULL) {
				struct Node *temp;
				temp = new Node;
				temp->data = x;
				temp->next = curr->next;
				temp->prev = curr;
				if (curr->next != NULL)
					curr->next->prev = temp;
				curr->next = temp;
			}
			else
				cout << "element not found" << endl;
				
		}
		else {
			cout << "list is empty";
		}


		}
	void insertBefore(int s, int x) {
		if (start != NULL) {
			struct Node *curr;
			curr = start;
			while (curr != NULL && curr->data != s)
				curr = curr->next;
			if (curr != NULL) {
				struct Node *temp;
				temp = new Node;
				temp->data = x;
				temp->prev = curr->prev;
				temp->next = curr;
				curr->prev = temp;
				if (curr->prev != NULL)
					curr->prev->next = temp;
				else
					start = temp;
			}
			else {
				cout << "element not found" << endl;
			}

		}
		else
			cout << "list is empty" << endl;
	}

	int deleteFirst() {
		int x = -999;
		if (start != NULL) {
			struct node *temp;
			temp = start;
			if (temp->next != NULL)
				temp->next->prev = NULL;
			start = temp->next;
			x = temp->data;
			delete temp;
		}
		else
			cout << "no element to delete";
		return x;
	}
	int deleteLast(){
		int x = -999;
		if (start != NULL) {
			struct Node *curr;
			curr = start;
			while (curr->next != NULL)
				curr = curr->next;
			x = curr->data;
			if (curr->prev != NULL)
			{
				curr->prev->next = NULL;
			delete temp;
			}
			else {
				delete start;
				start = NULL;
			}


		}cout << "no elements to delete" << endl;
	
		return x;
	}
	void deleteSpec(int x) {
		int x = -999;
		if (start != NULL) {
			curr = start;
			while (curr != NULL && curr->data != x)
				curr = curr->next;
			if (curr != NULL) {
				if (curr->prev != NULL) {
					curr->prev->next = curr->next;
				}
				else
					start = curr->next;
				if (curr->next != NULL) {
					curr->next->prev = curr->prev;
				}
				x = curr->data;
				delete curr;
			}
			else
				cout << "element Not found";
		}
		else
			cout << "list is empty" << endl;

		return x;
	}
	void traverseForward() {
		struct Node *curr;
		curr = start;
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	void traverseBackward() {
		
		if (start != NULL) {
			struct Node *curr;
			curr = start;
			while (curr->next != NULL) {
				curr = curr->next;
			}
			while (curr != NULL) {
				cout << curr->data << " ;"
					curr = curr->prev;
			}
		}
		else
			cout << "no elements in list" << endl;
	}

};
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
		cout << "11.exit" << endl;
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
			exit(0);
		default:
			cout << "choose valid option" << endl;
		}
	}
}
