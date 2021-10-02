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
	}					/*Почему-то после нескольких итераций происходит ошибка в расчётах		
						т.е. он почему-то думает что 6 * 4 = 18
						А ещё после того, как рекурсия отработала и условие if не соблюдалось и по логике он
						должен был выполнить условие else и вернуться в main, он почему-то выполняет условие
						else и возвращается к return, который в if, хотя он должен вообще игнорить if*/
	else return a;
}//UNDONE!
int power(int a, int n, int i = 1)
{
	if (i != n) 
	{
		a = a * a; 
		return power(a, n, i + 1);
	}								/*Тут тоже самое*/
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