//mentoring 42. 2022.1.1
//string 함수, sort의 응용

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct{
    int idx;
    string title;
    string head;
    int number;
}fileInfo;
vector<fileInfo> list;

bool compareRule(const fileInfo &a,const fileInfo &b){
    if(a.head==b.head){
        if(a.number==b.number)
            return a.idx<b.idx;
        return a.number<b.number;
    }
    return a.head<b.head;
}

void get_fileInfo(int idx, string &title){
    string fhead="",n="";
    int fnumber=0;
    int tLen=title.length();

    for(int i=0; i<tLen; i++){//head
        if(isdigit(title[i])){
            break;
        }
        fhead+=title[i];
    }
    int fhLen=fhead.length();
    for(int i=0; i<fhLen; i++){
        fhead[i]=tolower(fhead[i]);
    }

    for(int i=fhLen; i<tLen; i++){//number가 시작하는 index에서 연속으로 최대 5글자의 숫자 가능
        if(!isdigit(title[i]))
            break;
        n+=title[i];
        if(n.length()==5)
            break;
    }

    fnumber=stoi(n);
    list.push_back({idx, title, fhead, fnumber});
}
vector<string> solution(vector<string> files) {
    vector<string> answer;

    for(int i=0; i<files.size(); i++)
        get_fileInfo(i, files[i]);

    sort(list.begin(), list.end(), compareRule);
    for(int i=0; i<list.size(); i++)
        answer.push_back(list[i].title);
    return answer;
}
