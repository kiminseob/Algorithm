#include<iostream>
using std::cin;
using std::cout;
using std::endl;

/*(A+B)%C는 (A%C + B%C)%C 와 같을까?

(A×B) % C는(A%C × B%C) % C 와 같을까 ?*/
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << (A + B) % C << endl;
	cout << (A%C + B%C) % C << endl;
	cout << (A*B) % C << endl;
	cout << (A%C * B%C) % C << endl;
	return 0;
}