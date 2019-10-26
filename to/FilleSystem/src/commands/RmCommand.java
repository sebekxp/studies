package commands;

import filesystem.Directory;
import filesystem.Node;
import ui.Console;

import java.util.Optional;

public class RmCommand extends Command implements ICommand {
    public RmCommand(String name) {
        super(name);
    }


    @Override
    public void run(Console console, String param) {
        Optional<Node> dir = console.getCurrentDir().getByName(param);
        if (dir.isPresent()) {
            console.getCurrentDir().remove(dir.get());
        } else {
            System.out.println("No directory with the given name");
        }
    }
}
