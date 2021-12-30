#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct mincompare {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

struct compare {
    bool operator()(const int& a, const int& b) {
        return a < b;
    }
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int, vector<int>, mincompare> minpq;
    priority_queue<int, vector<int>, compare> maxpq;

    for (int i = 0; i < operations.size(); i++) {
        size_t p = operations[i].find(' ');
        string cmd = operations[i].substr(0, p);
        int num = stoi(operations[i].substr(p + 1));

        if (cmd.compare("I") == 0) {
            if (minpq.empty() || maxpq.empty()) {
                if (maxpq.empty()) {
                    if(minpq.empty())
                        maxpq.push(num);
                    else {
                        if (num < minpq.top()) {
                            int temp = minpq.top();
                            minpq.pop();
                            minpq.push(num);
                            maxpq.push(temp);
                        }
                    }
                }
                else {
                    if (num > maxpq.top()) {
                        int temp = maxpq.top();
                        maxpq.pop();
                        maxpq.push(num);
                        minpq.push(temp);
                    }
                    else {
                        minpq.push(num);
                    }
                }
            }
            else {
                priority_queue<int, vector<int>, mincompare> tempMaxpq;
                priority_queue<int, vector<int>, compare> tempMinpq;

                //털기
                while (!maxpq.empty()) {
                    tempMaxpq.push(maxpq.top());
                    maxpq.pop();
                }
                while (!minpq.empty()) {
                    tempMinpq.push(minpq.top());
                    minpq.pop();
                }

                if (num > tempMaxpq.top()) {
                    if (tempMaxpq.size() >= tempMinpq.size()) {
                        int temp = tempMaxpq.top();
                        tempMaxpq.pop();
                        tempMinpq.push(temp);
                    }
                    tempMaxpq.push(num);

                }
                else if (num < tempMinpq.top()) {
                    if (tempMinpq.size() >= tempMaxpq.size()) {
                        int temp = tempMinpq.top();
                        tempMinpq.pop();
                        tempMaxpq.push(temp);
                    }
                    tempMinpq.push(num);
                }
                // 중간값
                else {
                    if (tempMaxpq.size() > tempMinpq.size()) tempMinpq.push(num);
                    else if (tempMaxpq.size() <= tempMinpq.size()) tempMaxpq.push(num);
                }


                //원상태
                while (!tempMaxpq.empty()) {
                    maxpq.push(tempMaxpq.top());
                    tempMaxpq.pop();
                }
                while (!tempMinpq.empty()) {
                    minpq.push(tempMinpq.top());
                    tempMinpq.pop();
                }
            }
        }
        else if (cmd.compare("D") == 0) {
            if (num == 1) {
                if (!maxpq.empty())
                    maxpq.pop();
                else if (!minpq.empty())
                    minpq.empty();
            }
            else {
                if (!minpq.empty())
                    minpq.pop();
                else if (!maxpq.empty())
                    maxpq.pop();
            }
        }
    }
    if (maxpq.empty()) {
        answer.push_back(0);
    }
    else {
        answer.push_back(maxpq.top());
    }
    if (minpq.empty()) {
        answer.push_back(0);
    }
    else {
        answer.push_back(minpq.top());
    }
    

    return answer;
}

int main()
{
    vector<string> operations;
    operations.push_back("I -45");
    operations.push_back("I 653");
    operations.push_back("D 1");
    operations.push_back("I -653");
    operations.push_back("I 45");
    operations.push_back("I 97");
    operations.push_back("D 1");
    operations.push_back("D -1");
    operations.push_back("I 333");
    solution(operations);
}