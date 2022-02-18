
import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.Arrays;


class Solution
{
    private static int N,M;
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
            M = Integer.parseInt(br.readLine());

            parent = new int[N];
            nodes = new Node[N];
            lines = new Node[M];


            for(int i=0;i<M;i++){
                String[] info = br.readLine().split(" ");
                lines[i] = new Node(Integer.parseInt(info[0])-1, Integer.parseInt(info[1])-1, Integer.parseInt(info[2]));
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

            System.out.println("#" + test_case + " " + Math.round(ans));
            /////////////////////////////////////////////////////////////////////////////////////////////
        }
    }

    private static class Node implements Comparable<Node>{
        int x,y;
        int cost;

        public Node(int x,int y,int cost){
            this.x = x;
            this.y = y;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return Long.compare(this.cost, o.cost);
        }
    }

    private static int find(int a){
        if(parent[a] < 0) return a;
        else return parent[a] = find(parent[a]);
    }

    private static boolean union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if(rootA != rootB){
            parent[rootB] = rootA;
            return true;
        }
        return false;
    }

}
