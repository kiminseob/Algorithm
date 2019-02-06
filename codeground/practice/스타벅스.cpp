/*
스타벅스는 하나의 문화다.
그렇기 때문에 이 세상에 있는 문제들은 스타벅스와 연관이 있기도 하다.
그런 여러 문제 중 하나로, 어떤 커피를 구매할 것이냐가 있다.
A사의 신입사원 김커피씨는 점심 시간이 끝나가면서 상사에게 커피를 사오라는 명령을 받았다.
김커피씨는 법인 카드를 최대 K원 이용할 수 있다.
김커피씨가 근무중인 부서에는 N명의 사람들이 있는데, 각각 원하는 커피의 종류가 정해져 있다.
스타벅스에는 M개의 커피 종류가 있는데, 커피마다 1 ~ M까지의 번호가 주어져 있다.
스타벅스 커피들의 가격과, 부서 사람들의 커피 기호와, 법인 카드 지출의 한계치인 K가 주어졌을 때,
김커피씨가 N명 모두가 행복하게 주어진 돈으로 커피를 구매할 수 있을지 구하는 프로그램을 작성하라.
제한시간 : 1초 (Java 2초 ) / 메모리 제한 : 256 MB
-----
[입력]: 첫 줄에 테스트케이스 T가 주어진다 (T <= 20).
첫 줄에 N, M, K가 차례대로 주어진다 (1 <= N <= 30, 1 <= M <= 20, 0 <= K <= 100 000).
그 다음 N개의 줄 중 i번째 줄에는 ci 가 주어진다 (1 <= ci <= M). ci 는 i번째 사람이 좋아하는 커피의 종류를 나타낸다.
그 다음 M개의 줄에는 pi 가 주어진다 (3 000 <= pi <= 8 000).
[출력]: 김커피씨가 모든 커피를 구매할 수 있으면 “Y”를, 모든 커피를 구매할 수 없으면 “N”를 출력한다.
-----
[입출력예]
-입력
2
3 2 10000
1
2
2
4000
3000
3 2 10000
1
2
2
5000
3000
-출력
Case #1
Y
Case #2
N
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char* Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		//N:사원수, M:커피종류, K : 법인카드 최대치
		int N, M, K;
		cin >> N >> M >> K;
		//Ci : 사원별 좋아하는 커피 종류
		int *Ci = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> Ci[i];
		}
		//Pi : 커피 종류별 가격
		int *Pi = new int[M];
		for (int i = 0; i < M; i++) {
			cin >> Pi[i];
		}
		//사원이 선택한 커피의 가격을 모두 더한다.
		int price = 0;
		for (int i = 0; i < N; i++) {
			price += Pi[Ci[i] - 1];
		}
		// 모든 커피의 총합이 법인카드 최대치 K보다 낮은가?
		// 낮다면
		if (price <= K) {
			Answer = "Y";
		}
		else {
			Answer = "N";
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}