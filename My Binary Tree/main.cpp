#include <iostream>
using namespace std;
class tree{
	class element {
		element* pl;
		element* pr;
		int data;
	public:
		element(int data, element* pr = nullptr, element* pl = nullptr) :
			pr(pr), pl(pl), data(data) {cout << "E" << endl;}
		~element() { cout << "~E" << endl; };
		friend class tree;
	}*root;
public:
	tree() : root(nullptr) { cout << "T" << endl; };
	~tree() { cout << "~T" << endl; }
	element* get() { return root; }

	void add(int data) { add(root, data); }
	void print() { print(root); }
	void min() { cout << min(root); }
	void max() { cout << max(root); }
	void erase(int data) { erase(root, data); }
protected:
	void add(element* root, int data) {
		if (this->root) {
			if (root->data > data) {
				if (root->pl) add(root->pl, data);
				else root->pl = new element(data);
				return;
			}
			else if (root->data < data) {
				if (root->pr) add(root->pr, data);
				else root->pr = new element(data);
				return;
			}
			else if (root->data == data) return;
		}
		else {
			this->root = new element(data); 
			return;
		}
	}
	void print(element* root) {
		if (root) {
			cout << root->data << "\t";
			print(root->pl);
			print(root->pr);
		}
		else return;
	}
	int min(element* root) {
		if (this->root) {
			if (root->pl)min(root->pl);
			else return root->data;
		}
		else return 0;
	}
	int max(element* root) {
		if (this->root) {
			if (root->pr)max(root->pr);
			else return root->data;
		}
		else return 0;
	}
	void erase(element* root, int data) {
		if (this->root) {
			if (data == root->data) {
				if (root->pl || root->pr) {
					erase(root->pl, data);
					erase(root->pr, data);
				}
				else {
					root = nullptr;
					delete root;
				}
			}
			else {
				erase(root->pl, data);
				erase(root->pr, data);
			}
		}
		else return;
	}
};

void main()
{
	srand(time(NULL));
	tree oak;
	for (int i = 0; i < 5; i++) oak.add(rand() % 100);
	oak.add(1000);
	oak.print();
	oak.erase(1000);
	cout << endl;
	oak.print();
	//cout << endl << "Min: "; oak.min(); cout << endl;
	//cout << endl << "Max: "; oak.max(); cout << endl;
}