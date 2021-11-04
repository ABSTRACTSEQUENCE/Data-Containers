#include <iostream>
using namespace std;
class tree
{
	class element
	{
		int data;
		element* pl; element* pr; //pl - left pr - right
	public:
		element(int data = 0, element* pl = nullptr, element* pr = nullptr) :
			data(data), pl(pl), pr(pr) {
			cout << "E\t" << this << endl;
		};
		~element() { cout << "~E\t" << this << endl; }
		friend class tree;
	}*root;
public:
	element* get_root()const { return root; }
	tree() :root(nullptr)
	{
		//this->root = nullptr;
		cout << "T\t" << this << endl;
	}
	tree(const std::initializer_list<int>& il) : tree()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			add(*it, this->root);
		}

	}
	~tree()
	{
		clear(root);
		cout << "~T\t" << this << endl;
	}
	void add(int data) { add(data, this->root); }
	void erase(int data) { erase(data, this->root); }
	void print()const { print(this->root); cout << endl; }
	int min()const { return min(this->root); }
	int max()const { return max(this->root); }
	int count()const { return count(this->root); }
	int sum()const { return sum(this->root); }
	double avg()const { return (double)sum(this->root) / count(this->root); }
private:
	void add(int data, element* root)
	{
		if (this->root == nullptr) { this->root = new element(data); return; }
		if (root == nullptr) return;
		if (data < root->data)
		{
			if (root->pl == nullptr) { root->pl = new element(data); }
			else { add(data, root->pl); }
		}
		else if (data > root->data)
		{
			if (root->pr)add(data, root->pr);
			else root->pr = new element(data);
		}
	}
	void erase(int data, element*& root)
	{
		if (root == nullptr) return;
		erase(data, root->pl); erase(data, root->pr);
		if (data == root->data)
		{
			if (root->pl == nullptr && root->pr == nullptr)
			{
				delete root;
				root = nullptr;
			}
			else
			{
				if (count(root->pl) > count(root->pr))
				{
					root->data = max(root->pl);
					erase(max(root->pl), root->pl);
				}
				else
				{
					root->data = min(root->pr);
					erase(min(root->pr), root->pr);
				}
			}
		}
		
	}
		void clear(element * root)
		{
			if (root == nullptr) return;
			clear(root->pl); clear(root->pr);
			delete root;
		}
		void print(element * root)const
		{
			if (root == nullptr) return;
			cout << root->data << "\t";
			print(root->pl);
			print(root->pr);
		}
		int min(element * root)const
		{
			/*if (root->pl == nullptr) return root->data;
			else return min(root->pl);*/
			return root->pl ? min(root->pl) : root->data;
		}
		int max(element * root)const
		{
			/*	if (root->pr == nullptr) return root->data;
				else return max(root->pr);*/
			return root->pr ? max(root->pr) : root->data;

		}
		int count(element * root)const
		{
			/*static int counter = 0;
			if (root != NULL)
			{
				counter++;
				count(root->pl);
				count(root->pr);
			}
			return counter;*/
			if (root == nullptr) return 0;
			else return count(root->pl) + count(root->pr) + 1;

		}
		//int sum(element* root)const
		//{
		//	if (root == NULL)return 0;
		//	if (count(root) == 1)return root->data;
		//	static int summ = root->data;
		//	if (root->pl != NULL)
		//	{
		//		summ =summ +root->pl->data; //38 + 5 = 43
		//		sum(root->pl);
		//	}
		//	if (root->pr != NULL)
		//	{
		//		summ =summ + root->pr->data;
		//		sum(root->pr);
		//	}
		//	return summ;
		//}
		int sum(element * Root)const
		{
			//return Root == nullptr ? 0 : sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
			return !Root ? 0 : sum(Root->pl) + sum(Root->pr) + Root->data;
		}
	};
	//#define BASE_CHECK
	void main()
	{
		//srand(time(NULL));
#ifdef BASE_CHECK
		int n;
		cout << "Tree size: "; cin >> n;
		tree oak;
		for (int i = 0; i < n; i++) { oak.add(rand() % 100); }
		oak.print(/*oak.get_root()*/);
		cout << "\nAmount of elements: " << oak.count() << endl;
		cout << "\nSum: " << oak.sum() << endl;
		cout << "\nMin: " << oak.min() << endl;
		cout << "\nMax: " << oak.max() << endl;
		cout << "\nAvg: " << oak.avg() << endl << endl;
#endif//BASE CHECK
		tree oak = { 50,25,80,16,32,64,85 };
		oak.print();
		int value;
		cout << "?\n"; cin >> value;
		oak.erase(value);
		oak.print();
	}