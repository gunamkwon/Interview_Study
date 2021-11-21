#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm> 
#include <vector>
#include <cstring>
#include <stdio.h>
#include <map>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int size;
int answer = -1;
vector<int> v;
bool selected[8];

int getCount(vector<int> v, int k, vector<vector<int>> dungeons)
{
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (k < dungeons[v[i]][0]) break;
        k -= dungeons[v[i]][1];
        cnt++;
    }

    return cnt;
}

void DFS(int cnt, vector<vector<int>> dungeons, int k)
{
    if (cnt == dungeons.size()) {
        int num = getCount(v, k, dungeons);
        answer = max(answer, num);
    }

    for (int i = 0; i < dungeons.size(); i++) {
        if (selected[i] == true) continue;
        selected[i] = true;
        v.push_back(i);
        DFS(cnt + 1, dungeons, k);
        v.pop_back();
        selected[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    DFS(0, dungeons, k);
    return answer;
}

int main()
{
    int k = 80;
    vector<vector<int>> dungeons;

    dungeons.push_back({ 80,20 });
    dungeons.push_back({ 50,40 });
    dungeons.push_back({ 30,10 });

    cout << solution(k, dungeons) << endl;
}