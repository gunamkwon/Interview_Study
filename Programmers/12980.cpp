#include <iostream>
using namespace std;


int solution(int n)
{
    int ans = 0;
    
    int cnt = 0;
    while(n>=1){
        if(n % 2 == 0) n/=2;
        else {
            cnt+=1;
            n/=2;
        }
    }
    ans = cnt;
    return ans;
}