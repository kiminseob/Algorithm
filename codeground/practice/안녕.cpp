#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	
	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		
		string input_str;
		cin >> input_str;

		// ���� �ҹ���(26��) ���� �迭 ���� �� 0���� �ʱ�ȭ
		// �ƽ�Ű �ڵ�� �޴´�.
		// 10 ���� ���� (97 ~ 122)
		const int ARRAY_LENGTH = 26;
		int tmp[ARRAY_LENGTH] = {0};
		for (int i = 0; i < input_str.length(); i++) {
			tmp[input_str.at(i)-97]++;
		}

		// int �迭 ������
		int size = sizeof(tmp)/sizeof(int);
		
		// h:7 e:4 l:11 o:14
		int h = tmp[7]; //h����
		int e = tmp[4];
		int l = tmp[11];
		int o = tmp[14];

		int min;
		// h, e, o ���� �� ���� ���� ���� ���� ���� ã�´�.
		if (h <=e) {
			if (h <= o) {
				min = h;
			}
		}
		if (e <= h) {
			if (e <= o) {
				min = e;
			}
		}
		if (o <=h) {
			if (o <= e) {
				min = o;
			}
		}
		
		// ���� ���� ���� ���ڰ� 0�� �ų�, ���� �ҹ��� '��'�� 2������ ������
		if (min == 0 || l<2) { Answer = 0; }
		else {
			if (l >= min * 2){
				Answer = min;
			}
			else {
				Answer = 0;
			}
		}
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}