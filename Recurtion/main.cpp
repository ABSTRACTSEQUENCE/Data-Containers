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
int factorial(int value, int number = 1, int i = 1)
{
	if (i != value)
	{
		//number = number * i;
		factorial(value, number * i, i + 1);  //�������� �������� ���� ��� ��-�������, �� � 4 �������� �� �������� ���������� � number �����-�� ���� (6 * 4 = 18)
	}
	else return number;
}
int power(int value, int powerr, int i = 0)
{
	if (i != powerr)
	{
		power(value * value, powerr, i + 1);  // ��� �� �� �����, ������� �� ���������
	}
	else return value;
}
//UNDONE
void main()
{
	/*int n;
	cout << "LVL: "; cin >> n;
	elevator(n);*/
	cout << power(5,6);
}