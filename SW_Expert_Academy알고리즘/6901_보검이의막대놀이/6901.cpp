// 알고리즘을 하려고 c++도 엊그제 시작해서 배우고 있는데 ..
// 알고리즘 문제 풀이 자체도 엊그제 시작했는데 ..
// 풀만할 것 같아서 도전했다가 탈탈 털린 문제 ㅋ.
// 알고리즘 공부하고 나~중~에~ 다시 해보자..
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

	
	//랜덤값 생성 2가지
	/*
	srand((unsigned int)time(0));

	ofstream o(filename.c_str());
	o << 1 << endl;

	for (int i = 0; i < 1; i++) {
		int testcase = (rand()) + 1;
		o << testcase << endl;
		cout << "테스트케이스 : "<< testcase << endl;
		for (int j = 0; j < testcase; j++) {
			unsigned long long num = (rand() * 100000) + 1;
			o << num << endl;
			cout << j << "번: " << num << endl;
		}
	}
	o.close();
	*/
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	
	
	/*
	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	vector < vector<unsigned long long> > l_arr;
	for (int i = 0; i < T; i++) {
		vector<unsigned long long> l_tmp;
		int cases;
		unsigned long long tmp;
		cin >> cases;
		
		for (int j = 0; j < cases; j++) {
			cout << "cases 몇 번 : " << j << endl;
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
		
		// 삼각형 변수의 갯수가 6개 보다 작으면 삼각형 2개를 만들지 못하기 때문에
		// 0 출력 후 다음 테스트 케이스로 바로 넘어간다.
		if (l_arr_size < 6) {
			cout << "#" << test_case << " 0"<<endl;
		}
		else {
			for (int i = 0; i < l_arr_size - 2; i++) {
				for (int j = i + 1; j < l_arr_size - 1; j++) {
					for (int k = j + 1; k < l_arr_size; k++) {
						unsigned long long a = l_arr.at(test_case - 1).at(i);//1 번째 길이
						unsigned long long b = l_arr.at(test_case - 1).at(j);//2 번째 길이
						unsigned long long c = l_arr.at(test_case - 1).at(k);//3 번째 길이
						cout << "a b c 길이 : " << a <<b<<c << endl;
						unsigned long long max;
						vector <unsigned long long> tri_tmp;
						//a변의 길이가 가장 클 경우.
						if (a >= b && a >= c) {
							max = a;
							//삼각형 조건(가장 큰 변의 길이가 다른 두 변의 합보다 작다) 만족하면
							if (max < b + c) {
								//이때의 인덱스(li,lj,lk)와 총 변의 길이를 차례로 저장.
								tri_tmp.push_back(i);
								tri_tmp.push_back(j);
								tri_tmp.push_back(k);
								tri_tmp.push_back(a + b + c);

								triangle.push_back(tri_tmp); 
							}
							//삼각형 조건 만족하지 않으면 아무것도 추가하지 않고 넘어간다.
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

			//하나의 테스트 케이스에서 모든 가능한 삼각형의 막대번호와 총 둘레 길이 저장이 끝난 후
			//최소 2개의 삼각형을 만들 수 없는 경우는 0출력 후 다음 테스트 케이스로 넘어간다.
			if (triangle.size() < 2) {
				cout << "#" << test_case << " 0" << endl;
			}
			//2개 이상의 삼각형을 만들 수 있는 경우
			else {
				vector < vector<unsigned long long> > unmatch_tri;
				// 중복되는 변을 가지지 않는 두 개의 삼각형을 찾아서, 각각의 위치와 총 변의 길이를 더하여 저장한다.
				for (int i = 0; i < triangle.size()-1; i++) {
					int idxA = triangle[i][0];
					int idxB =	triangle[i][1];
					int idxC = triangle[i][2];
					for (int j = i + 1; j < triangle.size(); j++) {
						int c_idxA = triangle[j][0];
						int c_idxB = triangle[j][1];
						int c_idxC = triangle[j][2];
						cout << "common 길이 : " << j <<  endl;
						int common = 0;
						//모든 변을 비교하여 하나라도 같은 경우를 체크한다.
						if (idxA == c_idxA || idxA == c_idxB || idxA == c_idxC) {
							common = 1;
						}
						if (idxB == c_idxA || idxB == c_idxB || idxB == c_idxC) {
							common = 1;
						}
						if (idxC == c_idxA || idxC == c_idxB || idxC == c_idxC) {
							common = 1;
						}
						//비교 후, 공통 변수가 없으면
						if (common == 0) {
							vector <unsigned long long> com_tmp;
							com_tmp.push_back(i);
							com_tmp.push_back(j);
							com_tmp.push_back(triangle[i][3]+triangle[j][3]);

							unmatch_tri.push_back(com_tmp);
						}
					}//end for j
				}//end for i
				//중복되지 않은 삼각형 2쌍이 없는 경우
				if (unmatch_tri.size() == 0) {
					cout << "#" << test_case << " 0" << endl;
				}
				/* 
					대망의 마지막 부분..
					변이 중복되지 않은 삼각형 2쌍을, 2쌍의 변의 길이 합으로 내림차순 정렬 한다.
				*/
				else {
					sort(unmatch_tri.begin(), unmatch_tri.end(), compare);
					cout << "#" << test_case << " " << unmatch_tri[0][2] << endl;
				}
			}//end in else

			//마지막으로 삼각형 배열을 초기화한다.
			triangle.clear();

		}//end out else
	}
	cout << "end";
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}