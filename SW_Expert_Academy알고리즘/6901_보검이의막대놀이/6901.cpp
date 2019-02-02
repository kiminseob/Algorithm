/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
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
	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
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
		
		// 삼각형 변수의 갯수가 6개 보다 작으면 삼각형 2개를 만들지 못하기 때문에
		// 0 출력 후 다음 테스트 케이스로 바로 넘어간다.
		if (l_arr_size < 6) {
			cout << "#" << test_case << " 0"<<endl;
		}
		else {
			for (int i = 0; i < l_arr_size - 2; i++) {
				for (int j = i + 1; j < l_arr_size - 1; j++) {
					for (int k = j + 1; k < l_arr_size; k++) {
						int a = l_arr.at(test_case - 1).at(i);//1 번째 길이
						int b = l_arr.at(test_case - 1).at(j);//2 번째 길이
						int c = l_arr.at(test_case - 1).at(k);//3 번째 길이
						
						int max;
						vector <int> tri_tmp;
						if (a >= b && a >= c) {
							max = a;
							//삼각형 조건 만족하면
							if (max < b + c) {
								//이때의 인덱스(li,lj,lk), 총 길이 차례로 저장.
								tri_tmp.push_back(i);
								tri_tmp.push_back(j);
								tri_tmp.push_back(k);
								tri_tmp.push_back(a + b + c);

								//처음 2개의 삼각형을 만들 때는 그냥 만든다.
								if (triangle.size() == 0) { 
									triangle.push_back(tri_tmp); 
								}
								// 3번째 삼각형 부터는 총 길이를 비교하여 업데이트한다.
								else {
									if (triangle[0][3] < a + b + c) {
										triangle[0] = tri_tmp;
									}
									if (triangle[1][3] < a + b + c) {
										triangle[1] = tri_tmp;
									}
								}
								
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

								//처음 2개의 삼각형을 만들 때는 그냥 만든다.
								if (triangle.size() < 2) {
									triangle.push_back(tri_tmp);
								}
								// 3번째 삼각형 부터는 총 길이를 비교하여 업데이트한다.
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

								//처음 2개의 삼각형을 만들 때는 그냥 만든다.
								if (triangle.size() < 2) {
									triangle.push_back(tri_tmp);
								}
								// 3번째 삼각형 부터는 총 길이를 비교하여 업데이트한다.
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
			//하나의 테이스 케이스의 모든 가능한 삼각형의 막대번호와 총 둘레 길이의 저장이 끝났다.
			//먼저, 최소 2개의 삼각형을 만들 수 없는 경우는 0출력 후 넘어간다.
			if (triangle.size() < 2) {
				cout << "#" << test_case << " 0" << endl;
			}
			//2개 이상의 삼각형을 만들 수 있는 경우 총 둘레 길이 프린트한다.
			else {
				cout << "#" << test_case << " " << triangle[0][3] + triangle[1][3] <<endl;
			}

			//마지막으로 삼각형 배열을 초기화한다.
			triangle.clear();

		}//end else
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
