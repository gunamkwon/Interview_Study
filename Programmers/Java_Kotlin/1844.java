import java.util.*;

public class Solution {

    private boolean[][] check;

    private int[] d_y = {1,0,-1,0};
    private int[] d_x = {0,1,0,-1};


    public int solution(int[][] maps) {
        int answer = 0;
        int N = maps.length;
        int M = maps[0].length;
        check = new boolean[N][M];

        ArrayList<Pair> queue = new ArrayList<>();
        queue.add(new Pair(0,0,1));

        while(!queue.isEmpty()) {
            Pair cur = queue.get(0);
            queue.remove(0);

            if(cur.y == N-1 && cur.x == M-1) {
                answer = cur.s;
                break;
            }

            for(int i=0;i<4;i++){
                int ny = cur.y + d_y[i];
                int nx = cur.x + d_x[i];

                if(ny >= 0 && ny < N && nx >= 0 && nx < M){
                    if(maps[ny][nx] == 0 || check[ny][nx]) continue;
                    check[ny][nx]= true;
                    queue.add(new Pair(ny,nx,cur.s+1));
                }
            }
        }
        if(answer == 0) return -1;
        else return answer;
    }

    class Pair {
        int y;
        int x;
        int s;

        public Pair(int y,int x, int s){
            this.y = y;
            this.x = x;
            this.s = s;
        }
    }
}
