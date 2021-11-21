#include <string>
#include <vector>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
using namespace std;

string solution(string s) {
    string answer = "";
    int max = INT_MIN;
    int min = INT_MAX;

    while(s.find(" ") <= s.length() ){
        size_t p = s.find(" ");
        string ex_p = s.substr(0, p);
        s = s.substr(p+1);
        
        int cur = stoi(ex_p);
        if(max < cur) max = cur;
        if(min > cur) min = cur;
    }
            size_t p = s.find(" ");
        string ex_p = s.substr(0, p);
        s = s.substr(p+1);
        
        int cur = stoi(ex_p);
        if(max < cur) max = cur;
        if(min > cur) min = cur;
    
    answer += to_string(min);
    answer += ' ';
    answer += to_string(max);
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string sTemp = "";
    vector<int> vecInteger;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            vecInteger.push_back(stoi(sTemp));
            sTemp.clear();
            continue;
        }

        sTemp += s[i];
    }

    vecInteger.push_back(stoi(sTemp));

    sort(vecInteger.begin(), vecInteger.end());

    answer += to_string(vecInteger.front());
    answer += ' ';
    answer += to_string(vecInteger.back());

    return answer;
}
*/
/////////////////////////////////////////////////
/*
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string token;
    istringstream iss(s);
    vector<int> num;

    while(getline(iss, token, ' '))
    {
          num.push_back(stoi(token));
    }

    sort(num.begin(), num.end());

    answer = to_string(num.front()) + " " + to_string(num.back());

    return answer;
}
*/