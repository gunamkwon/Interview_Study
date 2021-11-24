#include <string>
#include <vector>

using namespace std;
#define MAX (int)(5000)
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i=3;i<=MAX;i++){
        for(int j=3;j<=i;j++){
            int total = i*j;
            int curBrown = i*2 + (j-2)*2;
            int curYellow = total - curBrown;
            
            if(brown == curBrown && yellow == curYellow){
                answer.push_back(i);
                answer.push_back(j);
            }
                
        }
    }
    return answer;
}

/* 硅况具 且 钱捞规过
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {

    int len = brown / 2 + 2;

    int w = len - 3;
    int h = 3;

    while(w >= h){
        if(w * h == (brown + red)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}
*/