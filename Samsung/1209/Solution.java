/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// double b;
// char g;
// String var;
// long AB;
// a = sc.nextInt();                           // int 변수 1개 입력받는 예제
// b = sc.nextDouble();                        // double 변수 1개 입력받는 예제
// g = sc.nextByte();                          // char 변수 1개 입력받는 예제
// var = sc.next();                            // 문자열 1개 입력받는 예제
// AB = sc.nextLong();                         // long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// double b = 1.0;
// char g = 'b';
// String var = "ABCDEFG";
// long AB = 12345678901234567L;
//System.out.println(a);                       // int 변수 1개 출력하는 예제
//System.out.println(b); 		       						 // double 변수 1개 출력하는 예제
//System.out.println(g);		       						 // char 변수 1개 출력하는 예제
//System.out.println(var);		       				   // 문자열 1개 출력하는 예제
//System.out.println(AB);		       				     // long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
import java.util.Arrays;
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
    public static void main(String args[]) throws Exception
    {
        System.setIn(new FileInputStream("res/input.txt"));

        Scanner sc = new Scanner(System.in);
        /*int T;
        T=sc.nextInt();*/

        for(int test_case = 1; test_case <= 10; test_case++)
        {
            int tc = sc.nextInt();
            int maxValue = 0;
            int[][] arr = new int[100][100];
            /////////////////////////////////////////////////////////////////////////////////////////////
            for(int i=0;i<100;i++){
                for(int j=0;j<100;j++){
                    arr[i][j] = sc.nextInt();
                }
            }

            maxValue = getSum(arr);
            /////////////////////////////////////////////////////////////////////////////////////////////
            System.out.println("#"+ tc + " " + maxValue);
        }
    }

    private static int getSum(int[][] arr) {
        int[] sumOfRowAndColAndDia = new int[202];
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                sumOfRowAndColAndDia[i] += arr[j][i];
                sumOfRowAndColAndDia[i+100] += arr[i][j];
            }
        }
        for(int j=0;j<100;j++) {
            sumOfRowAndColAndDia[200] += arr[j][j];
            sumOfRowAndColAndDia[201] += arr[j][99-j];
        }

        Arrays.sort(sumOfRowAndColAndDia);
        int maxSum = sumOfRowAndColAndDia[201];
        return maxSum;
    }
}