#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};

class list {
	struct Node *start;
public:
	list() {
		start = NULL;
	}
	void insert(int x) {
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
	void display() {
		struct Node *curr;
		curr = start;
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}

	}
	friend list merging(list, list);

};

list merging(list l1, list l2) {
	list l3;
	while (l1!= NULL &&l2 != NULL);
	{
		struct Node* temp;
		temp = new Node;
		if (l1->data > l2->data) {
			
			temp->data = l2->data;
			l2 = l2->next;
		}
		else {
			temp->data = l1->data;
			l1 = l1->data;
		}
		if (l3 == NULL)
			l3 = temp;
		else {
			l3->next = temp;
		}
	}
	while (l1 != NULL)
	{

	}



}