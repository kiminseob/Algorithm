#include<iostream>
using std::cin;
using std::cout;
using std::endl;

/*(A+B)%C�� (A%C + B%C)%C �� ������?

(A��B) % C��(A%C �� B%C) % C �� ������ ?*/
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << (A + B) % C << endl;
	cout << (A%C + B%C) % C << endl;
	cout << (A*B) % C << endl;
	cout << (A%C * B%C) % C << endl;
	return 0;
}