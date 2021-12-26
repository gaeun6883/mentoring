//mentoring 31. 2021.12.26
//그래프 topSort()와 비슷한 문제.

#include <string>
#include <vector>
#define MAX 30
using namespace std;

bool right_skillT(string skill, string skillTree){
    int next=0;
    for(int i=0; i<skillTree.length(); i++){
        int newS=skill.find(skillTree.at(i));
        //if(newS==-1)
          //  continue;
        if(next++!=newS)
            return false;
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0; i<skill_trees.size(); i++)
        if(right_skillT(skill, skill_trees[i]))
            ++answer;
    return answer;
}
