package validation;

import filesystem.Node;

import java.util.List;
import java.util.Optional;

public abstract class Verifier {
    public static void checkMaxLength(String name) throws VerificationError {
        if (name.length() > 12) {
            throw new VerificationError("The length cannot exceed 12 characters.");
        }
    }

    public static void checkMinLength(String name) throws VerificationError {
        if (name.length() <= 0) {
            throw new VerificationError("The length cannot has 0 characters.");
        }
    }

    public static void checkCharacters(String name) throws VerificationError {
        if (name.contains("/") ||
                name.contains("<") ||
                name.contains(">") ||
                name.contains(":") ||
                name.contains("\"") ||
                name.contains("\\") ||
                name.contains("|") ||
                name.contains("?") ||
                name.contains("*") ||
                name.startsWith(".")
        ) {
            throw new VerificationError("Given string contains forbidden characters.");
        }
    }

    public static void checkDuplicate(List<Node> nodes, String name) {
        Optional<Node> isDuplicate = nodes.stream().filter(n -> n.getName().equals(name)).findFirst();

        if (isDuplicate.isPresent())
            throw new VerificationError("Duplicate name. Please Use another.");
    }


    public static void verify(String name) {
        checkCharacters(name);
        checkMaxLength(name);
        checkMinLength(name);
    }
}
