import java.util.*;
class Solution {
    private boolean[] checked;
    private int[] parent;
    private Node[] nodeList;

    public int solution(int n, int[][] costs) {
        int answer = 0;
        checked = new boolean[n];
        parent = new int[n];
        nodeList = new Node[costs.length];
        Arrays.fill(parent, -1);

        for(int i=0;i< costs.length;i++){
            int start = costs[i][0];
            int des = costs[i][1];
            int weight = costs[i][2];

            nodeList[i] = new Node(start,des,weight);
        }
        Arrays.sort(nodeList);

        for(int i=0;i < nodeList.length;i++){
            if(union(nodeList[i].start, nodeList[i].des)){
                answer += nodeList[i].weight;
            }

        }

        return answer;
    }

    private boolean union(int start, int des) {
        int rootA = find(start);
        int rootB = find(des);

        if(rootA != rootB){
            parent[rootB] = rootA;
            return true;
        }

        return false;
    }

    private int find(int start) {
        if(parent[start] < 0) return start;
        else return parent[start] = find(parent[start]);
    }

    public class Node implements Comparable<Node> {
        int start;
        int des;
        int weight;

        public Node(int start, int des, int weight) {
            this.start = start;
            this.des = des;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.weight,o.weight);
        }
    }
}