import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static int N;
    private static int[][] squareMap = new int[101][101];
    private static ArrayList<DragonCurve> curveList = new ArrayList<>();
    private static int answer = 0;

    private static int[] d_x = {1, 0, -1, 0};
    private static int[] d_y = {0, -1, 0, 1};

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();

        for(int i=0;i<N;i++){
            int x,y,d,g;
            x = sc.nextInt();
            y = sc.nextInt();
            d = sc.nextInt();
            g = sc.nextInt();

            curveList.add(new DragonCurve(x,y,d,g));
        }

        checkCurve();
        countMap();

        System.out.println(answer);
    }

    private static void checkCurve()
    {
        for(DragonCurve curve: curveList) {
            // 배열 만들기
            ArrayList<Integer> curveDir = new ArrayList<>();
            curveDir.add(curve.dir);
            for(int i=1;i<=curve.gen;i++){
                int size = curveDir.size();
                for(int j=size-1;j>=0;j--){
                    int dir = (curveDir.get(j)+1>=4)? 0:curveDir.get(j)+1;
                    curveDir.add(dir);
                }
            }

            // 체크하기
            int x = curve.x;
            int y = curve.y;
            for(int i=0;i<curveDir.size();i++){
                int nx = x + d_x[curveDir.get(i)];
                int ny = y + d_y[curveDir.get(i)];

                squareMap[y][x] = 1;
                squareMap[ny][nx] = 1;

                x = nx;
                y = ny;
            }
        }
    }

    private static void countMap()
    {
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                if(squareMap[i][j] == 1 && squareMap[i][j+1]==1
                        && squareMap[i+1][j]==1 && squareMap[i+1][j+1]==1)
                    answer++;
            }
        }
    }
    static class DragonCurve {
        int x;
        int y;
        int dir;
        int gen;

        DragonCurve(int x,int y,int d,int g){
            this.x = x;
            this.y = y;
            this.dir = d;
            this.gen = g;
        }
    }
}
