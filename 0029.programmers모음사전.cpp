//mentoring 29. 2021.12.24
//백트레킹 응용

#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int w_on_bridge = 0;
    vector<int> t_on_bridge;

    while (true) {
        if ((truck_weights.size() == 1) && ((truck_weights[0] + w_on_bridge) <= weight)) {
            answer += (bridge_length + 1);
            return answer;
        }

        if ((truck_weights[0] + w_on_bridge) > weight)
            t_on_bridge.push_back(0);
        else {
            t_on_bridge.push_back(truck_weights[0]);
            w_on_bridge += truck_weights[0];
            truck_weights.erase(truck_weights.begin());
        }

        if (t_on_bridge.size() == bridge_length) {
            w_on_bridge -= t_on_bridge[0];
            t_on_bridge.erase(t_on_bridge.begin());
        }
        answer++;
    }
    return answer;
}
