#include <iostream>

using namespace std;
class list
{
	class element
	{
		int data;
		element* pnext;
		element* pprev;
	public:
		element(int data = 0) : data(data), pnext(nullptr), pprev(nullptr) {}
		~element() {}
		friend class list;
		class iterator
		{
			element* i;
		public:
			iterator(element* i = nullptr) : i(i) {};
			~iterator() {}
			iterator operator++() { i = i->pnext; }
			iterator operator--() { i = i->pprev; }
			bool operator ==(iterator* value)
			{
				if (this == value) return true;
				else return false;
			}
			iterator operator *() { return *this; }
		};
	};
	element* head;
	element* tail;
public:
	list() : head(nullptr), tail(nullptr) { };
	~list() {};
	void add_start(int data)
	{
		element* a = new element(data);
		a->pnext = head;
		head = a;
	}	// DONE
	void add_end(int data)
	{
		if (head == nullptr) return add_start(data);
		element* a = new element(data);
		element* i = new element;
		i = head;
		while (i->pnext) i = i->pnext;
		i->pnext = a;
		a->pprev = i;
		tail = a;
	}
	void insert(int data, int index)
	{
		if (head == nullptr) return add_start(data);
		if (index == 0) return add_start(data);
		element* a = new element(data);
		iterator* i = new iterator;
		i = head;
		for (int j = 0; j < index - 1; j++) i = i->pnext;
		a->pnext = i->pnext;
		i->pnext = a;
		a->pprev = i;
	}//	DONE
	void erase(int index)
	{
		element* i = new element;
		i = head;
		for (int j = 0; j < index - 1; j++) i = i->pnext;
		i->pnext = i->pnext->pnext;
	}
	void print()const
	{
		element* i = new element;
		i = head;
		for (i; i; i = i->pnext) cout << i->data << " ";
		cout << endl;
	}
	void reverse_print()const
	{
		element* i = new element;
		i = tail;
		for (i; i; i = i->pprev)
			cout << i->data << " ";
	}
};
void main()
{
	srand(time(NULL));
	list list1;
	for (int i = 0; i < 5; i++) list1.add_end(rand() % 10);
	list1.print();
	list1.reverse_print();
}// Код будет работать без итератора, с итератором выдаёт ошибку
//"отсуствует список аргументов для шаблон класса iterator"