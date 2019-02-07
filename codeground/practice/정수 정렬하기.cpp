#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Answer;

void quickSort(int *a, int s, int e);
void swap(int *as, int *ae);
int main(int argc, char** argv)
{
	int T, test_case;
	
	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		
		int test_num;
		cin >> test_num;
		
		int*a = new int[test_num];
		for (int i=0; i < test_num; i++) {
			cin >> a[i];
		}

		//quick Á¤·Ä
		quickSort(a, 0, test_num - 1);
		
		int sum = 0;
		for (int i = 1; i < test_num; i++) {
			if (i == 1) { sum += a[i-1] - a[i]; }
			else if (i % 2 == 0){ sum += a[i]; }
			else if (i % 2 == 1) { sum -= a[i]; }
		}
		Answer = sum;
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

void quickSort(int *a, int s, int e) {
	int pivot = a[s];
	int bs = s, be = e;
	while (s < e) {
		while (pivot <= a[e] && s < e) e--;
		if (s > e) break;

		while (pivot >= a[s] && s < e) s++;
		if (s > e) break;

		swap(a[s], a[e]);
	}

	swap(a[bs], a[s]);
	if (bs < s) {
		quickSort(a, bs, s - 1);
	}
	if (be > e) {
		quickSort(a, s + 1, be);
	}
}

void swap(int *as, int *ae) {
	int* tmp;
	tmp = as;
	as = ae;
	ae = tmp;
}