#include <iostream>
using namespace std;
class element
{
	static int count; //Статическая переменная является общей для всех объектов класса. Её можно проинициализировать только за классом
	int data; //element value
	element* pnext; // next element adress
public:
	element(int data, element* pnext = nullptr) :data(data), pnext(pnext) 
	{ cout << "Econstruct: \t" << this << endl; }
	~element() 
	{ 
		//count--;
		cout << "Edestrusct: \t" << this << endl; 
	}
	friend class fwdlist;
};
//int element::count = 0;
class fwdlist
{
	size_t size;
	element* head; // голова списка указывает на начальный элемент списка (нулевой)
public:
	class iterator
	{
		element* i;
	public:
		iterator(element* i = nullptr) : i(i) { cout << "ITconstructor: \t" << this << endl; }
		~iterator() { cout << "ITdestructor " << this << endl; }
		iterator& operator++() { i = i->pnext; return *this; } // Это префиксный
		iterator operator++(int) 
		{ 
			iterator old = *this; 
			i = i->pnext;
			return old;
		} // Это постфиксный
		bool operator = (const iterator& other) const { return this->i == other.i; }
		bool operator!=(const iterator& other)const { return this->i != other.i; }
		int& operator *() { return i->data; }
	};
	iterator begin() { return this->head; }
	iterator end() { return nullptr; }
	//default constructor создаёт пустой список
	fwdlist() 
	{
		head = nullptr; cout << "Lconstructor: \t" << this << endl;
	} 
	//Если голова указывает на 0, то список пуст, т.е не содержит элементов
	//И голове больше не не что указывать	
	fwdlist(const initializer_list<int>& il) :fwdlist()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			this->push_back(*it);
		}
	}
	fwdlist(const fwdlist& other) :fwdlist()
	{
		for (element* temp = other.head; temp; temp = temp->pnext) push_back(temp->data);
	}
	~fwdlist()
	{
		while (head) pop_front();
		cout << "Ldestructor: \t" << this << endl; 
	}
	fwdlist& operator=(const fwdlist& other)
	{
		while (head) pop_front();
		for (element* temp = other.head; temp; temp = temp->pnext)
			push_back(temp->data);
		return *this;
	}
	//adding elements
	void push_front(int data)
	{
		//1) Создаём элемент
		element* New = new element(data);
		//2) Прикрепляем элемент к списку:
		New->pnext = head;
		//3) Говорим что новый элемент теперь начальный элемент списка
		head = New;
		size++;// count++;
	}
	void push_back(int data)
	{
		if (head == nullptr) { return push_front(data); }
		element* temp = head; //итератор
		while (temp->pnext) { temp = temp->pnext; }
		//element* New = new element(data);
		temp->pnext = new element(data);
		size++; //count++;
	}
	void insert(int index, int data)
	{
		if (index == 0) return push_front(data);
		if (index >= size) return push_back(data);
		element* temp = head;
		for (int i = 0; i < index-1; i++) temp = temp->pnext;
		element* New = new element(data);
		New->pnext = temp->pnext;
		temp->pnext = New;
		size++; //count++;
	}
	//removing elements
	void pop_front()
	{
		//1 Запоминаем адрес удаляемого элемента
		element* del = head;
		//2 Исключаем из списка
		head = head->pnext;
		//3 Удаляем из памяти
		delete del;
		size--; //count--;
	}
	void pop_back()
	{
		element* temp = head; //создаём элемент
		while (temp->pnext->pnext)//доходим до конца списка
		{
			temp = temp->pnext;
		}
		delete temp->pnext; //удаляем элемент из списка
		temp->pnext = nullptr; //зануляем
		size--;// count--;
	}
	void erase(int index)
	{
		element* temp = head;
		for (int i = 0; i < index; i++) temp = temp->pnext;
		temp = nullptr;
		delete temp;
		size--; //count--;
	}
	//methods
	void print()const
	{
		element* temp = head; //temp - итератор
		//Итератор - это указатель, при помощи которого можно получить доступ к элементам стуктуры данных
		/*while (temp != nullptr)
		{
			cout << temp << "\t" << temp->data << "\t" << temp->pnext << endl;
			temp = temp->pnext;//Переход на следующий элемент
		}
		cout << "Total elements: " << element::count << endl;*/
		for (element* temp = head; temp; temp = temp->pnext)
		{
			cout << "\nTemp adress: " << temp << "\tTemp value: " << temp->data << "\tNext adress: " << temp->pnext << endl;
		}
			cout << "\n------------List elements amount: " << size << "------------" << endl;
			cout << "------------Total elements amount: " << element::count << "------------" << endl << endl;
	}
	void copy(int left, int right)const //left - индекс числа, которое копируем right - индекс куда копируем
	{

	}
};
#define BASE_CHECK
//#define COPY
#define delimeter cout << "\n-------------------------------------------\n"
void main()
{
	system("color 0A");
	srand(time(NULL));
#ifdef BASE_CHECK
	fwdlist list;
	int n; cout << "Value size: "; cin >> n;
	for (int i = 0; i < n; i++) { list.push_front(rand() % 100); }
	//for (int i = 0; i < n; i++) { list.push_back(rand() % 100); }
#endif
#ifdef COPY
	fwdlist list = { 3,5,8,13,21 };
	list.print();
	fwdlist list1;
	list1 = list;
	list1.print();

#endif
	delimeter;
	cout << "Range-based for:\n" << endl;
	for (int i : list)
	{
		cout << i << "\t";
	}
	cout << endl;
	delimeter;
	cout << "Ordinary for:\n" << endl;
	for (fwdlist::iterator it = list.begin(); it != list.end(); it++) { cout << *it << "\t"; }
}