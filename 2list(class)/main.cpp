#include <iostream>
#include <ctime>
using namespace std;
//#define DEBUG
class list
{
	class element
	{
		int data;
		element* pnext;
		element* pprev;
	public:
		element(int data = 0, element* pnext = nullptr, element* pprev = nullptr)
			:data(data), pnext(pnext), pprev(pprev) {
			cout << "EC " << this << endl;
		}
		~element() 

		{ 
#ifdef DEBUG	
			cout << "ED " << this << endl; 
#endif
		}

		friend class list;
	}*head, *tail; // == element* head; element* tail;
	size_t size;
public:
	class iterator
	{
		element* i;
	public:
		iterator(element* i = nullptr) :i(i) 
		{ 
#ifdef DEBUG
			cout << "IC " << this << endl;
#endif
		}
		~iterator() 
		{ 
#ifdef DEBUG
			cout << "ID " << this << endl;
#endif
		}
		
		iterator& operator++()
		{
			i = i->pnext;
			return *this;
		}
		iterator operator ++ (int)
		{
			iterator old = *this;
			i = i->pnext;
			return old;
		}
		bool operator==(const iterator& other)const
		{
			return this->i == other.i;
		}
		bool operator!=(const iterator& other)const
		{
			return this->i != other.i;
		}

		const int& operator *()const
		{
			return this->i->data;
		}
		int& operator*()
		{
			return this->i->data;
		}
	};
	iterator begin() { return head; }
	iterator end() { return nullptr; }
	const size_t get_size() const
	{
		return this->size;
	}
	list()
	{
		//конструктор по умолчанию создаёт пустой список
		head = tail = nullptr;
		size = 0;
		cout << "LC " << this << endl; //LC == list constructor
	}
	list(const initializer_list<int>& il) : list()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			add_end(*it);
		}
		cout << "LSINGLE ARG " << this << endl;
	}
	list(const list& other) :list()
	{
		for (element* temp = other.head; temp; temp = temp->pnext) 
		add_end(temp->data);
		cout << "LCOPY " << this << endl;
	}
	~list() 
	{
		//while (head) delete_start();	
		while (tail) delete_end();
		cout << "LD " << this << endl; 
	}
	//operators
	list& operator =(const list& other)
	{
		if (this == &other) return *this;
		while (head)delete_start();
		for (element* temp = other.head; temp; temp = temp->pnext)
			add_end(temp->data);
		cout << "LCOPY_ASSIG " << this << endl;
		return *this;
	}
	//Adding elements
	void add_start(int data) // == push_front
	{
		if (head == nullptr && tail == nullptr) head = tail = new element(data);
		else
		{
			/*element* a = new element(data);
			a->pnext = head;
			head->pprev = a;
			head = a;*/
			head = head->pprev = new element(data, head);
		}
		size++;
	}
	void add_end(int data)
	{
		if (!head && !tail) return add_start(data);
			/*element* a = new element(data);
			a->pprev = tail;
			tail->pnext = a;
			tail = a;*/
			size++;
		tail = tail->pnext = new element(data,nullptr,tail);
	}
	//removing elements
	void delete_start()
	{
		//проверяем, не является ли удаляемый элемент списка последним:
		if (head = tail)
		{
			delete head;
			head = tail = nullptr;
			return;
		}
		head = head->pnext; //исключаем элемент из списка
		delete head->pprev;//удаляем элемент из памяти
		head->pprev = nullptr;//забываем об элементе
		size--;
	}
	void delete_end()
	{
		if (head == tail) return delete_start();
		tail = tail->pprev;
		delete tail->pnext;
		tail->pnext = nullptr;
		size--;
	}
	//methods
	void print()const
	{
		cout << "List start adress: " << head << endl;
		for (element* i = head; i; i = i->pnext)
		//for (element* i = head; i; i = i++)
		{
			cout << "Current: " << i << "\t" << "Previous: "<< i->pprev << "\t" << "Data: " << i->data << "\t" << "Next: " << i->pnext << endl;
		}
		cout << "List size: " << this->size << endl;
	}
	void reverse_print()const
	{
		cout << "List end adress: " << tail << endl;
		for (element* i = tail; i; i = i->pprev)
		{
			cout << "Current: " << i << "\t" << "Previous: " << i->pprev << "\t" << "Data: " << i->data << "\t" << "Next: " << i->pnext << endl;
		}
		cout << "List size: " << this->size << endl;
	}
	/*void insert(int data, int index)
	{
		element* a = new element(data);
		element* i = new element;
		i = head;
		for (int j = 0; j < index-1; j++) i = i->pnext;
		i->pnext = a->pnext;
		i->pnext = a;
	}*/
};
//#define BASE_CHECK
void main()
{
	srand(time(NULL));
#ifdef BASE_CHECK
	int n;
	cout << "???" << endl; cin >> n;
	list list;
	for (int i = 0; i < n; i++) list.add_end(rand() % 100);
	list.print();
	list.delete_end();
	list.print();
	list.reverse_print();
#endif
	list list1 = { 3,5,8,13,21 };
	list1.print();
	//list list2 = list1; //copy constructor
	list list2;// default constructor
	list2 = list1;//copy assignment
	for(list::iterator it = list2.begin(); it != list2.end(); ++it)
	{
		cout << *it << endl;	
	}
}