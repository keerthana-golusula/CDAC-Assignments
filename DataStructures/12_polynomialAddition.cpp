#include<iostream>
using namespace std;
struct node
{
	int e, c;
	node *next;
};
class Polyadd
{

public:
	node *head1, *head2, *head3, *tail1, *tail2;
	Polyadd()
	{
		head1 = NULL;
		head2 = NULL;
		head3 = NULL;
		tail1 = NULL;
		tail2 = NULL;
	}
	void read();
	void add();
	void dispres(node *);
};
void Polyadd::read()
{
	char ch = 'y';
	int coeff, exp;
	node *temp;
	cout << "\nenter first polynomial.press y to continue and n to end";
	cin >> ch;
	while (ch != 'n')
	{
		temp = new node;
		cin >> temp->c >> temp->e;
		if (head1 == NULL)
			head1 = temp;
		else
			tail1->next = temp;
		temp->next = NULL;
		tail1 = temp;
		cin >> ch;
	}
	ch = 'y';
	cout << "\nenter second polynomial.press y to continue and n to end";
	cin >> ch;
	while (ch != 'n')
	{
		temp = new node;
		cin >> temp->c >> temp->e;
		if (head2 == NULL)
			head2 = temp;
		else
			tail2->next = temp;
		temp->next = NULL;
		tail2 = temp;
		cin >> ch;
	}
	cout << "polynomials entered successfully\n";
}

void Polyadd::add()
{
	node *temp1 = head1;
	node *temp2 = head2;
	node *temp3, *tail3 = NULL;
	while (temp1 != NULL && temp2 != NULL)
	{
		temp3 = new node;
		temp3->next = NULL;
		if (temp1->e == temp2->e)
		{
			temp3->e = temp1->e;
			temp3->c = temp1->c + temp2->c;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if (temp1->e<temp2->e)
		{
			temp3->e = temp2->e;
			temp3->c = temp2->c;
			temp2 = temp2->next;
		}
		else if (temp1->e>temp2->e)
		{
			temp3->e = temp1->e;
			temp3->c = temp1->c;
			temp1 = temp1->next;
		}
		if (head3 == NULL)
			head3 = temp3;
		else
			tail3->next = temp3;
		tail3 = temp3;
	}
	while (temp1 != NULL)
	{
		tail3->next = temp1;
		tail3 = temp1;
		tail3->next = NULL;
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		tail3->next = temp2;
		tail3 = temp2;
		tail3->next = NULL;
		temp2 = temp2->next;
	}
	tail3->next = NULL;
}
void Polyadd::dispres(node *temp)
{
	while (temp != NULL)
	{
		cout << "(" << temp->c << "," << temp->e << ")   ";
		temp = temp->next;
	}
} 
int main()
{
	Polyadd p;
	p.read();
	cout << "\npolynomial 1:   ";
	p.dispres(p.head1);
	cout << "\npolynomial 2:   ";
	p.dispres(p.head2);
	p.add();
	cout << "\nSum of two polynomials is:";
	p.dispres(p.head3);
}

