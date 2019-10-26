package commands;

import filesystem.File;
import filesystem.Node;
import ui.Console;

import java.util.Optional;

public class CatCommand extends Command implements ICommand {
    public CatCommand(String name) {
        super(name);
    }

    @Override
    public void run(Console console, String param) {
        Optional<Node> file = console.getCurrentDir().getByName(param);
        if(file.isPresent()){
            File f = (File) file.get();
            f.printContent();
        }
    }
}
