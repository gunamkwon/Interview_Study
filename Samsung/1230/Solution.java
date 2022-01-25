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
import java.util.Scanner;
import java.io.FileInputStream;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
    public static void main(String args[]) throws Exception
    {
        System.setIn(new FileInputStream("res/input.txt"));

        Scanner sc = new Scanner(System.in);
        LinkedList list = new LinkedList();
        int T;
        //T=sc.nextInt();


        for(int test_case = 1; test_case <= 10; test_case++)
        {
            list.init();
            int listSize = sc.nextInt();

            for(int i=0;i<listSize;i++){
                int num = sc.nextInt();
                list.append(num);
            }

            int cmdCnt = sc.nextInt();
            /////////////////////////////////////////////////////////////////////////////////////////////
            for(int i=0;i<cmdCnt;i++) {
                String cmd = sc.next();
                int[] datum;
                int x,y;

                switch(cmd) {
                    case "I":
                        x = sc.nextInt();
                        y = sc.nextInt();
                        datum = new int[y];
                        for(int c=0;c<y;c++){
                            datum[c] = sc.nextInt();
                        }
                        list.insert(x,datum);
                        break;
                    case "D":
                        x = sc.nextInt();
                        y = sc.nextInt();
                        list.delete(x,y);
                        break;
                    case "A":
                        y = sc.nextInt();
                        datum = new int[y];
                        for(int c=0;c<y;c++){
                            datum[c] = sc.nextInt();
                        }
                        list.addLast(datum);
                        break;
                    default:
                        System.out.println("WHY?");
                        break;
                }
            }
            /////////////////////////////////////////////////////////////////////////////////////////////
            StringBuilder sb = new StringBuilder();
            sb.append("#"+test_case+" ");
            sb.append(list.getData());
            System.out.println(sb);
        }
    }

    static class LinkedList {

        static class Node {
            int data;
            Node next;

            Node(int data) {
                this.data = data;
                this.next = null;
            }
        }

        private Node[] nodeList = new Node[50000001];
        private int nodeSize = 0;
        private Node head;

        public Node getNode(int data) {
            nodeList[nodeSize] = new Node(data);
            return nodeList[nodeSize++];
        }

        LinkedList() {
            head = new Node(-1);
            nodeSize = 0;
        }

        private void init() {
            nodeSize = 0;
            head.next = null;
        }

        private void append(int data) {
            Node n;
            if(nodeList[nodeSize]==null){
                n = getNode(data);
            } else {
                n = nodeList[nodeSize++];
                n.data = data;
                n.next = null;
            }

            Node cur = head;
            if (cur.next != null) {
                n.next = cur.next;
            }
            cur.next = n;
        }

        private void addLast(int[] datum) {

            // cur -> tail 가리키기
            Node cur = head;
            while(cur.next!=null){
                cur = cur.next;
            }

            // cur -> n 순환
            for(int data: datum){
                Node n;
                if(nodeList[nodeSize]==null) {
                    n = getNode(data);
                } else {
                    n = nodeList[nodeSize++];
                    n.data = data;
                    n.next = null;
                }

                cur.next = n;
                cur = n;
            }
        }

        private void insert(int x, int[] datum) {
            Node cur = head;
            for(int i=0;i<x;++i){
                cur = cur.next;
            }

            for(int data:datum){
                Node n;
                if(nodeList[nodeSize] == null)
                    n = getNode(data);
                else {
                    n = nodeList[nodeSize++];
                    n.data = data;
                    n.next = null;
                }

                n.next = cur.next;
                cur.next = n;
                cur = n;
            }
        }

        private void delete(int x, int y) {
            // x 위치 가리키기
            Node cur = head;
            for(int i=0;i<x;i++){
                cur = cur.next;
            }
            for(int i=0;i<y;i++){
                cur.next = cur.next.next;
            }
        }

        private StringBuilder getData() {
            StringBuilder sb = new StringBuilder();
            Node cur = head;

            for(int i=0;i<10;i++) {
                cur = cur.next;
                sb.append(cur.data+ " ");
            }
            return sb;
        }
    }
}