
import java.util.*;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] myList = new long[N];
        for(int i=0;i<N;i++){
            myList[i] = sc.nextLong();
        }

        Arrays.sort(myList);

        int M = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<M;i++){
            int ans = 0;
            long num = sc.nextLong();
            int left = 0;
            int right = N-1;
            while(left <= right) {
                int mid = (left+right)/2;
                if(myList[mid] > num){
                    right = mid - 1;
                    ans = 0;
                } else if(myList[mid] < num) {
                    left = mid + 1;
                    ans = 0;
                } else {
                    ans = 1;
                    break;
                }
            }
            sb.append(ans + " ");
        }
        System.out.print(sb);
            /*if(isHave(0, myList.length-1, num, myList))
                System.out.print(1 + " ");
            else
                System.out.print(0 + " ");*/
    }

/*    private static boolean isHave(int start, int end, long num, long[] myList) {
        int mid;

        while(start <= end) {
            mid = (start + end) / 2;
            if(num > myList[mid])
                start = mid + 1;
            else if(num < myList[mid])
                end = mid-1;
            else
                return true;
        }
        return false;
    }*/
}