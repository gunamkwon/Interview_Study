import java.util.*;

public class Solution {

    private static int[][] board;

    public static int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        board = new int[rows+1][columns+1];

        initBoard(rows,columns);

        for(int i=0;i< queries.length;i++){
            int y1 = queries[i][0];
            int x1 = queries[i][1];

            int y2 = queries[i][2];
            int x2 = queries[i][3];

            ArrayList<Integer> list = new ArrayList<>();
            int min = Integer.MAX_VALUE;

            // Collect
            for(int x=x1; x<x2; x++){
                list.add(board[y1][x]);
                min = Math.min(min, list.get(list.size()-1));
            }
            for(int y=y1;y<y2;y++){
                list.add(board[y][x2]);
                min = Math.min(min, list.get(list.size()-1));
            }
            for(int x=x2;x>x1;x--){
                list.add(board[y2][x]);
                min = Math.min(min, list.get(list.size()-1));
            }
            for(int y=y2;y>y1;y--){
                list.add(board[y][x1]);
                min = Math.min(min, list.get(list.size()-1));
            }

            // MOVE
            for(int x=x1+1; x<x2; x++){
                board[y1][x] = list.get(0);
                list.remove(0);
            }
            for(int y=y1;y<y2;y++){
                board[y][x2] = list.get(0);
                list.remove(0);
            }
            for(int x=x2;x>x1;x--){
                board[y2][x] = list.get(0);
                list.remove(0);
            }
            for(int y=y2;y>y1;y--){
                board[y][x1] = list.get(0);
                list.remove(0);
            }
            board[y1][x1] = list.get(0);

            answer[i] = min;
        }


        return answer;
    }

    private static void initBoard(int rows, int columns) {
        int num=1;
        for(int i=1;i<=rows;i++) {
            for(int j=1;j<=columns;j++) {
                board[i][j] = num++;
            }
        }
    }

    public static void main(String[] args) {

        int[][] ss = {{2,2,5,4}, {3,3,6,6,}, {5,1,6,3}};
        solution(6,6, ss);
    }
}
