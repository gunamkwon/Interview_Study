#include <string>
#include <vector>

#define MOD 1234567
using namespace std;

int dp[100001] = {0,};
int solution(int n) {
    int answer = 0;
    
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;    
    }
    answer = dp[n];
    return answer;
}