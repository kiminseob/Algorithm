#include<iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::setprecision;

// 두 수의 나눗셈 
int main() {
	double a, b;
	cin >> a >> b;
	cout << setprecision(10);
	cout << a / b;

	return 0;
}