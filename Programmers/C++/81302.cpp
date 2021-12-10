#include <string>
#include <vector>

using namespace std;

int dx[3][4] = { {0, 1, -1, 0},{0, 2, -2, 0},{1, -1, -1, 1} };
int dy[3][4] = { {1, 0, 0, -1},{2, 0, 0, -2},{1, -1, 1, -1} };


bool checkSeat(vector<string> place, int x, int y)
{
    for (int dis = 0; dis < 3; dis++) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[dis][i];
            int ny = y + dy[dis][i];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                //거리 1이면 무조건 X
                if (dis == 0 && place[nx][ny] == 'P')
                    return false;

                //거리 2면 확인
                if (dis == 1 && place[nx][ny] == 'P') {
                    int bx = x + dx[0][i];
                    int by = y + dy[0][i];
                    if (place[bx][by] == 'O') 
                        return false;
                }

                //대각선이면 확인
                if (dis == 2 && place[nx][ny] == 'P') {
                    if (i == 0) {
                        int bx1 = x + dx[0][0];
                        int by1 = y + dy[0][0];

                        int bx2 = x + dx[0][1];
                        int by2 = y + dy[0][1];

                        if (place[bx1][by1] == 'O' || place[bx2][by2] == 'O')
                            return false;
                    }
                    else if (i == 1) {
                        int bx1 = x + dx[0][3];
                        int by1 = y + dy[0][3];

                        int bx2 = x + dx[0][2];
                        int by2 = y + dy[0][2];

                        if (place[bx1][by1] == 'O' || place[bx2][by2] == 'O')
                            return false;
                    }
                    else if (i == 2) {
                        int bx1 = x + dx[0][0];
                        int by1 = y + dy[0][0];

                        int bx2 = x + dx[0][2];
                        int by2 = y + dy[0][2];

                        if (place[bx1][by1] == 'O' || place[bx2][by2] == 'O')
                            return false;
                    }
                    else if (i == 3) {
                        int bx1 = x + dx[0][1];
                        int by1 = y + dy[0][1];

                        int bx2 = x + dx[0][3];
                        int by2 = y + dy[0][3];

                        if (place[bx1][by1] == 'O' || place[bx2][by2] == 'O')
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

int checkCase(vector<string> place)
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (place[i][j] == 'P')
                if (!checkSeat(place, i, j))
                    return 0;
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < 5; i++) {
        answer.push_back(checkCase(places[i]));
    }

    return answer;
}