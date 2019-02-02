// �˰����� �Ϸ��� c++�� ������ �����ؼ� ���� �ִµ� ..
// �˰��� ���� Ǯ�� ��ü�� ������ �����ߴµ� ..
// Ǯ���� �� ���Ƽ� �����ߴٰ� ŻŻ �и� ���� ��.
// �˰��� �����ϰ� ��~��~��~ �ٽ� �غ���..
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#include<cstdlib>
#include<iostream>
#include<fstream>
#include<ctime>
string filename = "sample_input.txt";
using std::ofstream;

bool compare(vector<unsigned long long> a, vector<unsigned long long> b) {
	return a[2] > b[2];
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	
	//������ ���� 2����
	/*
	srand((unsigned int)time(0));

	ofstream o(filename.c_str());
	o << 1 << endl;

	for (int i = 0; i < 1; i++) {
		int testcase = (rand()) + 1;
		o << testcase << endl;
		cout << "�׽�Ʈ���̽� : "<< testcase << endl;
		for (int j = 0; j < testcase; j++) {
			unsigned long long num = (rand() * 100000) + 1;
			o << num << endl;
			cout << j << "��: " << num << endl;
		}
	}
	o.close();
	*/
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	
	
	/*
	���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	vector < vector<unsigned long long> > l_arr;
	for (int i = 0; i < T; i++) {
		vector<unsigned long long> l_tmp;
		int cases;
		unsigned long long tmp;
		cin >> cases;
		
		for (int j = 0; j < cases; j++) {
			cout << "cases �� �� : " << j << endl;
			cin >> tmp;
			l_tmp.push_back(tmp);
			if (j + 1 == cases) {
				l_arr.push_back(l_tmp);
				l_tmp.clear();
			}
		}
	}
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector < vector<unsigned long long> > triangle;
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
						unsigned long long a = l_arr.at(test_case - 1).at(i);//1 ��° ����
						unsigned long long b = l_arr.at(test_case - 1).at(j);//2 ��° ����
						unsigned long long c = l_arr.at(test_case - 1).at(k);//3 ��° ����
						cout << "a b c ���� : " << a <<b<<c << endl;
						unsigned long long max;
						vector <unsigned long long> tri_tmp;
						//a���� ���̰� ���� Ŭ ���.
						if (a >= b && a >= c) {
							max = a;
							//�ﰢ�� ����(���� ū ���� ���̰� �ٸ� �� ���� �պ��� �۴�) �����ϸ�
							if (max < b + c) {
								//�̶��� �ε���(li,lj,lk)�� �� ���� ���̸� ���ʷ� ����.
								tri_tmp.push_back(i);
								tri_tmp.push_back(j);
								tri_tmp.push_back(k);
								tri_tmp.push_back(a + b + c);

								triangle.push_back(tri_tmp); 
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
							}
						}

					}//end for k
				}//end for j
			}//end for i

			//�ϳ��� �׽�Ʈ ���̽����� ��� ������ �ﰢ���� �����ȣ�� �� �ѷ� ���� ������ ���� ��
			//�ּ� 2���� �ﰢ���� ���� �� ���� ���� 0��� �� ���� �׽�Ʈ ���̽��� �Ѿ��.
			if (triangle.size() < 2) {
				cout << "#" << test_case << " 0" << endl;
			}
			//2�� �̻��� �ﰢ���� ���� �� �ִ� ���
			else {
				vector < vector<unsigned long long> > unmatch_tri;
				// �ߺ��Ǵ� ���� ������ �ʴ� �� ���� �ﰢ���� ã�Ƽ�, ������ ��ġ�� �� ���� ���̸� ���Ͽ� �����Ѵ�.
				for (int i = 0; i < triangle.size()-1; i++) {
					int idxA = triangle[i][0];
					int idxB =	triangle[i][1];
					int idxC = triangle[i][2];
					for (int j = i + 1; j < triangle.size(); j++) {
						int c_idxA = triangle[j][0];
						int c_idxB = triangle[j][1];
						int c_idxC = triangle[j][2];
						cout << "common ���� : " << j <<  endl;
						int common = 0;
						//��� ���� ���Ͽ� �ϳ��� ���� ��츦 üũ�Ѵ�.
						if (idxA == c_idxA || idxA == c_idxB || idxA == c_idxC) {
							common = 1;
						}
						if (idxB == c_idxA || idxB == c_idxB || idxB == c_idxC) {
							common = 1;
						}
						if (idxC == c_idxA || idxC == c_idxB || idxC == c_idxC) {
							common = 1;
						}
						//�� ��, ���� ������ ������
						if (common == 0) {
							vector <unsigned long long> com_tmp;
							com_tmp.push_back(i);
							com_tmp.push_back(j);
							com_tmp.push_back(triangle[i][3]+triangle[j][3]);

							unmatch_tri.push_back(com_tmp);
						}
					}//end for j
				}//end for i
				//�ߺ����� ���� �ﰢ�� 2���� ���� ���
				if (unmatch_tri.size() == 0) {
					cout << "#" << test_case << " 0" << endl;
				}
				/* 
					����� ������ �κ�..
					���� �ߺ����� ���� �ﰢ�� 2����, 2���� ���� ���� ������ �������� ���� �Ѵ�.
				*/
				else {
					sort(unmatch_tri.begin(), unmatch_tri.end(), compare);
					cout << "#" << test_case << " " << unmatch_tri[0][2] << endl;
				}
			}//end in else

			//���������� �ﰢ�� �迭�� �ʱ�ȭ�Ѵ�.
			triangle.clear();

		}//end out else
	}
	cout << "end";
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}