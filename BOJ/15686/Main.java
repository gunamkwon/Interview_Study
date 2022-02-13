import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    private static int N,M;
    private static int[][] TownMap = new int[51][51];
    private static boolean[] selected = new boolean[14];
    private static ArrayList<Position> homeList = new ArrayList<>();
    private static ArrayList<Position> chickenList = new ArrayList<>();

    private static int minDis = Integer.MAX_VALUE;


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        for(int i=0;i<N;i++){
            for(int j=0; j<N; j++) {
                TownMap[i][j] = sc.nextInt();
                if(TownMap[i][j] == 1)
                    homeList.add(new Position(i,j));
                else if(TownMap[i][j] == 2)
                    chickenList.add(new Position(i,j));
            }
        }

        ArrayList<Position> selectedList = new ArrayList<>();
        DFS(0, 0, selectedList);

        System.out.println(minDis);
    }

    private static void DFS(int idx, int count, ArrayList<Position> selectedList){
        if(count == M) {
            minDis = Math.min(minDis,getDis(selectedList));
            return;
        }

        for(int i=idx;i<chickenList.size();i++){
            if(selected[i]) continue;
            selected[i] = true;
            selectedList.add(chickenList.get(i));
            DFS(i, count+1, selectedList);
            selectedList.remove(selectedList.size()-1);
            selected[i] = false;
        }
    }

    private static int getDis(ArrayList<Position> selectedChicken)
    {
        int ret = 0;
        for(int i=0; i<homeList.size(); i++){
            Position curHome = homeList.get(i);
            int minD = Integer.MAX_VALUE;
            for(int j=0;j<M;j++){
                minD = Math.min(minD,
                        Math.abs(curHome.r - selectedChicken.get(j).r) + Math.abs(curHome.c - selectedChicken.get(j).c));
            }
            ret += minD;
        }

        return ret;
    }

    private static class Position {
        private int r;
        private int c;

        public Position(int r, int c){
            this.r = r;
            this.c = c;
        }
    }
}
