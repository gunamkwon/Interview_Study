
import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.Arrays;


class Solution
{
    private static final int MAX_DAYS = 2000001;

    private static boolean[] studyDays;
    private static int T, N, P, last;
    private static int max = 0;
    public static void main(String args[]) throws Exception
    {
        //System.setIn(new FileInputStream("res/input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {
            String[] data = br.readLine().split(" ");

            N = Integer.parseInt(data[0]);
            P = Integer.parseInt(data[1]);

            studyDays = new boolean[MAX_DAYS];

            String[] days = br.readLine().split(" ");

            for(String day: days){
                int d = Integer.parseInt(day);
                studyDays[d] = true;
                last = Math.max(last,d);
            }
            max = P+1;
            countDays();

            StringBuilder sb = new StringBuilder();
            sb.append("#"+test_case+" "+ max);
            System.out.println(sb);
        }
    }

    private static void countDays()
    {
        int s = 1;
        int e = 1;
        int num = 0;
        while(e < last+1) {
            if(studyDays[e]) {
                num++;
                e++;
                max = Math.max(max,num);
            }
            else {
                if(P==0){
                    max = Math.max(max,num);
                    if(!studyDays[s]) P++;
                    s++;
                    num--;
                }
                else {
                    P--;
                    num++;
                    e++;
                }
            }
        }
    }
}