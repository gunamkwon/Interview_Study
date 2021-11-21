#include <string>
#include <vector>

using namespace std;

// Problem 1
vector<int> solution(long long n) {
    vector<int> answer;
    while(n>=1){
        answer.push_back(n%10);
        n /= 10;
    }

    return answer;
}

// Problem 2
int month[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
string day[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};

string solution(int a, int b) {
    string answer = "";
    int day_cnt = b;

    for(int i=1;i < a;i++){
        day_cnt += month[i];
    }
    cout << day_cnt << endl;
    answer = day[ (day_cnt-1) % 7 ];
    return answer;
}