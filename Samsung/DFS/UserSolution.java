

public class UserSolution {

    LinkedList[] familyList = new LinkedList[100];
    boolean[] checked;
    public void dfs_init(int N, int[][] path) {
        for(int i=0;i<100;i++){
            familyList[i] = new LinkedList();
        }
        checked = new boolean[100];
        for(int i=0; i<N-1; i++){
            int parent = path[i][0];
            int child = path[i][1];
            familyList[parent].add(child);
        }
    }

    public int dfs(int N) {
        checked = new boolean[100];
        int[] stack = new int[1000];
        int sIdx = -1;
        stack[++sIdx] = N;
        checked[N] = true;

        while(sIdx>=0) {
            int curKing = stack[sIdx--];

            for(int i=0;i<familyList[curKing].size();i++){
                int nextKing = familyList[curKing].get(i);

                if(!checked[nextKing]) {
                    //System.out.println(nextKing);
                    if(nextKing > N) {
                        //System.out.println("return:" + nextKing);
                        return nextKing;
                    }
                    else {
                        stack[++sIdx] = curKing;
                        stack[++sIdx] = nextKing;
                        checked[nextKing] = true;
                        break;
                    }
                }
            }
        }
        //System.out.println("return:" + -1);
        return -1;
    }

    class LinkedList {
        Node head;
        int size;

        class Node {
            int value;
            Node next;

            Node(int value) {
                this.value = value;
                next = null;
            }
        }

        LinkedList() {
            head = new Node(-1);
            size = 0;
        }

        public void add(int value) {
            Node n = new Node(value);

            Node cur = head;
            while(cur.next!=null){
                cur = cur.next;
            }

            cur.next = n;
            size++;
        }

        public int get(int idx) {
            Node cur = head;
            for(int i=0;i<=idx;i++){
                cur = cur.next;
            }

            return cur.value;
        }

        public int size() {
            return this.size;
        }
    }
}