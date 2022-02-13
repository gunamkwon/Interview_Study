import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
    public static void main(String args[]) throws Exception
    {
        //System.setIn(new FileInputStream("res/input1.txt"));

        Scanner sc = new Scanner(System.in);
        //int T;
        //T=sc.nextInt();

        for(int test_case = 1; test_case <= 10; test_case++)
        {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            int N = sc.nextInt();
            sc.nextLine();
            Tree t = new Tree(N);
            /////////////////////////////////////////////////////////////////////////////////////////////
            for(int i=1;i<=N;i++){
                String input = sc.nextLine();
                String[] inputArray = input.split(" ");

                if(inputArray.length == 2)
                    t.makeNode(null,Integer.parseInt(inputArray[0]),inputArray[1],null);
                else if(inputArray.length == 3)
                    t.makeNode(Integer.parseInt(inputArray[2]),Integer.parseInt(inputArray[0]),inputArray[1],null);
                else
                    t.makeNode(Integer.parseInt(inputArray[2]),Integer.parseInt(inputArray[0]),inputArray[1],Integer.parseInt(inputArray[3]));
            }
            System.out.print("#"+ test_case + " ");

            System.out.println(t.inorder(1));

            /////////////////////////////////////////////////////////////////////////////////////////////
        }
    }

    static class Node {
        String data;
        Integer leftId;
        Integer rightId;

        Node(String data, Integer leftId, Integer rightId) {
            this.data = data;
            this.leftId = leftId;
            this.rightId = rightId;
        }
    }

    static class Tree {
        Node[] nodeList;

        Tree(int N) {
            nodeList = new Node[10001];
        }

        public Node makeNode(Integer leftId, int id, String data, Integer rightId) {
            nodeList[id] = new Node(data, leftId, rightId);

            return nodeList[id];
        }

        public Node makeNode(Integer leftId, int id, String data) {
            nodeList[id] = new Node(data, leftId, null);

            return nodeList[id];
        }

        public Node makeNode(int id, String data) {
            nodeList[id] = new Node(data, null, null);

            return nodeList[id];
        }

        public String inorder(int cur) {
            if(nodeList[cur].leftId == null) return nodeList[cur].data;
            int leftData = Integer.parseInt(inorder(nodeList[cur].leftId));
            int rightData = Integer.parseInt(inorder(nodeList[cur].rightId));
            String operator = nodeList[cur].data;
            int ret = 0;
            switch(operator){
                case "+":
                    ret = leftData + rightData;
                    break;
                case "-":
                    ret = leftData - rightData;
                    break;
                case "*":
                    ret = leftData * rightData;
                    break;
                case "/":
                    ret = leftData / rightData;
                    break;
            }

            return String.valueOf(ret);
        }
    }
}