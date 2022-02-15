import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Queue;

class UserSolution {

    private int map_size;
    private int[][] bfsMap = new int[11][11];
    private boolean[][] checked = new boolean[11][11];

    private int[] d_y = { 0, 1, 0, -1 };
    private int[] d_x = { 1, 0 ,-1, 0 };

    void bfs_init(int map_size, int map[][]) {
        this.map_size = map_size;

        for(int i=1;i<=map_size;i++){
            for(int j=1;j<=map_size;j++){
                bfsMap[i][j] = map[i-1][j-1];
            }
        }


    }

    int bfs(int x1, int y1, int x2, int y2) {
        checked = new boolean[11][11];
        Queue queue = new Queue();
        queue.add(y1,x1,0);
        checked[y1][x1] = true;


        while(!queue.empty()) {
            Queue.Node cur = queue.peek();
            queue.remove();
            if(cur.y == y2 && cur.x == x2){
                return cur.time;
            }

            for(int d=0;d<4;d++){
                int nY = cur.y + d_y[d];
                int nX = cur.x + d_x[d];

                if(nY > 0 && nY <= map_size && nX > 0 && nX <= map_size){
                    if(checked[nY][nX] || bfsMap[nY][nX] == 1) continue;
                    checked[nY][nX] = true;
                    queue.add(nY,nX,cur.time+1);
                }
            }
        }

        return -1;
    }

    public class Queue {
        private Node first = null;
        private Node last = null;

        public class Node {
            int y;
            int x;
            int time;
            private Node next;

            public Node(int y, int x, int time){
                this.y = y;
                this.x = x;
                this.time = time;
                next = null;
            }
        }


        public void add(int y,int x, int time) {
            Node n = new Node(y,x,time);
            if(last != null) {
                last.next = n;
            }
            last = n;

            if(first == null){
                first = last;
            }
        }

        public Node remove() {
            if(first == null)
                throw new NoSuchElementException();

            Node data = first;
            first = first.next;
            if(first == null)
                last = null;

            return data;
        }

        public Node peek() {
            if(first == null)
                throw new NoSuchElementException();

            return first;
        }

        public boolean empty() {
            return first == null;
        }
    }
}
