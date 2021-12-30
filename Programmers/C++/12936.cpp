#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long factorial(int n) {
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    long long slice, now = 0;

    // 초기화
    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i);


    while (1) {
        if (n == 0)
            break;

        // 팩토리얼 계산
        slice = factorial(n) / n;
        now = int((k - 1) / slice);

        // 와야할 숫자index 통해 알 수 있음
        answer.push_back(v[now]);
        v.erase(v.begin() + now);

        // 다음 숫자 결정
        n--;
        k %= slice;
        if (k == 0)
            k = slice;
    }

    return answer;
}