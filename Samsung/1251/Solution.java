
import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.Arrays;


class Solution
{
    private static int N;
    private static Node[] lines,nodes;
    private static int[] parent;

    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T;
        T= Integer.parseInt(br.readLine());


        for(int test_case = 1; test_case <= T; test_case++)
        {
            double ans = 0;
            N = Integer.parseInt(br.readLine());

            parent = new int[N];
            nodes = new Node[N];
            lines = new Node[N * N];

            String[] tmpX = br.readLine().split(" ");
            String[] tmpY = br.readLine().split(" ");

            for(int i=0;i<N;i++){
                nodes[i] = new Node(Integer.parseInt(tmpX[i]), Integer.parseInt(tmpY[i]));
            }

            double e = Double.parseDouble(br.readLine());

            int cnt = 0;
            for(int i =0;i<N;i++){
                for(int j=0;j<N;j++){
                    lines[cnt] = new Node(i,j);
                    lines[cnt++].cost = (long) (nodes[i].x - nodes[j].x) * (nodes[i].x - nodes[j].x)
                            + (long)(nodes[i].y - nodes[j].y) * (nodes[i].y - nodes[j].y);
                }
            }

            Arrays.sort(lines);
            Arrays.fill(parent, -1);
            /////////////////////////////////////////////////////////////////////////////////////////////
            for(int i=0;i<lines.length;i++){
                Node cur = lines[i];
                if(cur.cost == 0) continue;
                if(union(cur.x, cur.y)) {
                    ans += cur.cost;
                }
            }
            ans *= e;
            System.out.println("#" + test_case + " " + Math.round(ans));
            /////////////////////////////////////////////////////////////////////////////////////////////
        }
    }

    private static class Node implements Comparable<Node>{
        int x,y;
        long cost;

        public Node(int x,int y){
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Node o) {
            return Long.compare(this.cost, o.cost);
        }
    }

    private static int find(int a) {
        if(parent[a] < 0) return a;
        else return parent[a] = find(parent[a]);
    }

    private static boolean union(int a, int b){
        int rootA = find(a);
        int rootB = find(b);
        if(rootA != rootB){
            parent[rootB] = rootA;
            return true;
        }
        return false;
    }

}