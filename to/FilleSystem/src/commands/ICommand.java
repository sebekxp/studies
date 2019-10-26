package commands;

import ui.Console;

public interface ICommand {
    public void run(Console console, String param);
}
