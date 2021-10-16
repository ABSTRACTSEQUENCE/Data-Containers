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
	~tree() { cout << "~T\t" << this << endl; }
	void add(int data, element* root)
		{
			if (this->root == nullptr) { this->root = new element(data); return; }
			if (root == nullptr) return;
			if (data < root->data)
			{
				if (root->pl == nullptr) { root->pl = new element(data); }
				else { add(data, root->pl); }
			}
			else 
			{
				if (root->pr)add(data, root->pr);
				else root->pr = new element(data);
			}
		}
	void print(element* root)const
	{
		if (root == nullptr) return;
		cout << root->data << "\t";
		print(root->pl);
		print(root->pr);
	}
	int min(element* root)const
	{
		if (root == nullptr) return 0;
		if (root->pl) min(root->pl);
		return root->data;
	}
	int max(element* root)const
	{
		if (root == nullptr) return 0;
		if (root->pr) max(root ->pr);
		return root->data;
	}
	int count(element* root)const
	{
		static int counter = 0;
		if (root != NULL)
		{
			counter++;
			count(root->pl);
			count(root->pr);
		}
		return counter;
	}
	int sum(element* root)
	{
		if (root == NULL)return 0;
		if (count(root) == 1)return root->data;
		static int summ = root->data;
		if (root->pl != NULL)
		{
			summ =summ +root->pl->data; //38 + 5 = 43
			sum(root->pl);
		}
		if (root->pr != NULL)
		{
			summ =summ + root->pr->data;
			sum(root->pr);
		}
		return summ;
	}
	int avg(element* root)
	{
		return sum(root) / count(root);
	}
};
void main()
{
	srand(time(NULL));
	int n;
	cout << "Tree size: "; cin >> n;
	tree oak;
	for (int i = 0; i < n; i++) { oak.add(rand() % 100, oak.get_root()); }
	oak.print(oak.get_root());
	//cout << "\nAmount of elements: " << oak.count(oak.get_root()) << endl;
	//cout << "\nSum: " << oak.sum(oak.get_root()) << endl;
	cout << "\nAvg: " << oak.avg(oak.get_root()) << endl;
}