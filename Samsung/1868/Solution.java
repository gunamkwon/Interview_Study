import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
    private static int N;
    private static int[][] mineMap = new int[301][301];
    private static int[][] cntMap = new int[301][301];
    private static int answer = 0;

    private static int[] dy = { -1, -1, 0, 1, 1, 1, 0, -1};
    private static int[] dx = { 0, 1, 1, 1, 0, -1, -1, -1};

    public static void main(String args[]) throws Exception
    {
        System.setIn(new FileInputStream("res/input.txt"));

        Scanner sc = new Scanner(System.in);
        int T;
        T=sc.nextInt();


        for(int test_case = 1; test_case <= T; test_case++)
        {
            answer = 0;
            N = sc.nextInt();
            for(int i=0;i<N;i++){
                String temp = sc.next();
                for(int j=0;j<N;j++){
                    if(temp.charAt(j) == '.') {
                        mineMap[i][j] = 0;
                    } else {
                        mineMap[i][j] = 1;
                    }
                }
            }
            countMine();
            /////////////////////////////////////////////////////////////////////////////////////////////
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(mineMap[i][j]==0 && cntMap[i][j] == 0) {
                        click(i,j);
                        answer++;
                    }
                }
            }

            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(mineMap[i][j] == 0 && cntMap[i][j] > 0) {
                        click(i,j);
                        answer++;
                    }
                }
            }
            /////////////////////////////////////////////////////////////////////////////////////////////
            System.out.println("#" + test_case + " " + answer);
        }
    }

    private static void countMine() {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(mineMap[i][j]==0) {
                    int cnt = 0;
                    for(int d=0;d<8;d++){
                        int ny = i + dy[d];
                        int nx = j + dx[d];

                        if(ny < 0 || ny >= N || nx < 0 || nx >= N || mineMap[ny][nx] != 1 ) continue;
                        cnt++;
                    }

                    cntMap[i][j] = cnt;
                }
            }
        }
    }


    private static void click(int y, int x) {

        int now = cntMap[y][x];
        cntMap[y][x] = -1;

        if(now == 0) {
            for(int d=0;d<8;d++){
                int ny = y + dy[d];
                int nx = x + dx[d];

                if(ny < 0 || ny >= N || nx < 0 || nx >= N
                        || cntMap[ny][nx] == -1 ) continue;

                click(ny,nx);
            }
        }
    }
}