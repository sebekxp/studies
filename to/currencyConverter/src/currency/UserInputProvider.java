package currency;

import java.util.Optional;
import java.util.Scanner;

public class UserInputProvider {
    private Repository repository;
    private Scanner sc = new Scanner(System.in);
    private boolean run = true;

    UserInputProvider(Repository repository){
        this.repository = repository;
    }
    public void userInput() {
        sc.nextLine();
        System.out.println("currency code (source)");
        String src = sc.nextLine();
        System.out.println("currency code (destination)");
        String dest = sc.nextLine();
        System.out.println("Amount of money");
        double value = sc.nextDouble();

        Optional<Currency> optionalCurrency1 = repository.getCurrencyByCoode(src);
        Optional<Currency> optionalCurrency2 = repository.getCurrencyByCoode(dest);

        if (optionalCurrency1.isPresent() && optionalCurrency2.isPresent()) {
            Currency c1 = optionalCurrency1.get();
            Currency c2 = optionalCurrency2.get();
            Calculator calculate = new Calculator(c1, c2, value);

            System.out.println("Amount of money after convert");
            System.out.println(value + " " + src + " == " + calculate.calc() + " " + dest);
            System.out.println(value + " " + src + " == " + UserCalc.uCalc(src, dest, value, repository) + " " + dest);
        } else {
            throw new IllegalArgumentException("We dont support entered currency code.");
        }
    }

    public void start() {
        while (run) {
            Menu.printMenu();

            System.out.println("Chose option");
            int option = sc.nextInt();
            switch (option) {
                case 1:
                    userInput();
                    break;
                case 2:
                    exit();
                    break;
            }
        }
        System.out.println("GOOD BYE");
    }


    public void exit() {
        run = false;
    }
}
