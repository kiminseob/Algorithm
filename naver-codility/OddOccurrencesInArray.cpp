/*
A non-empty array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.

For example, in array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the elements at indexes 0 and 2 have value 9,
the elements at indexes 1 and 3 have value 3,
the elements at indexes 4 and 6 have value 9,
the element at index 5 has value 7 and is unpaired.
Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.

For example, given array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the function should return 7, as explained in the example above.

Write an efficient algorithm for the following assumptions:

N is an odd integer within the range [1..1,000,000];
each element of array A is an integer within the range [1..1,000,000,000];
all but one of the values in A occur an even number of times.
*/
#include<iostream>
#include<vector>
using namespace std;

//정확도100%, 성능 25%...? (탐색 알고리즘 적용해서 써보자)
int main() {
	vector<int> A = { 9,9,9,9,9,9,9,9,9,4,9,9,4 };
	
	vector<int> *arr = &A;

	vector<int> checkedIdx(arr->size());
	int cnt = 0;
	int oddIdx = -1;
	for (int i = 0; i < arr->size() - 1; i++) {
		int temp = arr->at(i);
		if (checkedIdx.at(i) == 0) {
			checkedIdx.at(i) = 1;
			cnt++;
			cout << "인덱스 i :" << i;
			for (int j = i + 1; j < arr->size(); j++) {
				if (temp == arr->at(j) && checkedIdx.at(j) == 0) {
					checkedIdx.at(j) = 1;
					cnt++;
					cout << temp << "\n" << "카운트:" << cnt << "\n";
				}
				if (j == arr->size() - 1 && cnt % 2== 1) {
					oddIdx = i;
					cout << "홀수인덱스 : " << oddIdx;
				}
			}
			if (cnt % 2 == 1) break;
			cnt = 0;
		}
	}
	if (oddIdx == -1) oddIdx = arr->size() - 1;
	cout << "쌍 없는 홀수 : " << arr -> at(oddIdx);
	return arr->at(oddIdx);
}