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
struct Node* deleteElex(int e, struct Node* curr) {
	if (curr != NULL) {
		if (e > curr->data)
			curr->right = deleteElex(e, curr->right);
		else if (e < curr->data)
			curr ->left = deleteElex(e, curr->left);
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
}
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
			curr->left = insertx(e, curr->left);
		else
			curr->right = insertx(e, curr->right);
		return curr;
	}
}
void printI(struct Node *curr) {
	//cout << "hello2";
	if (curr != NULL) {
		printI(curr->left);
		cout << curr->data<<" ";
		printI(curr->right);
	}
}
void printPre(struct Node *curr) {
	if (curr != NULL) {
		cout << curr->data<<" ";
		printPre(curr->left);
		printPre(curr->right);
	}
}
void printPost(struct Node *curr) {
	if (curr != NULL) {
		printPost(curr->left);
		printPost(curr->right);
		cout << curr->data<<" ";
	}
}

class BST{
	
public:
	struct Node *root;
	BST() {
		root = NULL;
	}
	void insert(int e) {
	root=insertx(e, root);
	}
	void deleteEle(int e)
	{
		root=deleteElex(e, root);
	}
	void inOrder();
	void preOrder();
	void postOrder();
	 friend int findMax(struct Node *);
	friend int findMin(struct Node *);
	friend int height(struct Node *);
	friend int NLN(struct Node *);
	friend int NNLN(struct Node *);
	~BST();
};
int NLN(struct Node* curr) {
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 1;
	return (NLN(curr->left) + NLN(curr->right));
}

int NNLN(struct Node *curr) {
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 0;
	return (NNLN(curr->left) + NNLN(curr->right) + 1);

}
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

int height(struct Node *curr) {
	if (curr == NULL)
		return -1;
	else
		return (max(height(curr->left), height(curr->right)) + 1);
}
void BST::inOrder() {
	//cout << "Hello";
	if (root != NULL)
		printI(root);
	//cout << "hello";
}
void BST::preOrder() {
	if (root != NULL) {
		printPre(root);
	}

}
void BST::postOrder() {
	if (root != NULL)
		printPost(root);
}
void deleteNode(struct Node *curr) {
	if (curr != NULL) {
		deleteNode(curr->left);
		deleteNode(curr->right);
		delete curr;
	}
}


BST::~BST() {
	if (root != NULL)
		deleteNode(root);
}

int main() {
	cout << "BINARY SEARCH TREE!!" << endl;
	int x, op;
	BST bst;
	while (1) {
		cout << "choose a choice:" << endl;
		cout << "1.insert\t2.delete\t3.inorder Traversal\t4.preorder Traversal\t5.postorder Traversal\t6.find height\t7.find Minimum\t 8.find maximum\t9. find no. of leaf Nodes\t10.find no. of non leaf nodes\t11.exit";
		cout << endl;
		cin >> op;
		switch (op) {
		case 1: 
			cout << "enter the element to be inserted:";
			cin >> x;
			bst.insert(x);
			break;
		case 2:
			cout << "enter element to be deleted:";
			cin >> x;
			bst.deleteEle(x);
			break;
		case 3:
			bst.inOrder();
			break;
		case 4:
			bst.preOrder();
			break;
		case 5:
			bst.postOrder();
			break;
		case 6:
			x=height(bst.root);
			cout << "height is:" << x;
			break;
		case 7:
			x = findMin(bst.root);
			cout << "minimum elemnet in tree:" << x;
			break;
		case 8:
			x = findMax(bst.root);
			cout << "maximum element in tree:" << x;
			break;
		case 9:
			x = NLN(bst.root);
			cout << "No. of leaf Nodes:" << x<<endl;
			break;
		case 10:
			x = NNLN(bst.root);
			cout << "No. of non Leaf Nodes:" << x << endl;
			break;
		case 11:
			exit(0);
		default:
			cout << "choose valid option";
			break;
		}


	}



}
