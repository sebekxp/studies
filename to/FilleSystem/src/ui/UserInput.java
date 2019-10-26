package ui;

import commands.*;
import java.util.Optional;
import java.util.Scanner;

public class UserInput {
    private Scanner sc;
    private String line;
    private String cmd;
    private String[] parts;
    private String param;
    private CommandsRepository commandsRepository = new CommandsRepository();

    public UserInput() {
        this.sc = new Scanner(System.in);
    }

    public String getLine() {
        return line;
    }

    public void getConsoleLine(Console console) {
        line = sc.nextLine().trim();
        parts = line.split(" ", 2);
        cmd = parts[0];
        if (parts.length == 2)
            param = parts[1];
        searchAction(console);
    }

    private void searchAction(Console console) {
        Optional<Command> command = commandsRepository.getByName(cmd);
        command.ifPresentOrElse(command1 -> command1.run(console, param), () -> {
            if (!line.equals(""))
                System.out.println("Unknown command");
        });
    }
}
