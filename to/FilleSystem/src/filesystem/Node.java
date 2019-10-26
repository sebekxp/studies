package filesystem;

import java.util.Objects;

public abstract class Node {
    private Directory parent;
    private String name;
    private String path;

    public void setParent(Directory parent) {
        this.parent = parent;
    }

    public Node getParent() {
        return parent;
    }
    public boolean isDirectory(){
        return this instanceof Directory;
    }
    public boolean isFile(){
        return this instanceof File;
    }
    public String getName() {
        return name;
    }

    public String getPath() {
        return path;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Node node = (Node) o;
        return Objects.equals(name, node.name) &&
                Objects.equals(path, node.path);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, path);
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPath() {
        this.path = (parent.getPath() == null) ?
                ((this instanceof Directory) ?
                        parent.getName() + "/" :
                        parent.getName()) :
                ((this instanceof Directory) ?
                        parent.getPath() + this.name + "/" :
                        parent.getPath() + this.name);
    }
}
