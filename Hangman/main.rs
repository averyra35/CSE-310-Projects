use rand::seq::SliceRandom;
use rand::thread_rng;
use std::io::{self, Write};

const HANGMAN_DISPLAY: [&str; 9] = [
    "   +---+\n       |\n       |\n       |\n      ===",
    "   +---+\n   O   |\n       |\n       |\n      ===",
    "   +---+\n   O   |\n   |   |\n       |\n      ===",
    "   +---+\n   O   |\n  /|   |\n       |\n      ===",
    "   +---+\n   O   |\n  /|\\  |\n       |\n      ===",
    "   +---+\n   O   |\n  /|\\  |\n  /    |\n      ===",
    "   +---+\n   O   |\n  /|\\  |\n  / \\  |\n      ===",
    "   +---+\n   O   |\n  /|\\  |\n _/ \\  |\n      ===",
    "   +---+\n   O   |\n  /|\\  |\n _/ \\_ |\n      ===",
];

fn main() {
    let words: Vec<&str> = vec!["crustacean", "lobster", "tuna"];
    let word_to_guess = words.choose(&mut thread_rng()).unwrap();
    let mut letters_guessed: Vec<char> = vec!['_'; word_to_guess.len()];
    let mut guesses_left = HANGMAN_DISPLAY.len() - 1;
    let mut wrong_guesses = 0;
    
    println!("Welcome to Hangman!");

    while guesses_left > 0 && letters_guessed.contains(&'_') {
        print_stats(&letters_guessed, guesses_left, wrong_guesses);
        let guess: char = get_guess();

        if word_to_guess.contains(guess) {
            for (i, c) in word_to_guess.chars().enumerate() {
                if c == guess {
                    letters_guessed[i] = guess;
                }
            }
        } else {
            guesses_left -= 1;
            wrong_guesses += 1;
        }
    }

    if guesses_left == 0 {
        println!("You lost, the word was: {}", word_to_guess);
        println!("{}", HANGMAN_DISPLAY[HANGMAN_DISPLAY.len() - 1]);
    } else {
        println!("Congratulations! You guess the word: {}", word_to_guess);
    }
}

fn print_stats(letters_guessed: &[char], guesses_left: usize, wrong_guesses: usize) {
    println!("{}", HANGMAN_DISPLAY[wrong_guesses]);
    println!("\nWord: {}", letters_guessed.iter().collect::<String>());
    println!("Guesses left: {}", guesses_left);
}

fn get_guess() -> char {
    print!("Enter guess: ");
    io::stdout().flush().unwrap();
    let mut guess = String::new();
    io::stdin().read_line(&mut guess).unwrap();
    guess.trim().chars().next().unwrap_or('_')
}