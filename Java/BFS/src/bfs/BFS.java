package bfs;
import java.util.LinkedList;
import java.util.Queue;

public class BFS {
    
    public static void BFSTraversal(TreeNode root){
        if(root == null){
            return;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()){
            TreeNode current = queue.poll();
            System.out.println(current.val+" ");
            
            if(current.left != null){
                queue.offer(current.left);
            }
            if(current.right != null){
                queue.offer(current.right);
            }
        }
    }
    
    public static void main(String[] args){
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        System.out.print("BFS Traversal:");
        BFSTraversal(root);
    }
    
    static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        
        public TreeNode(int val){
            this.val = val;
        }
    } 
}
