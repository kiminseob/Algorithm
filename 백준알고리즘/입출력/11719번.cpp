#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//�Է� ���� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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