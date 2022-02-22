
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;


class Solution {

    private static String[] words, sortedWords;
    private static int T, N;
    private static HashSet<String> set;

    public static void main(String args[]) throws Exception {
        //System.setIn(new FileInputStream("res/input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {

            N = Integer.parseInt(br.readLine());

            words = new String[N];
            sortedWords = new String[N];

            for (int i = 0; i < N; i++) {
                words[i] = br.readLine();
            }

            mergeSort(0, N-1);



            System.out.println("#"+test_case);
            System.out.println(words[0]);
            for (int i = 1; i < N; i++) {
                if(words[i].compareTo(words[i-1]) !=0)
                    System.out.println(words[i]);
            }
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
            if(words[i].length() < words[j].length()){
                sortedWords[k++] = words[i++];
            } else if(words[i].length() == words[j].length()){
                if(words[i].compareTo(words[j]) < 0)
                    sortedWords[k++] = words[i++];
                else
                    sortedWords[k++] = words[j++];
            } else {
                sortedWords[k++] = words[j++];
            }
        }

        if(i > mid) {
            while(j <= right) {
                sortedWords[k++] = words[j++];
            }
        }
        else {
            while(i <= mid)
                sortedWords[k++] = words[i++];
        }

        for(i= left;i<=right;i++)
            words[i] = sortedWords[i];
    }
}