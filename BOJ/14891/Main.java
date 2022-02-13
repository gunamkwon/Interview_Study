import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    private static int K;
    private static int[][] gear = new int[4][8];
    private static int answer = 0;

    private static final int TOP_POS = 0;
    private static final int RIGHT_POS = 2;
    private static final int LEFT_POS = 6;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for(int i=0;i<4;i++){
            String gears = sc.next();
            for(int j=0; j<8; j++) {
                gear[i][j] = gears.charAt(j) - '0';
            }
        }

        K = sc.nextInt();
        for(int i=0;i<K;i++){
            int num = sc.nextInt();
            int dir = sc.nextInt();

            rotate(num, dir);
        }

        for(int i=0;i<4;i++){
            int score = 0;
            if(i==0) score = 1;
            else if(i==1) score = 2;
            else if(i==2) score = 4;
            else if(i==3) score = 8;

            answer += gear[i][TOP_POS] * score;
        }

        System.out.println(answer);
    }

    private static void deepCopy(int [][] des){
        for(int i=0;i<4;i++){
            for(int j=0; j<8; j++) {
                des[i][j] = gear[i][j];
            }
        }
    }

    private static void rotate(int num, int dir) {
        int[][] originGear = new int[4][8];
        deepCopy(originGear);

        int idx = num-1;
        if(idx == 0) {
            if(originGear[idx][RIGHT_POS] != originGear[idx+1][LEFT_POS]){
                int ndir =( dir > 0)? -1:1;
                shiftGear(idx+1, ndir);
                if(originGear[idx+1][RIGHT_POS] != originGear[idx+2][LEFT_POS]){
                    shiftGear(idx+2,dir);
                    if(originGear[idx+2][RIGHT_POS] != originGear[idx+3][LEFT_POS]){
                        shiftGear(idx+3,ndir);
                    }
                }
            }
        } else if(idx==1) {
            // 좌 체크
            if(originGear[idx-1][RIGHT_POS] != originGear[idx][LEFT_POS]){
                int ndir = ( dir > 0)? -1:1;
                shiftGear(idx-1,ndir);
            }
            // 우 체크
            if(originGear[idx][RIGHT_POS] != originGear[idx+1][LEFT_POS]){
                int ndir = (dir>0)? -1:1;
                shiftGear(idx+1,ndir);
                if(originGear[idx+1][RIGHT_POS] != originGear[idx+2][LEFT_POS])
                    shiftGear(idx+2,dir);
            }
        } else if (idx ==2) {
            if(originGear[idx-1][RIGHT_POS] != originGear[idx][LEFT_POS]){
                int ndir = ( dir > 0)? -1:1;
                shiftGear(idx-1,ndir);
                if(originGear[idx-2][RIGHT_POS] != originGear[idx-1][LEFT_POS])
                    shiftGear(idx-2,dir);
            }
            if(originGear[idx][RIGHT_POS] != originGear[idx+1][LEFT_POS]){
                int ndir = ( dir > 0)? -1:1;
                shiftGear(idx+1,ndir);
            }
        } else if(idx==3){
            if(originGear[idx-1][RIGHT_POS] != originGear[idx][LEFT_POS]){
                int ndir = ( dir > 0)? -1:1;
                shiftGear(idx-1,ndir);
                if(originGear[idx-2][RIGHT_POS] != originGear[idx-1][LEFT_POS]){
                    shiftGear(idx-2,dir);
                    if(originGear[idx-3][RIGHT_POS] != originGear[idx-2][LEFT_POS]){
                        shiftGear(idx-3,ndir);
                    }
                }
            }
        }

        shiftGear(idx,dir);
    }

    private static void shiftGear(int idx, int dir) {
        int[][] tempGear = new int[4][8];
        deepCopy(tempGear);

        if(dir == 1){
            for(int i=0;i<8;i++){
                if(i==0)
                    gear[idx][i] = tempGear[idx][7];
                else gear[idx][i] = tempGear[idx][i-1];
            }
        } else {
            for(int i=0;i<8;i++){
                if(i==7)
                    gear[idx][i] = tempGear[idx][0];
                else gear[idx][i] = tempGear[idx][i+1];
            }
        }
    }
}
