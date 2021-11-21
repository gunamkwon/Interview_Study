#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm> 
#include <vector>
#include <cstring>
#include <stdio.h>
#include <map>
using namespace std;

long long solution(int w, int h) {
    long long answer = 0;

    for (long long i = 1; i <= w; i++) {
        long long temp = ((double)h * i / w > h * i / w && (double)h * i / w < h* i / w + 1) ? (h * i / w) + 1 : (h * i / w);
        answer += h - temp;
    }
    answer *= 2;
    return answer;
}

int main()
{
    cout << solution(8, 12) << endl;
}