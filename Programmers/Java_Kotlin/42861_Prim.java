import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Queue;


class Solution {
    private boolean[] checked;
    private ArrayList<Node>[] nodeList = new ArrayList[101];


    public int solution(int n, int[][] costs) {
        for(int i=0;i<n;i++){
            nodeList[i] = new ArrayList<>();
        }

        for(int i=0;i< costs.length;i++){
            int start = costs[i][0];
            int des = costs[i][1];
            int weight = costs[i][2];

            nodeList[start].add(new Node(des,weight));
            nodeList[des].add(new Node(start,weight));
        }
        int answer = Integer.MAX_VALUE;

        for(int i=0;i<1;i++){
            answer = Math.min(answer, prim(i,n));
        }


        return answer;
    }

    private int prim(int start,int n) {
        int total = 0;
        checked = new boolean[n];
        Queue<Node> queue = new PriorityQueue<>();
        queue.add(new Node(start,0));

        while(!queue.isEmpty()) {
            Node cur = queue.poll();
            int node = cur.to;
            int weight = cur.weight;

            if(checked[node]) continue;
            checked[node] = true;
            total += weight;

            for(Node next: nodeList[node]){
                if(!checked[next.to])
                    queue.add(next);
            }
        }
        return total;
    }

    public class Node implements Comparable<Node> {
        int to;
        int weight;

        public Node(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.weight,o.weight);
        }
    }
}