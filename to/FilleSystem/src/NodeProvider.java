import filesystem.Directory;
import filesystem.File;
import ui.Console;

public class NodeProvider {

    public static void main(String[] args) {
        Directory root =  new Directory("root");
        Directory dir1 =  new Directory("dir1");
        Directory dir2 =  new Directory("dir2");
        Directory dir3 =  new Directory("dir3");
        Directory dir4 =  new Directory("dir4");
        Directory dir5 =  new Directory("dir5");
        Directory dir6 =  new Directory("dir6");
        Directory dir7 =  new Directory("dir7");

        File file = new File("file");
        File file1 = new File("file1");
        File file2 = new File("file2");
        file.setContent("contentFile".getBytes());

        root.add(dir1);
        root.add(file);
        dir1.add(dir2);
        dir1.add(file);
        dir1.add(file1);
        dir1.add(file2);
        dir2.add(dir3);
        dir3.add(file);
        root.add(dir4);
        root.add(dir5);
        root.add(dir6);
        root.add(dir7);

        Console console = new Console(root);
        console.run();
    }
}
