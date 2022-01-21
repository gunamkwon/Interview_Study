
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main
{
    int N,M;

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        ArrayList<Integer> myList = new ArrayList<>();

        for(int i=0;i<N;i++){
            myList.add(sc.nextInt());
        }

        M = sc.nextInt();
        ArrayList<Integer> targetList = new ArrayList<>();
        for(int i=0;i<N;i++){
            targetList.add(sc.e)
        }

        System.out.println(moveDays);
    }

}


import java.util.LinkedList;
        import java.util.Queue;
        import java.util.Scanner;

class Main
{
    private static int N,L,R;
    private static int[][] peopleMap = new int[51][51];
    private static int[][] boundaryMap = new int[51][51];
    private static boolean[][] checkMap = new boolean[51][51];

    private static int[] dY = {0,0,1,0,-1};
    private static int[] dX = {0,1,0,-1,0};     // 동 남 서 북 == 2, 4, 8, 16

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();
        R = sc.nextInt();

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                peopleMap[i][j] = sc.nextInt();
            }
        }

        int moveDays = 0;
        while(true) {
            if(openBoundary()==0) break;
            peopleMove();
            moveDays++;
            closeBoundary();
        }

        System.out.println(moveDays);
    }

    private static void peopleMove() {
        for(int y=0;y<N;y++) {
            for(int x=0;x<N;x++) {
                if(boundaryMap[y][x] != 0 && checkMap[y][x] != true) {
                    BFS(y,x);
                }
            }
        }
    }

    private static void BFS(int y, int x) {
        int totalPeople = 0;
        LinkedList<Pair> locList= new LinkedList<>();
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(y,x));
        locList.add(new Pair(y,x));
        totalPeople += peopleMap[y][x];
        checkMap[y][x] = true;

        while(!q.isEmpty()){
            int cY = q.peek().y;
            int cX =  q.peek().x;
            q.remove();

            for(int i=1;i<=4;i++){
                int nY = cY + dY[i];
                int nX = cX + dX[i];

                if(nY < 0 || nY >= N || nX < 0 || nX >= N) continue;
                if(checkMap[nY][nX] == true || (boundaryMap[cY][cX] & 1<<i) == 0) continue;
                checkMap[nY][nX] = true;
                locList.add(new Pair(nY,nX));
                totalPeople += peopleMap[nY][nX];
                q.add(new Pair(nY,nX));
            }
        }

        for(Pair list: locList) {
            peopleMap[list.y][list.x] = totalPeople / locList.size();
        }
    }

    private static int openBoundary() {
        int boundaryCnt =0;
        for(int y=0;y<N;y++){
            for(int x=0;x<N;x++){
                for(int i=1;i<=4;i++){
                    int nextY = y+dY[i];
                    int nextX = x+dX[i];

                    if(nextY < 0 || nextY >=N || nextX < 0 || nextX >=N) continue;
                    int difPeople = Math.abs(peopleMap[y][x]-peopleMap[nextY][nextX]);
                    if(difPeople >= L && difPeople <= R) {
                        boundaryMap[y][x] |= 1<<i;
                        boundaryCnt++;
                    }
                }
            }
        }

        return boundaryCnt;
    }

    private static void closeBoundary() {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                boundaryMap[y][x] = 0;
                checkMap[y][x] = false;
            }
        }
    }

    static class Pair {
        int y;
        int x;
        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}