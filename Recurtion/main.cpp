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
#ifdef FACTORIAL
int factorial(int n)
{
	if (n == 0) return 1;
	return n * factorial(n - 1);
	//return n == 0 ? 1 : n * factorial(n - 1);
}
#endif
double power(double a, int n)
{
	if (n == 0) return 1;
	/*if (n > 0) return a * power(a, n - 1);
	else return 1 / a * power(a, n + 1);*/
	return n == 0 ? 1 : n > 0 ? a * power(a, n - 1) : 1 / a * power(a, n + 1);
}
void main()
{
	int a; int n;
	cout << "Number: "; cin >> a;
	cout << "Power: "; cin >> n;
	cout << power(a, n) << endl;
	main();
}