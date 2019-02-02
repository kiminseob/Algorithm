/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	
	/*
	���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	vector<int> test_cases;
	vector< vector<int> > l_arr;
	for (int i = 0; i < T; i++) {
		vector<int> l_tmp;
		int tmp;
		int cases;
		cin >> cases;
		test_cases.push_back(cases);

		for (int j = 0; j < test_cases.back(); j++) {
			cin >> tmp;
			l_tmp.push_back(tmp);
			if (j + 1 == test_cases.back()) {
				l_arr.push_back(l_tmp);
				l_tmp.clear();
			}
		}
	}
	/*
	int test_cases_size = test_cases.size();	
	for (int i = 0; i < test_cases_size; i++) {
		cout << test_cases.at(i)<< endl;
		int l_arr_size = l_arr.at(i).size();
		for (int j = 0; j < l_arr_size; j++) {
			cout << l_arr[i][j] << endl;
		}
	}
	*/
	vector < vector<int> > triangle;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int l_arr_size = l_arr.at(test_case - 1).size();
		
		// �ﰢ�� ������ ������ 6�� ���� ������ �ﰢ�� 2���� ������ ���ϱ� ������
		// 0 ��� �� ���� �׽�Ʈ ���̽��� �ٷ� �Ѿ��.
		if (l_arr_size < 6) {
			cout << "#" << test_case << " 0"<<endl;
		}
		else {
			for (int i = 0; i < l_arr_size - 2; i++) {
				for (int j = i + 1; j < l_arr_size - 1; j++) {
					for (int k = j + 1; k < l_arr_size; k++) {
						int a = l_arr.at(test_case - 1).at(i);//1 ��° ����
						int b = l_arr.at(test_case - 1).at(j);//2 ��° ����
						int c = l_arr.at(test_case - 1).at(k);//3 ��° ����
						
						int max;
						vector <int> tri_tmp;
						if (a >= b && a >= c) {
							max = a;
							//�ﰢ�� ���� �����ϸ�
							if (max < b + c) {
								//�̶��� �ε���(li,lj,lk), �� ���� ���ʷ� ����.
								tri_tmp.push_back(i);
								tri_tmp.push_back(j);
								tri_tmp.push_back(k);
								tri_tmp.push_back(a + b + c);

								//ó�� 2���� �ﰢ���� ���� ���� �׳� �����.
								if (triangle.size() == 0) { 
									triangle.push_back(tri_tmp); 
								}
								// 3��° �ﰢ�� ���ʹ� �� ���̸� ���Ͽ� ������Ʈ�Ѵ�.
								else {
									if (triangle[0][3] < a + b + c) {
										triangle[0] = tri_tmp;
									}
									if (triangle[1][3] < a + b + c) {
										triangle[1] = tri_tmp;
									}
								}
								
							}
							//�ﰢ�� ���� �������� ������ �ƹ��͵� �߰����� �ʰ� �Ѿ��.
						}
						else if (b >= a && b >= c) {
							max = b;
							if (max < a + c) {
								tri_tmp.push_back(i);
								tri_tmp.push_back(j);
								tri_tmp.push_back(k);
								tri_tmp.push_back(a + b + c);
								triangle.push_back(tri_tmp);

								//ó�� 2���� �ﰢ���� ���� ���� �׳� �����.
								if (triangle.size() < 2) {
									triangle.push_back(tri_tmp);
								}
								// 3��° �ﰢ�� ���ʹ� �� ���̸� ���Ͽ� ������Ʈ�Ѵ�.
								else {
									if (triangle[0][3] < a + b + c) {
										triangle[0] = tri_tmp;
									}
									if (triangle[1][3] < a + b + c) {
										triangle[1] = tri_tmp;
									}
								}
							}
						}
						else if (c >= a && c >= b) {
							max = c;
							if (max < a + b) {
								tri_tmp.push_back(i);
								tri_tmp.push_back(j);
								tri_tmp.push_back(k);
								tri_tmp.push_back(a + b + c);
								triangle.push_back(tri_tmp);

								//ó�� 2���� �ﰢ���� ���� ���� �׳� �����.
								if (triangle.size() < 2) {
									triangle.push_back(tri_tmp);
								}
								// 3��° �ﰢ�� ���ʹ� �� ���̸� ���Ͽ� ������Ʈ�Ѵ�.
								else {
									if (triangle[0][3] < a + b + c) {
										triangle[0] = tri_tmp;
									}
									if (triangle[1][3] < a + b + c) {
										triangle[1] = tri_tmp;
									}
								}
							}
						}

					}//end k
				}//end j
			}//end i
			//�ϳ��� ���̽� ���̽��� ��� ������ �ﰢ���� �����ȣ�� �� �ѷ� ������ ������ ������.
			//����, �ּ� 2���� �ﰢ���� ���� �� ���� ���� 0��� �� �Ѿ��.
			if (triangle.size() < 2) {
				cout << "#" << test_case << " 0" << endl;
			}
			//2�� �̻��� �ﰢ���� ���� �� �ִ� ��� �� �ѷ� ���� ����Ʈ�Ѵ�.
			else {
				cout << "#" << test_case << " " << triangle[0][3] + triangle[1][3] <<endl;
			}

			//���������� �ﰢ�� �迭�� �ʱ�ȭ�Ѵ�.
			triangle.clear();

		}//end else
	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
