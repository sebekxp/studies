package filesystem;

public class File extends Node {
    private byte[] content;

    public File(String name) {
        setName(name);
    }

    public byte[] getContent() {
        return content;
    }

    public void setContent(byte[] content) {
        this.content = content;
    }

    public void printContent(){
        System.out.println(new String(this.content));
    }
}
