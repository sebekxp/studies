package commands;

import filesystem.Directory;
import ui.Console;
import validation.VerificationError;

public class MkdirCommand extends Command implements ICommand {
    public MkdirCommand(String name) {
        super(name);
    }


    @Override
    public void run(Console console, String param) {
        Directory newDir = new Directory(param);
        try {
            console.getCurrentDir().add(newDir);
        } catch (VerificationError e) {
            System.out.println(e.getMessage());
        }
    }
}
