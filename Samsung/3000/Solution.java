
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
    public static void main(String args[]) throws Exception
    {
        System.setIn(new FileInputStream("res/input.txt"));

        Scanner sc = new Scanner(System.in);
        int T;
        T=sc.nextInt();

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if(o1 < o2)
                    return 1;
                else
                    return -1;
            }
        });

        PriorityQueue<Integer> minHeap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if(o1 < o2)
                    return -1;
                else
                    return 1;
            }
        });

        for(int test_case = 1; test_case <= T; test_case++)
        {
            long answer = 0;
            maxHeap.clear();
            minHeap.clear();

            int N = sc.nextInt();
            int A = sc.nextInt();
            maxHeap.add(A);
            /////////////////////////////////////////////////////////////////////////////////////////////

            for(int i=0; i<N; i++) {

                for(int j=0;j<2;j++){
                    int num = sc.nextInt();
                    if(minHeap.isEmpty()) {
                        if(maxHeap.peek() > num) {
                            minHeap.add(maxHeap.poll());
                            maxHeap.add(num);
                        } else {
                            minHeap.add(num);
                        }

                        continue;
                    }
                    if(num < minHeap.peek()) maxHeap.add(num);
                    else minHeap.add(num);

                    makeHeapBalance(maxHeap,minHeap);
                }

                int middle = (maxHeap.size() > minHeap.size())? maxHeap.peek() : minHeap.peek();
                answer += middle;
                answer %= 20171109;

            }

            /////////////////////////////////////////////////////////////////////////////////////////////
            System.out.print("#" + test_case + " " + answer);
            System.out.println();
        }
    }

    private static void makeHeapBalance(PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap) {
        if(Math.abs(maxHeap.size() - minHeap.size()) == 1 ) return;
        else if(maxHeap.size() - 1 < minHeap.size()) {
            int cnt = minHeap.size() - (maxHeap.size()-1);
            while(--cnt>0){
                maxHeap.add(minHeap.remove());
            }
        } else {
            int cnt = maxHeap.size() - minHeap.size();
            while(--cnt>0){
                minHeap.add(maxHeap.remove());
            }
        }
    }
}
