#include<iostream>>
using namespace std;
int max(int x, int y) {
	if (x > y)
		return x;
	else
		return y;
}
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
int findMax(struct Node* curr) {
	if (curr != NULL) {
		while (curr->right != NULL)
			curr = curr->right;
		return curr->data;
	}
	else return -1;
}
int height(struct Node *curr) {
	if (curr == NULL)
		return -1;
	else
		return (max(height(curr->left), height(curr->right)) + 1);
}

int bf(struct Node *curr) {
	return (height(curr->left) - height(curr->right));
}
struct Node *lRotation(struct Node * curr) {
	struct Node *temp;
	temp = curr->right;
	curr->right = temp->left;
	temp->left = curr;
	return temp;
}
struct Node* rRotation(struct Node *curr) {
	struct Node *temp;
	temp = curr->left;
	curr->left = temp->right;
	temp->right = curr;
	return temp;
}
struct Node * lrRotation(struct Node *curr) {
	cout << "hello3";
	curr->left = lRotation(curr->left);
	return rRotation(curr);
}
struct Node * rlRotation(struct Node *curr) {
	curr->right = rRotation(curr->right);
	return lRotation(curr);
}
struct Node * balance(struct Node *curr) {
	//cout << "hello";
	if (bf(curr) > 1) {
		//cout << "hello2";
		if (bf(curr->left) == 1)
			curr = rRotation(curr);
		else
			curr = lrRotation(curr);
	}
	if (bf(curr) < -1) {
		if (bf(curr->right) == 1)
			curr = rlRotation(curr);
		else
			curr = rRotation(curr);
	}
	return curr;
}
/*struct Node* deleteElex(int e, struct Node* curr) {
	if (curr != NULL) {
		if (e > curr->data)
			curr->right = deleteElex(e, curr->right);
		else if (e < curr->data)
			curr->left = deleteElex(e, curr->left);
		else {
			if (curr->left != NULL && curr->right != NULL)
			{
				curr->data = findMax(curr->left);
				curr->left = deleteElex(curr->data, curr->left);
			}
			else {
				struct Node* temp;
				temp = curr;
				if (curr->left == NULL)
					curr = curr->right;
				else
					curr = curr->left;
				delete temp;
			}

		}
		return curr;

	}
	else {
		cout << "No elements in tree" << endl;
	}
}*/
struct Node* insertx(int e, struct Node* curr) {
	if (curr == NULL) {
		struct Node *temp;
		temp = new Node;
		temp->data = e;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else {
		if (e < curr->data)
		{
			curr->left = insertx(e, curr->left);
			curr = balance(curr);
		}
		else {
			curr->right = insertx(e, curr->right);
			curr = balance(curr);
		}
		return curr;
	}
}
void printI(struct Node *curr) {
	//cout << "hello2";
	if (curr != NULL) {
		printI(curr->left);
		cout << curr->data << " ";
		printI(curr->right);
	}
}

class AVL {

public:
	struct Node *root;
	AVL() {
		root = NULL;
	}
	void insert(int e) {
		root = insertx(e, root);
	}
	/*void deleteEle(int e)
	{
		root = deleteElex(e, root);
	}*/
	void inOrder();
	
	friend int findMax(struct Node *);
	friend int findMin(struct Node *);
	friend int height(struct Node *);
	friend int bf(struct Node *);
	friend struct Node * balance(struct Node *);
	friend struct Node * lRotation(struct Node *);
	friend struct Node * rRotation(struct Node *);
	friend struct Node * lrRotation(struct Node *);
	friend struct Node * rlRotation(struct Node *);
	
	~AVL();
};

int findMin(struct Node* curr) {
	if (curr != NULL)
	{
		while (curr->left != NULL)
			curr = curr->left;
		return curr->data;
	}
	else
		return -1;
}


void AVL::inOrder() {
	
	if (root != NULL)
		printI(root);
	
}
void deleteNode(struct Node *curr) {
	if (curr != NULL) {
		deleteNode(curr->left);
		deleteNode(curr->right);
		delete curr;
	}
}


AVL::~AVL() {
	cout << "memory deleted";
	if (root != NULL)
		deleteNode(root);
}

int main() {
	cout << "BINARY SEARCH TREE!!" << endl;
	int x, op;
	AVL AVL;
	while (1) {
		cout << "choose a choice:" << endl;
		cout << "1.insert\t2.delete\t3.inorder Traversal\t4.find height\t5.find Minimum\t 6.find maximum\t7.exit";
		cout << endl;
		cin >> op;
		switch (op) {
		case 1:
			cout << "enter the element to be inserted:";
			cin >> x;
			AVL.insert(x);
			break;
		case 2:
			cout << "enter element to be deleted:";
			cin >> x;
			//AVL.deleteEle(x);
			break;
		case 3:
			AVL.inOrder();
			break;
		case 4:
			x = height(AVL.root);
			cout << "height is:" << x;
			break;
		case 5:
			x = findMin(AVL.root);
			cout << "minimum elemnet in tree:" << x;
			break;
		case 6:
			x = findMax(AVL.root);
			cout << "maximum element in tree:" << x;
			break;
		case 7:
			AVL.~AVL();
			exit(0);
		default:
			cout << "choose valid option";
			break;
		}


	}



}
