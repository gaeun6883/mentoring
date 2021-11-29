//mentoring 22. 2021.11.26

#include <string>
#include <vector>
using namespace std;
#define min(x,y) x<y?x:y

int matrix[102][102];

int spinning(vector<int> v){
    int x1=v[0]-1, y1=v[1]-1;
    int x2=v[2]-1, y2=v[3]-1;
    int temp = matrix[x1][y1];
    int min=temp;
    for (int i = x1; i < x2; i++)
    {
        min = min(min, matrix[i][y1]);
        matrix[i][y1] = matrix[i + 1][y1];
    }
    for (int i = y1; i < y2; i++)
    {
        min = min(min, matrix[x2][i]);
        matrix[x2][i] = matrix[x2][i + 1];
    }
    for (int i = x2; i > x1; i--)
    {
        min = min(min, matrix[i][y2]);
        matrix[i][y2] = matrix[i - 1][y2];
    }
    for (int i = y2; i > y1; i--)
    {
        min = min(min, matrix[x1][i]);
        matrix[x1][i] = matrix[x1][i - 1];
    }
    matrix[x1][y1 + 1] = temp;
    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int n=1;
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            matrix[i][j]=n++;

    int result;
    for(int i=0; i<queries.size(); i++){
        result=spinning(queries[i]);
        answer.push_back(result);
    }

    return answer;
}
