package filesystem;

import validation.Verifier;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class Directory extends Node {
    private List<Node> nodes = new ArrayList<>();

    public Directory(String name) {
        Verifier.verify(name);
        setName(name);
    }

    public List<Node> getNodes() {
        return nodes;
    }

    public void add(Node node) {
        Verifier.checkDuplicate(nodes, node.getName());
        node.setParent(this);
        node.setPath();
        nodes.add(node);
    }

    public void remove(Node node) {
        nodes.remove(node);
    }

    public void printNodes() {
        nodes.stream().forEach(n -> {
            if (n instanceof Directory)
                System.out.println(n.getName() + "/");
            else
                System.out.println(n.getName());
        });
    }

    public Optional<Node> getByNode(Node node) {
        return nodes.stream().filter(n -> n.equals(node)).findFirst();
    }

    public Optional<Node> getByName(String name) {
        return nodes.stream().filter(n -> n.getName().equals(name)).findFirst();
    }

    public void printTree() {
        int indent = 0;
        StringBuilder sb = new StringBuilder();
        printDirectoryTree(this, indent, sb);
        System.out.println(sb.toString());
    }

    private void printDirectoryTree(Node node, int indent, StringBuilder sb) {
        sb.append(getIndentString(indent, node.getName()));
        sb.append("├─");
        sb.append(node.getName());
        if (node.isDirectory())
            sb.append("/");
        sb.append("\n");

        if (node.isDirectory()) {
            Directory directory = (Directory) node;
            for (Node file : directory.getNodes()) {
                printDirectoryTree(file, indent + 1, sb);
            }
        }
    }

    private  String getIndentString(int indent, String name) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < indent; i++) {
            sb.append("│");
            int temp = 0;
            while (temp++ != findLongestName()) {
                sb.append(" ");
            }
        }
        return sb.toString();
    }

    private int findLongestName() {
        var ref = new Object() {
            int max = 0;
        };

        nodes.stream().forEach(n -> {
            if (n.getName().length() > ref.max)
                ref.max = n.getName().length();
        });
        return ref.max;
    }
}
