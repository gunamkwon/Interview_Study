import java.util.*;

class Solution {

    public int[] solution(String msg) {
        HashMap<String,Integer> strMap = new HashMap<>();
        for(int i=0;i<26;i++){
            char ch = (char)('A' + i);
            strMap.put(ch + "", i+1);
        }
        int idx = 27;

        ArrayList<Integer> tempAnswer = new ArrayList<>();

        int cpos = 0;
        int end = 0;
        while(true){
            String cur = String.valueOf(msg.charAt(cpos));
            cpos++;

            while(strMap.containsKey(cur)) {

                if(cpos >= msg.length()) {
                    tempAnswer.add(strMap.get(cur));
                    end = 1;
                    break;
                }

                cur += String.valueOf(msg.charAt(cpos));
                cpos++;

            }

            if(end==1) break;
            strMap.put(cur, idx++);

            int value = 0;
            if(strMap.get(cur.substring(0, cur.length()-1)) != null)
                value = strMap.get(cur.substring(0, cur.length()-1));

            tempAnswer.add(value);
            cpos--;
        }

        int[] answer = new int[tempAnswer.size()];
        for(int i=0;i<answer.length;i++){
            answer[i] = tempAnswer.get(i);
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] answer = {20, 8, 1, 20, 27, 29, 9, 19, 33, 31, 30, 28, 20, 33, 14, 15, 39, 19, 41, 43, 36, 9, 39, 46, 38, 47, 34, 19, 36, 52, 45, 40, 42, 35, 38, 48, 62, 54, 51, 61, 53, 55, 66, 57, 44, 59, 64, 32, 49, 60, 29, 52, 76, 37, 32, 71, 43, 70, 47, 75, 73, 80, 43, 79, 56, 72, 84, 61, 86, 68, 81, 90, 69, 92, 72, 85, 63, 96, 89, 87, 91, 83, 101, 94, 103, 65, 97, 106, 99, 108, 50, 74, 111, 77, 66, 98, 81, 70, 93, 118, 117, 88, 33, 122, 116, 58, 127, 62, 127, 78, 114, 123, 100, 133, 95, 112, 105, 104, 132, 145, 87, 134, 130, 129, 137, 131, 82, 79, 148, 151, 150, 144, 153, 159, 102, 135, 121, 156, 159, 125, 75, 162, 113, 158, 124, 109, 126, 149, 67, 142, 146, 166, 155, 158, 174, 171, 140, 119, 128, 175, 120, 138, 152, 161, 174, 181, 139, 154, 141, 187, 143, 176, 165, 172, 167, 191, 164, 182, 194, 184, 136, 170, 193, 147, 86};
        int[] solu = sol.solution("THATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITIS");

        int i=0;
        for(i=0;i<answer.length;i++){
            if(answer[i] != solu[i]){
                System.out.println(i);
                break;
            }
        }
        System.out.println(i +" " + answer.length);
    }
}
