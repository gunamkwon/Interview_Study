#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string trans(int temp, int n) {
    string ret;
    if (temp == 0) return "0";
    if (temp == 1) return "1";
    while (temp >= 1) {
        int remainder = temp % n;
        string remainStr;
        switch (remainder) {
        case 10:
            remainStr = 'A';
            break;
        case 11:
            remainStr = 'B';
            break;
        case 12:
            remainStr = 'C';
            break;
        case 13:
            remainStr = 'D';
            break;
        case 14:
            remainStr = 'E';
            break;
        case 15:
            remainStr = 'F';
            break;
        default:
            remainStr = to_string(remainder);
            break;
        }
        ret += remainStr;
        temp /= n;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    int cnt=0;
    string temp;
    for(int i=0;i<t*m;i++){
        temp += trans(i,n);
    }
    
    for(int i=p-1;i<temp.length(),cnt<t;i+=m){
        answer += temp[i];
        cnt++;
    }

    return answer;
}