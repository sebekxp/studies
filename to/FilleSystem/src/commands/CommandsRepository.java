package commands;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class CommandsRepository {
    private List<Command> commands;

    public CommandsRepository() {
        this.commands = new ArrayList<>() {{
            add(new LsCommand("ls"));
            add(new CdCommand("cd"));
            add(new MkdirCommand("mkdir"));
            add(new TreeCommand("tree"));
            add(new RmCommand("rm"));
            add(new TouchCommand("touch"));
            add(new CatCommand("cat"));
        }};
    }

    public List<Command> getCommands() {
        return commands;
    }

    public void setCommands(List<Command> commands) {
        this.commands = commands;
    }

    public Optional<Command> getByName(String name) {
        return commands.stream().filter(c -> name.equals(c.getName())).findFirst();
    }
}
