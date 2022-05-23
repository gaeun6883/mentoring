//mentoring 233. 2022.5.16
//sstream & 구현

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<double> endTime(lines.size());
    vector<double> processTime(lines.size());
     for (int i = 0; i < lines.size(); i++) {
        lines[i][13] = lines[i][16] = ' ';
        istringstream ss(lines[i]);
        string date;
        double h, min, sec;
        ss >> date >> h >> min >> sec >> processTime[i];
        endTime[i] = h * 3600.0 + min * 60.0 + sec;
    }
    sort(endTime.begin(), endTime.end());

    int cnt;
    for (int i = 0; i < lines.size(); i++) {
        cnt = 1;
        for (int j = i+1; j < lines.size(); j++)
            if (endTime[j] - processTime[j] < endTime[i] + 0.999)
                cnt++;
        answer=max(answer,cnt);
    }
    return answer;
}
