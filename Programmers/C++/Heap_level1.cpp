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
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    while (pq.top() < K) {
        if (pq.size() < 2) {
            answer = -1;
            break;
        }

        answer++;

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + (second * 2));
    }

    return answer;
}
