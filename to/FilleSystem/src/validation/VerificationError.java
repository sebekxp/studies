package validation;

public class VerificationError extends RuntimeException{
    public VerificationError(String message) {
        super(message);
    }
}
