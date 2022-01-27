import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
    private static final int MAX_NODE = 10001;
    private static TreeNode[] treeNodeList = new TreeNode[MAX_NODE];
    public static void main(String args[]) throws Exception
    {
        System.setIn(new FileInputStream("res/input4.txt"));

        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();

        for(int test_case = 1; test_case <= T; test_case++)
        {
            int V, E, t1, t2;
            V = sc.nextInt();
            E = sc.nextInt();
            t1 = sc.nextInt();
            t2 = sc.nextInt();
            init(V);
            /////////////////////////////////////////////////////////////////////////////////////////////
            for(int i=0;i<E;i++){
                int parent = sc.nextInt();
                int child = sc.nextInt();
                treeNodeList[parent].addChildNode(child);
            }
            TreeNode commonNode = findCommonParent(treeNodeList[t1],treeNodeList[t2]);
            int subTreeSize = commonNode.getSubTreeSize() + 1;
            /////////////////////////////////////////////////////////////////////////////////////////////
            System.out.println("#"+test_case+ " " + commonNode.data + " " + subTreeSize);


        }
    }

    private static void init(int size) {
        for(int i=1;i<=size;i++){
            treeNodeList[i] = new TreeNode(i);
        }
    }


    private static TreeNode findCommonParent(TreeNode t1, TreeNode t2) {
        TreeNode T1 = t1;
        TreeNode T2 = t2;

        int T1depth = t1.getDepth();
        int T2depth = t2.getDepth();

        if (T1depth > T2depth) {
            while(T1depth != T2depth) {
                T1 = T1.getParent();
                T1depth--;
            }
        } else if(T1depth < T2depth) {
            while(T1depth != T2depth) {
                T2 = T2.getParent();
                T2depth--;
            }
        }

        while(T1.data != T2.data) {
            T1 = T1.getParent();
            T2 = T2.getParent();
        }

        return T1;
    }

    static class TreeNode {
        int data;
        TreeNode parent;
        ArrayList<TreeNode> childList = new ArrayList<>();

        TreeNode(int data) {
            this.data = data;
            parent = null;
        }

        public void setParentNode(TreeNode parent) {
            this.parent = parent;
        }

        public TreeNode addChildNode(int data) {
            TreeNode child = treeNodeList[data];
            child.setParentNode(this);
            childList.add(child);

            return child;
        }

        public int getSubTreeSize() {
            int size = childList.size();

            for(int i=0;i<childList.size();i++){
                size += childList.get(i).getSubTreeSize();
            }

            return size;
        }

        public int getDepth() {
            int depth = 0;
            TreeNode cur = this;

            while(cur.parent!= null){
                depth++;
                cur = cur.parent;
            }

            return depth;
        }

        public TreeNode getParent() {
            return parent;
        }
    }

}