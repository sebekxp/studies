package ui;

import filesystem.Directory;

public class Console {
    private boolean run;
    private Directory currentDir;
    private UserInput userInput;

    public Console(Directory dir) {
        this.run = true;
        currentDir = dir;
        userInput = new UserInput();
    }

    public void run() {
        while (run) {
            System.out.print(updateDir());
            userInput.getConsoleLine(this);
        }
    }

    public void setCurrentDir(Directory currentDir) {
        this.currentDir = currentDir;
    }

    public Directory getCurrentDir() {
        return currentDir;
    }

    private String updateDir() {
        String dir = currentDir.getPath() == null ? currentDir.getName() : currentDir.getPath() + currentDir.getName();
        dir += ": ";
        return dir;
    }

}
