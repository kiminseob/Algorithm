#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//입력 받은 대로 출력하는 프로그램을 작성하시오.
int main() {
	string a;
	int cnt = 0;
	while (cnt<100) {
		getline(cin, a);
		cout << a << endl;
		cnt++;
	}

	return 0;
}