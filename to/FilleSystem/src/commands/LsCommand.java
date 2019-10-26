package commands;

import ui.Console;

public class LsCommand extends Command implements ICommand {
    public LsCommand(String name) {
        super(name);
    }

    @Override
    public void run(Console console, String param) {
        console.getCurrentDir().printNodes();
    }
}
