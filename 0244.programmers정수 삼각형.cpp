//mentoring 244. 2022.5.27
//구현

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int s=triangle.size();
    for(int i=1; i<s; i++)
        for(int j=0; j<=i; j++)
            if(j==0)
                triangle[i][j]=triangle[i][j]+triangle[i-1][j];
            else if(j==i)
                triangle[i][j]=triangle[i][j]+triangle[i-1][j-1];
            else
                triangle[i][j]=triangle[i][j]+max(triangle[i-1][j],triangle[i-1][j-1]);

    answer=*max_element(triangle[s-1].begin(), triangle[s-1].end());
    return answer;
}
