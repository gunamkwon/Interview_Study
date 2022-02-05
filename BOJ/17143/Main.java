import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    private static int R,C,M;
    private static ArrayList<Integer>[][] sharkMap = new ArrayList[101][101];
    private static ArrayList<Shark> sharkList = new ArrayList<Shark>();

    private static int[] d_r = {0, -1, 1, 0, 0};
    private static int[] d_c = {0, 0, 0, 1, -1};
    private static int answer = 0;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        R = sc.nextInt();
        C = sc.nextInt();
        M = sc.nextInt();

        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                sharkMap[i][j] = new ArrayList<>();
            }
        }

        for(int i=0;i<M;i++) {
            int r,c,s,d,z;
            r = sc.nextInt();
            c = sc.nextInt();
            s = sc.nextInt();
            d = sc.nextInt();
            z = sc.nextInt();

            sharkList.add(new Shark(r,c,s,d,z));
            sharkMap[r][c].add(i);
        }

        for(int pos=1; pos<=C; pos++) {
            catchShark(pos);
            moveShark();
        }

        System.out.println(answer);
    }

    private static void moveShark()
    {
        for(int i=0;i< sharkList.size();i++) {
            Shark shark = sharkList.get(i);
            if(!shark.live) continue;
            int r = shark.r;
            int c = shark.c;
            sharkMap[r][c].remove(0);

            // 상어 위치 수정
            // 일단 (R-1) *2 의 나머지로 최대 움직이는 칸(그 이상은 동일)
            int mr = Math.abs( (shark.speed * d_r[shark.dir]) % ((R-1) *2) );
            int mc = Math.abs( (shark.speed * d_c[shark.dir]) % ((C-1) *2) );

            int nr = r;
            int nc = c;

            while(mr-->0 || mc-->0) {
                if (!inRange(nr + d_r[shark.dir], nc + d_c[shark.dir])) {
                    shark.dir = changeDir(shark.dir);
                }
                nr += d_r[shark.dir];
                nc += d_c[shark.dir];
            }
            sharkList.get(i).r = nr;
            sharkList.get(i).c = nc;
            sharkMap[nr][nc].add(i);
        }

        eatShark();
    }

    private static int changeDir(int dir) {
        switch (dir) {
            case 1:
                dir=2;
                break;
            case 2:
                dir=1;
                break;
            case 3:
                dir=4;
                break;
            case 4:
                dir=3;
                break;
        }

        return dir;
    }

    private static boolean inRange(int r, int c) {
        if(r >=1 && r <= R && c>=1 && c <= C) return true;
        else return false;
    }

    private static void eatShark() {
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                // 겹치면 제일 Size 큰놈 찾기
                if(sharkMap[i][j].size() >= 2) {
                    int maxSize = -1;
                    int maxSizeIdx = -1;
                    for(int s = 0; s<sharkMap[i][j].size();s++){
                        Shark curShark = sharkList.get(sharkMap[i][j].get(s));
                        if(maxSize < curShark.size){
                            maxSize = curShark.size;
                            maxSizeIdx = sharkMap[i][j].get(s);
                        }
                    }

                    // 죽음 표시
                    for(int s = 0; s<sharkMap[i][j].size();s++){
                        if(sharkMap[i][j].get(s) != maxSizeIdx) {
                            sharkList.get(sharkMap[i][j].get(s)).live = false;
                        }
                    }
                    // 제일 큰놈만
                    sharkMap[i][j].clear();
                    sharkMap[i][j].add(maxSizeIdx);
                }
            }
        }
    }

    private static void catchShark(int pos)
    {
        for(int i=1;i<=R;i++){
            if(!sharkMap[i][pos].isEmpty()) {
                Shark target = sharkList.get(sharkMap[i][pos].get(0));
                answer += target.size;
                target.live = false;
                sharkMap[i][pos].remove(0);
                break;
            }
        }
    }



    private static class Shark {
        int r;
        int c;
        int speed;
        int dir;
        int size;
        boolean live;

        public Shark(int r,int c, int speed, int dir, int size){
            this.r = r;
            this.c = c;
            this.speed = speed;
            this.dir = dir;
            this.size = size;
            this.live = true;
        }
    }
}
