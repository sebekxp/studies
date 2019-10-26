package commands;

import filesystem.File;
import ui.Console;
import validation.VerificationError;

public class TouchCommand extends Command implements ICommand {
    public TouchCommand(String name) {
        super(name);
    }

    @Override
    public void run(Console console, String param) {
        File newFile = new File(param);
        newFile.setContent("".getBytes());
        try {
            console.getCurrentDir().add(newFile);
        } catch (VerificationError e) {
            System.out.println(e.getMessage());
        }
    }
}
