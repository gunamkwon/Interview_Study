#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
bool check(int start, string s){
    stack<char> ch;
    for(int i=0; i<s.length(); i++){
        
        if(s[start] == '(' || s[start] == '[' || s[start] == '{')
            ch.push(s[start]);
        else if(s[start] == ')' || s[start] == ']' || s[start] == '}'){
            if(ch.empty()) return false;
            if(s[start] == ')') {
                if(ch.top() == '(') {
                    ch.pop();
                }
                else return false;
            }
            if(s[start]== ']') {
                if(ch.top() == '[') {
                    ch.pop();
                }
                else return false;
            }
            if(s[start] == '}') {
                if(ch.top() == '{') {
                    ch.pop();
                }
                else return false;
            }
        }
        if(++start >= s.length()) start = 0;
    }
    if(!ch.empty()) return false;
    return true;
}
int solution(string s) {
    int answer = 0;
        
    for(int start=0; start<s.length(); start++){
        if(check(start,s) == true) {
            answer++;
        }
    }
    
    return answer;
}