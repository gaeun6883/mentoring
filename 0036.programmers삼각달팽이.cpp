//mentoring 36. 2021.12.28
//배열의 응용

#include <string>
#include <vector>
#define MAX 1003
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int** problem=new int*[n];
    for(int i=0; i<n; i++)
        problem[i]=new int[i+1];

    int startRow = 0, endRow = n - 1, startCol = 0;
    int cur = 1;
    while (1) {
        for (int i = startRow; i <= endRow; i++, cur++)//밑으로
            problem[i][startCol] = cur;

        for (int i = startCol + 1; i < n - startRow; i++, cur++) //옆으로
            problem[endRow][i] = cur;

        for (int i = endRow - 1; i > startRow; i--, cur++) //위로
            problem[i][i - startCol] = cur;

        startRow += 2;
        if (startRow >= endRow)
            break;
        endRow -= 1;
        startCol += 1;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            answer.push_back(problem[i][j]);
    return answer;
}
