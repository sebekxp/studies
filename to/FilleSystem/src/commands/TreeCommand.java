package commands;

import filesystem.Directory;
import ui.Console;

public class TreeCommand extends Command implements ICommand {
    public TreeCommand(String name) {
        super(name);
    }

    @Override
    public void run(Console console, String param) {
        console.getCurrentDir().printTree();
    }
}
