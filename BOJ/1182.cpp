#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;


int N, S;

vector<int> arr;
bool check[20];
int answer = 0;

int sumOf(vector<int> arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];

    return sum;
}

void subsequence(vector<int> now, int idx) {
    if (now.size() > 0 && sumOf(now)== S) {
        answer++;
    }

    for (int i = idx; i < arr.size(); i++) {
        if (check[i] == true) continue;
        check[i] = true;
        now.push_back(arr[i]);
        subsequence(now,i);
        now.pop_back();
        check[i] = false;
    }

}

int main() 
{
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    vector<int> now;
    subsequence(now, 0);
    cout << answer << endl;
}