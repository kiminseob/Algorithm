#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//�Է� ���� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
int main() {
	string a;

	while (true) {
		getline(cin, a);
		if (a == "") { break; }
		cout << a << endl;
	}

	return 0;
}