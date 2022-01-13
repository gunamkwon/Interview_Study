#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(vector<int> arr, int lcm){
    for(int i=0;i<arr.size();i++){
        if(lcm % arr[i] != 0) return false;
    }

    return true;
}

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(),arr.end());
    int max = arr[arr.size()-1];
    cout << max;

    int cnt = 0;
    while(1){
        int lcm = max * (++cnt);

        if(check(arr,lcm)) break;
    }
    answer = max * cnt;
    return answer;
}
