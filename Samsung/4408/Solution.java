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
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
    private static int studentNum;
    private static int[] room = new int[201];
    public static void main(String args[]) throws Exception
    {
        //System.setIn(new FileInputStream("res/input.txt"));

        Scanner sc = new Scanner(System.in);
        int T;
        T=sc.nextInt();

        for(int test_case = 1; test_case <= T; test_case++)
        {
            int[] room = new int[201];
            int answer =0;
            studentNum = sc.nextInt();
            for(int i=0;i<studentNum;i++){
                int a = sc.nextInt();
                if(a%2==1) a++;
                int b = sc.nextInt();
                if(b%2==1) b++;

                StudentRoomPos student = new StudentRoomPos(a/2,b/2);

                for(int j=student.cur;j<=student.target;j++){
                    room[j]++;
                }
            }

            /////////////////////////////////////////////////////////////////////////////////////////////

            /////////////////////////////////////////////////////////////////////////////////////////////
            for(int i=1;i<=200;i++){
                answer = Integer.max(answer,room[i]);
            }
            System.out.println("#"+test_case + " " + answer);
        }
    }

    public static class StudentRoomPos {
        int cur;
        int target;

        StudentRoomPos(int a, int b){
            if(a<b) {
                cur = a;
                target = b;
            } else {
                target = a;
                cur = b;
            }

        }
    }
}