#include <string>
#include <vector>
using namespace std;

int maxDiff;
vector<int> answer(1, -1);

// 작은 점수에 더 많은 화살이 있는지
bool isBetter(vector<int>& ryan) {
    for (int i = 10; i >= 0; i--) {
        if (ryan[i] > answer[i]) return true;
        else if (ryan[i] < answer[i]) return false;
    }
}

// 점수 계산
void calcScore(vector<int>& ryan, vector<int>& apeach) {
    int ryanScore = 0, apeachScore = 0;
    for (int i = 0; i < 11; i++) {
        if (ryan[i] > apeach[i]) ryanScore += 10 - i;
        else if (apeach[i] > 0) apeachScore += 10 - i;
    }

    int diff = ryanScore - apeachScore;
    if (diff > 0 && diff >= maxDiff) {
        if (maxDiff == diff && !isBetter(ryan)) return;

        maxDiff = diff;
        answer = ryan;
    }
}

// 완전 탐색
void solve(int idx, int arrows, vector<int>& ryan, vector<int>& apeach) {
    if (idx == 11 || arrows == 0) {
        ryan[10] += arrows; // 남은 화살은 모두 0점 과녁에
        calcScore(ryan, apeach);
        ryan[10] -= arrows;
        return;
    }

    // 점수를 얻기로 결정
    if (apeach[idx] < arrows) {
        ryan[idx] += apeach[idx] + 1;
        solve(idx + 1, arrows - apeach[idx] - 1, ryan, apeach);
        ryan[idx] -= apeach[idx] + 1;
    }

    // 얻지 않기로 결정
    solve(idx + 1, arrows, ryan, apeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11, 0);
    solve(0, n, ryan, info);

    return answer;
}