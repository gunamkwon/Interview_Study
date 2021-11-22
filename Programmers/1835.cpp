#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

typedef struct {
    char cFir;
    char cSec;
    int n;
    int op;
}condition;
vector<char> character = { 'A','C','F','J','M','N','R','T' };
bool check[8] = { 0, };
vector<char> pos;
vector<condition> con;
int answer = 0;

bool checkCondition()
{
    for (int i = 0; i < con.size(); i++) {
        int first = find(pos.begin(), pos.end(), con[i].cFir) - pos.begin();
        int second = find(pos.begin(), pos.end(), con[i].cSec) - pos.begin();
        switch (con[i].op) {
        case 0:

            if (abs(first - second) - 1 != con[i].n)
                return false;
            break;
        case 1:
            if (abs(first - second) - 1 <= con[i].n)
                return false;
            break;
        case 2:
            if (abs(first - second) - 1 >= con[i].n)
                return false;
            break;
        }
    }

    return true;
}

void BFS(int idx, int cnt)
{
    if (cnt == 8) {
        if (checkCondition()) 
            answer++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (check[i] == true) continue;
        else {
            check[i] = true;
            pos.push_back(character[i]);
            BFS(i, cnt+1);
            check[i] = false;
            pos.pop_back();
        }
    }
}

void init(){
    pos.clear();
    con.clear();
    answer = 0;
    for(int i=0;i<8;i++){
        check[i] = false;
    }
}
int solution(int n, vector<string> data) {
    init();
    for (int i = 0; i < n; i++) {
        char cFir = data[i][0];
        char cSec = data[i][2];
        int n = data[i][4] - '0';
        if (data[i][3] == '=') con.push_back({ cFir,cSec,n,0});
        else if (data[i][3] == '>') con.push_back({ cFir,cSec,n,1 });
        else if (data[i][3] == '<') con.push_back({ cFir,cSec,n,2 });
    }
    BFS(0, 0);

    return answer;
}