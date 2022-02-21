import java.util.*;

class Main
{
    private static final int L = 100001;
    private static int N,Q;
    private static Trunk[] trunks, sortedTrunks;
    private static int[][] quest;
    private static int[] group;
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        Q = sc.nextInt();

        trunks = new Trunk[L];
        sortedTrunks = new Trunk[L];
        quest = new int[L][3];
        group = new int[L];
        group[0] = 0;

        for(int i=0;i<N;i++){
            int sx = sc.nextInt();
            int ex = sc.nextInt();
            int y = sc.nextInt();

            trunks[i] = new Trunk(sx,ex,y,i+1);
        }

        mergeSort(0, N-1);

        for(int i=0;i<Q;i++){
            quest[i][0] = sc.nextInt();
            quest[i][1] = sc.nextInt();
        }

        frogJump();
    }

    private static void frogJump() {
        int groupNumber = 1;
        group[trunks[0].num] = groupNumber;
        int pivot = trunks[0].ex;

        for(int i=1;i<N;i++) {
            if(pivot >= trunks[i].sx) {
                if(pivot < trunks[i].ex) pivot = trunks[i].ex;
            }
            else {
                groupNumber++;
                pivot = trunks[i].ex;
            }
            group[trunks[i].num] = groupNumber;
        }


        for(int i=0;i<Q;i++){
            if(group[quest[i][0]] == group[quest[i][1]])
                System.out.println("1");
            else
                System.out.println("0");
        }
    }


    private static void mergeSort(int left, int right) {
        int mid;
        if(left < right) {
            mid = (left+right)/2;
            mergeSort(left,mid);
            mergeSort(mid+1,right);
            merge(left,mid,right);
        }
    }

    private static void merge(int left, int mid, int right) {
        int i = left;
        int j = mid+1;
        int k = left;

        while(i <= mid && j <= right){
            if(trunks[i].compareTo(trunks[j]) < 0) {
                sortedTrunks[k++] = trunks[i++];
            } else
                sortedTrunks[k++] = trunks[j++];
        }

        if(i > mid) {
            while(j <= right)
                sortedTrunks[k++] = trunks[j++];
        }
        else {
            while(i <= mid)
                sortedTrunks[k++] = trunks[i++];
        }

        for(i=left;i<=right;i++)
            trunks[i] = sortedTrunks[i];
    }

    private static class Trunk implements Comparable<Trunk>{
        int sx;
        int ex;
        int y;
        int num;

        public Trunk(int sx, int ex, int y, int num){
            this.sx = sx;
            this.ex = ex;
            this.y = y;
            this.num = num;
        }

        public int compareTo(Trunk t1){
            if(this.sx == t1.sx)
                return this.ex - t1.ex;
            else
                return this.sx - t1.sx;
        }
    }
}