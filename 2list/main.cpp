#include <iostream>
using namespace std;

struct element
{
	int data;
	element* pnext;
	element* pprev;
	element(int data = 0) : data(data), pnext(nullptr), pprev(nullptr)
	{
		cout << "Econstructor: " << this << endl;
	}
	~element()
	{
		cout << "Edestructor: " << this << endl;
	}
};
class list
{
	element* head;
public:
	list() : head(nullptr) { cout << "Lconstructor: " << this << endl; };

	void add_start(int data)
	{
		element* a = new element(data);
		a->pnext = head;
		head = a;
	}
	void add_end(int data)
	{
		if (head == nullptr) return add_start(data);
		element* a = new element(data);
		element* i = new element;
		i = head;
		while (i->pnext) i = i->pnext;
		i->pnext = a;
		a->pprev = i;
	}
	void insert(int data, int index)
	{
		if (head == nullptr) return add_start(data);
		if (index == 0) return add_start(data);
		element* a = new element(data);
		element* i = new element;
		i = head;
		for (int j = 0; j < index-1; j++)
		i = i->pnext;
		i->pnext = a;
		i->pnext->pnext = a->pnext;
		a->pprev = i;
	}//На этом остановился
	void print()
	{
		element* i = new element;
		i = head;
		for (i; i; i = i->pnext) 
		cout << i->data << " ";
		cout << endl;
	}
};
void main()
{
	list list;
	list.add_start(1);
	list.add_end(5);
	list.insert (3,1);
	list.print();
}