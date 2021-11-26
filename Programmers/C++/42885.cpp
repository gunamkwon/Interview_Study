#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int& a, int& b) {
    return a > b;
}
int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dPeople;
    for (int i = 0; i < people.size(); i++) {
        dPeople.push_back(people[i]);
    }
    sort(dPeople.begin(), dPeople.end(), cmp);

    while (!dPeople.empty()) {
        answer++;
        cout << dPeople.front() << ' ' << dPeople.back() << endl;
        if (dPeople.size() == 1) {
            dPeople.pop_front();
            continue;
        }
        if (dPeople.front() + dPeople.back() > limit) {
            dPeople.pop_front();
        }
        else {
            dPeople.pop_front();
            dPeople.pop_back();
        }
    }
    return answer;
}