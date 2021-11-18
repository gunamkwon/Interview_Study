#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm> 
#include <vector>
#include <cstring>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int cnt_one;
int check(int n) {
    int cur_cnt = 0;
    while (n >= 1) {
        if (n % 2 == 1) cur_cnt++;
        n /= 2;
    }
    return cur_cnt;
}

int solution(int n) {
    int answer = 0;
    cnt_one = check(n);
    int t = n + 1;
    while ( cnt_one != check(t)) {
        t++;
    }

    answer = t;
    return answer;
}