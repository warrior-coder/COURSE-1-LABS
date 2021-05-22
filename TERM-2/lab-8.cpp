#include <iostream>
using namespace std;

struct Node
{
	int inf;
	Node* prev;
	Node* next;
};
struct List
{
	Node* begin = nullptr;
	Node* end = nullptr;

	void push_back(int inf)
	{
		Node* spt = new Node;
		spt->inf = inf;
		spt->next = nullptr;
		if (begin)
		{
			spt->prev = end;
			end->next = spt;
			end = spt;
		}
		else
		{
			spt->prev = nullptr;
			begin = end = spt;
		}
	}
	void show()
	{
		Node* spt = begin;
		while (spt)
		{
			cout << spt->inf << ' ';
			spt = spt->next;
		}
		cout << endl;
	}
	void clear()
	{
		Node* spt;
		while (begin)
		{
			spt = begin;
			begin = begin->next;
			delete spt;
		}
		begin = end = nullptr;
	}
};

int main()
{
	int n;
	cout << "Enter list size: "; cin >> n;

	if (n > 0)
	{
		// create
		List l1;
		for (int i = 0; i < n; i++)
			l1.push_back(rand() % 101 - 50);
		cout << "List: ";
		l1.show();

		// find
		Node* sp1, *sp2;
		int i, i1, i2;

		sp1 = l1.begin;
		i1 = i = 0;
		for (Node* spt = l1.begin->next; spt; spt = spt->next, i++)
			if (spt->inf < sp1->inf) { sp1 = spt; i1 = i; }
		cout << "Min: " << sp1->inf << endl;

		sp2 = l1.begin;
		i2 = i = 0;
		for (Node* spt = l1.begin->next; spt; spt = spt->next, i++)
			if (spt->inf > sp2->inf) { sp2 = spt; i2 = i; }
		cout << "Max: " << sp2->inf << endl;

		// create new list
		List l2;
		Node* begin = (i1 < i2) ? sp1 : sp2;
		Node* end = (i1 < i2) ? sp2 : sp1;
		
		for (Node* spt = begin->next; spt && spt != end; spt = spt->next)
			l2.push_back(spt->inf);
		cout << "New List: "; 
		l2.show();

		// clear
		l1.clear();
		l2.clear();
	}
	else cout << "List is empty";

	return 0;
}