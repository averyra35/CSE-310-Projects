import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int run = 1;
        Guessing_Game obj = new Guessing_Game();
        Scanner scan = new Scanner(System.in);
        obj.guessing();
        while (run == 1) {
            System.out.println("Would you like to play again?\n  1. Yes\n  2. View Scores\n  0. Quit");
            String option = scan.nextLine();
            int choice = Integer.parseInt(option);
            if (choice == 1) {
                obj.guessing();
            }
            else if (choice == 2) {
                obj.scoreList();
            }
            else if (choice == 0) {
                run = 0;
            }
        }
    }
}