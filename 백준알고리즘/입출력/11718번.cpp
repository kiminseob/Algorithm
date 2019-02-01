#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//입력 받은 대로 출력하는 프로그램을 작성하시오.
int main() {
	string a;

	while (true) {
		getline(cin, a);
		if (a == "") { break; }
		cout << a << endl;
	}

	return 0;
}