/*
An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

int solution(vector<int> &A);

that, given an array A, returns the value of the missing element.

For example, given array A such that:

  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].
*/
#include<iostream>
#include<vector>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int>*arr = &A;
    vector<int>B(arr->size()+2);
    int result;
    
    for(int i=0; i<arr->size(); i++){
        B.at(arr->at(i)) = 1;
    }
    for(int j=1; j<B.size(); j++){
        if(B.at(j)==0){
            result = j;
            break;
        }
    }
    return result;
}