package commands;

import filesystem.Directory;
import filesystem.Node;
import ui.Console;

import java.util.Optional;

public class CdCommand extends Command implements ICommand {
    public CdCommand(String name) {
        super(name);
    }

    @Override
    public void run(Console console, String param) {
        if (param.equals("..")) {
            Directory prevDir = (Directory) console.getCurrentDir().getParent();
            console.setCurrentDir(prevDir);
        } else {
            Optional<Node> directory = console.getCurrentDir().getByName(param);
            if (directory.isPresent()) {
                console.setCurrentDir((Directory) directory.get());
            } else {
                System.out.println("No directory with the given name");
            }
        }
    }
}
