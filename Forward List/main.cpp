#include <iostream>
using namespace std;
class element
{
	static int count; //����������� ���������� �������� ����� ��� ���� �������� ������. Ÿ ����� ������������������� ������ �� �������
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
int element::count = 0;
class fwdlist
{
	size_t size;
	element* head; // ������ ������ ��������� �� ��������� ������� ������ (�������)
public:
	//default constructor ������ ������ ������
	fwdlist() 
	{
		head = nullptr; cout << "Lconstructor: \t" << this << endl;
	} 
	//���� ������ ��������� �� 0, �� ������ ����, �.� �� �������� ���������
	//� ������ ������ �� �� ��� ���������	
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
		//1) ������ �������
		element* New = new element(data);
		//2) ����������� ������� � ������:
		New->pnext = head;
		//3) ������� ��� ����� ������� ������ ��������� ������� ������
		head = New;
		size++;
	}
	void push_back(int data)
	{
		if (head == nullptr) { return push_front(data); }
		element* temp = head; //��������
		while (temp->pnext) { temp = temp->pnext; }
		//element* New = new element(data);
		temp->pnext = new element(data);
		size++;
	}
	void insert(int index, int data)
	{
		if (index == 0) return push_front(data);
		if (index >= size) return push_back(data);
		element* temp = head;
		for (int i = 0; i < index-1; i++)temp = temp->pnext;
		element* New = new element(data);
		New->pnext = temp->pnext;
		temp->pnext = New;
		size++;
	}
	//removing elements
	void pop_front()
	{
		//1 ���������� ����� ���������� ��������
		element* del = head;
		//2 ��������� �� ������
		head = head->pnext;
		//3 ������� �� ������
		delete del;
		size--;
	}
	void pop_back()
	{
		element* temp = head; //������ �������
		while (temp->pnext->pnext)//������� �� ����� ������
		{
			temp = temp->pnext;
		}
		delete temp->pnext; //������� ������� �� ������
		temp->pnext = nullptr; //��������
		size--;
	}
	void erase(int index)
	{
		element* temp = head;
		for (int i = 0; i < index; i++) temp = temp->pnext;
		temp = nullptr;
		delete temp;
		size--;
	}
	//methods
	void print()const
	{
		element* temp = head; //temp - ��������
		//�������� - ��� ���������, ��� ������ �������� ����� �������� ������ � ��������� �������� ������
		/*while (temp != nullptr)
		{
			cout << temp << "\t" << temp->data << "\t" << temp->pnext << endl;
			temp = temp->pnext;//������� �� ��������� �������
		}
		cout << "Total elements: " << element::count << endl;*/
		for (element* temp = head; temp; temp = temp->pnext)
		{
			cout << "\nTemp adress: " << temp << "\tTemp value: " << temp->data << "\tNext adress: " << temp->pnext << endl;
			cout << "\n------------List elements amount: " << size << "------------" << endl;
			cout << "------------Total elements amount: " << element::count << "------------" << endl << endl;
		}
	}
	void copy(int left, int right)const //left - ������ �����, ������� �������� right - ������ ���� ��������
	{

	}
};
#define BASE_CHECK
//#define COPY
void main()
{
	system("color 0A");
	srand(time(NULL));
#ifdef BASE_CHECK
	fwdlist list;
	int n; cout << "Value size: "; cin >> n;
	//for (int i = 0; i < n; i++) { list.push_front(rand() % 100); }
	for (int i = 0; i < n; i++) { list.push_back(rand() % 100); }
	list.print();
	
#endif
#ifdef COPY
	fwdlist list = { 3,5,8,13,21 };
	list.print();
	fwdlist list1;
	list1 = list;
	list1.print();
#endif
}