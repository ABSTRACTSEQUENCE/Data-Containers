#include<iostream>
using namespace std;
/*void elevator(int level)
{
	if (level == false) return;
	cout << level;
	if (level == 4) cout << " LVL_DEATH";
	cout << endl;
	elevator(level - 1);
}*/
int factorial(int value, int a = 1, int i = 1)
{
	if (i != value) 
	{ 
		a = a * i; 
	return factorial(value, a, i + 1);
	}					/*������-�� ����� ���������� �������� ���������� ������ � ��������		
						�.�. �� ������-�� ������ ��� 6 * 4 = 18
						� ��� ����� ����, ��� �������� ���������� � ������� if �� ����������� � �� ������ ��
						������ ��� ��������� ������� else � ��������� � main, �� ������-�� ��������� �������
						else � ������������ � return, ������� � if, ���� �� ������ ������ �������� if*/
	else return a;
}//UNDONE!
int power(int a, int n, int i = 1)
{
	if (i != n) 
	{
		a = a * a; 
		return power(a, n, i + 1);
	}								/*��� ���� �����*/
	else return a;
	
}//UNDONE
void main()
{
	/*int n;
	cout << "LVL: "; cin >> n;
	elevator(n);*/
	cout << power(2, 5) << endl;
	cout << factorial(5);
}