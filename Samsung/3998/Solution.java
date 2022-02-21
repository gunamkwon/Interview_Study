
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution {

    private static long[] A, sortedA;
    private static int T, N;
    private static long answer;

    public static void main(String args[]) throws Exception {
        //System.setIn(new FileInputStream("res/input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {

            N = Integer.parseInt(br.readLine());

            A = new long[N+1];
            sortedA = new long[N+1];
            answer = 0;

            String[] nums = br.readLine().split(" ");
            for (int i = 0; i < N; i++) {
                A[i+1] = Integer.parseInt(nums[i]);
            }

            mergeSort(1, N);


            System.out.println("#"+test_case + " " + answer);
        }
    }

    private static void mergeSort(int left,int right)
    {
        if(left < right){
            int mid = (left + right) / 2;
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
            if(A[i] < A[j])
                sortedA[k++] = A[i++];
            else {
                answer += (mid - i + 1);
                sortedA[k++] = A[j++];
            }
        }

        if(i > mid) {
            while(j <= right) {
                answer += (mid - i + 1);
                sortedA[k++] = A[j++];
            }
        }
        else {
            while(i <= mid)
                sortedA[k++] = A[i++];
        }

        for(i=left;i<=right;i++)
            A[i] = sortedA[i];
    }
}