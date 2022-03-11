//mentoring 179. 2022.3.9
//구현

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B){
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int sum = 0, size=A.size();
    for (int i = 0; i < size; i++)
        sum +=A[i] * B[size-1-i];
    return sum;
}
