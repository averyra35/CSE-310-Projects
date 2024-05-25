import java.util.ArrayList;
import java.util.Scanner;

public class Guessing_Game {
    ArrayList<Integer> scores = new ArrayList<Integer>();
    public void guessing() {
        int guesses = 0;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the top of the range: ");
        int rangeT = scan.nextInt();
        System.out.println("Enter the bottom of the range: ");
        int rangeB = scan.nextInt();
        int randomNum = rangeB + (int)(Math.random() * (rangeT - rangeB + 1));
        System.out.println("I have selected a number between " + rangeB + " and " + rangeT + ". Try to guess it!");
        
        while (guesses < 20) {
            System.out.println("Enter your guess: ");
            int guess = scan.nextInt();
            guesses++;

            if (guess < randomNum) {
                System.out.println("Too low!");
            } else if (guess > randomNum) {
                System.out.println("Too high!");
            } else {
                System.out.println("Congratulations! You guessed the number in " + guesses + " guesses.");
                scores.add(guesses);
                break;
            }

            System.out.println("You have " + (20 - guesses) + " guesses left.");
        }
        if (guesses == 20) {
            System.out.println("Sorry, you've used all your guesses. The number was " + randomNum + ".");
        }
    }

    public void scoreList() {
        System.out.println("\nYour Scores are: ");
        for (int i : scores) {
            if (i == 1) {
                System.out.println(i + " Guess");
            }
            else {
                System.out.println(i + " Guesses");
            }
        }
    }
}
