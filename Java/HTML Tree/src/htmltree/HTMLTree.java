package htmltree;
import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import java.awt.*;

public class HTMLTree {

    public static void main(String[] args) {
        DefaultMutableTreeNode html = new DefaultMutableTreeNode("html");

        DefaultMutableTreeNode head = new DefaultMutableTreeNode("head");
        DefaultMutableTreeNode body = new DefaultMutableTreeNode("body");

        html.add(head);
        html.add(body);

        DefaultMutableTreeNode meta = new DefaultMutableTreeNode("meta");
        DefaultMutableTreeNode title = new DefaultMutableTreeNode("title");
        head.add(meta);
        head.add(title);

        DefaultMutableTreeNode ul = new DefaultMutableTreeNode("ul");
        DefaultMutableTreeNode h1 = new DefaultMutableTreeNode("h1");
        DefaultMutableTreeNode h2 = new DefaultMutableTreeNode("h2");
        body.add(ul);
        body.add(h1);
        body.add(h2);

        DefaultMutableTreeNode li1 = new DefaultMutableTreeNode("li");
        DefaultMutableTreeNode li2 = new DefaultMutableTreeNode("li");
        ul.add(li1);
        ul.add(li2);

        DefaultMutableTreeNode a = new DefaultMutableTreeNode("a");
        h2.add(a);

        JTree tree = new JTree(html);
        JScrollPane treeView = new JScrollPane(tree);

        JFrame frame = new JFrame("JTree Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());
        frame.add(treeView, BorderLayout.CENTER);
        frame.setSize(300, 400);
        frame.setVisible(true);
    }
}
