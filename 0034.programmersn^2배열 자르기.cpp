//mentoring 34. 2021.12.27
//배열의 응용

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i=left; i <= right; i++) {
        long long div = i / n;
        long long mod = i % n;
        answer.push_back(max(div, mod) + 1);
    }
    return answer;
}

//초기코드
/*#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int** matrix=new int*[n];
    for(int i=0;i<n;i++)
        matrix[i]=new int[n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>j)
                matrix[i][j]=i+1;
            else matrix[i][j]=j+1;
            answer.push_back(matrix[i][j]);
        }
    }
    answer.erase(answer.begin()+right+1,answer.end());
    answer.erase(answer.begin(),answer.begin()+left);
    return answer;
}*/
