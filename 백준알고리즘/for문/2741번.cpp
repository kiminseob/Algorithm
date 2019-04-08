#include<iostream>
using namespace std;

/*
문제.
자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

입력.
첫째 줄에 100,000보다 작거나 같은 자연수 N이 주어진다.

출력.
첫째 줄부터 N번째 줄 까지 차례대로 출력한다.
*/
int main() {
	//for문 입출력 속도를 최대로 하기 위한 방법.
	//1. endl대신 개행문자 사용.
	//2. sync_with_stdio에 false 적용.(c의 stdio 버퍼와 동기화하지 않는다.)
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cout << i << "\n";
	}
	return 0;
}