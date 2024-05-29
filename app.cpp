#include <iostream>
#include <cstdlib>
#include <ctime>
#include <valarray> //Opfylder STL Requirement :D
#include <ctype.h>
#include <algorithm>
using namespace std;

void gameLoop();
string pickRandomWord();
void printHangMan(int state);
bool isAWord(string s);
bool validGuess(string s);
string fillShowCase(string word);
valarray<string> array = {"KAJ", "ANDREA", "KURT", "LIBRARY", "HAJ"};
valarray<string> wrongGuessesList = {};
string randomWord = "";
int wrongGuesses = 0;

int main(){
    // cout << "______" << "\n";
    // string pickedWord = "Elephant";
    // string guess = "muchogrande";
    // transform(guess.begin(), guess.end(), guess.begin(), ::toupper); // Converts input into Uppercase through magical means...
    // cout << guess << "\n";
    // if (validGuess(guess)){
    //     if (isAWord(guess)){
    //         cout << "You guessed a word: " << guess << "\n";
    //     } else{
    //         int idx = pickedWord.find(guess);
    //         cout << "Guess is in word: " << idx << "\n";
    //         cout << "You guessed a letter: " << guess << "\n"; 
    //     } 
    // }else cout << "Your guess is invalid: " << guess << "\n";
    gameLoop();

    return 0;
}

void gameLoop(){
    cout << "-- HANGMAN --\n";
    randomWord = pickRandomWord();
    string showCase = fillShowCase(randomWord);
    bool isDone = false;
    string guess;
    cout<< "Guess either a letter or a word"<< "\n";
    while (!isDone){
        cout << "Progress: " << showCase << "\n";
        cin>>guess;
        transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        if (validGuess(guess)){
            if (isAWord(guess)){
                // Check if guessed word is correct and fill in on showCase
                if (guess == randomWord){
                    isDone = true;
                    cout << "Correct! The word was: " << randomWord << "\n";
                } else {
                    // Replace with a method
                    wrongGuesses++;
                    cout << "-- HANGMAN --\n";
                    printHangMan(wrongGuesses);
                    if (wrongGuesses > 9){
                        cout << "You ran out of guesses... The word was: " << randomWord << "\n";
                        isDone = true;
                    }
                }
            } else {
                // Guess is a letter check the word for any and all instances of said letter
                // Perhaps shorten this into a method if possible
                int idx = randomWord.find(guess);
                if (idx != -1){
                 for (int i = 0; i < randomWord.length(); i++){
                    if (randomWord[i] == guess[0]){
                        showCase[i] = guess[0];
                    }
                 }
                 if (showCase.find("_") == -1){
                    isDone = true;
                    cout << "Correct! The word was: " << randomWord << "\n";
                 }   
                }else {
                    // Replace with a method
                    wrongGuesses++;
                    cout << "-- HANGMAN --\n";
                    printHangMan(wrongGuesses);
                    if (wrongGuesses > 9){
                        cout << "You ran out of guesses... The word was: " << randomWord << "\n";
                        isDone = true;
                    }
                    // A list of wrong guessed letters here and print progress of hangman tree
                }
                
            }
        } else cout << "INVALID GUESS\n";
    }
}
/**
 * Checks if the given string is a valid guess
 * @param s given param as string
 * @return true or false
*/
bool validGuess(string s){
    // Checks if the String is empty
    if (s.empty()){
        return false;
    } else {
        //Checks if there is a digit in the guess
        for (int i = 0; i < s.length(); i++){
            if (isdigit(s[i])){
                return false;
            }
        }
    }
    return true;
}

/**
 * Checks wether or not the given parameter is a word by checking if lenght() > 1
 * @param s string to check
 * @return true or false
*/
bool isAWord(string s){
    if (s.length() > 1){
        return true;
    } else return false;
}
/**
 * Picks a random word using srand() method based on current time.
 * @return the random word
*/
string pickRandomWord(){
    int lb = 0;
    int ub = array.size();
    srand(time(0));
    int random = (rand() % (ub - lb + 1)) + lb;
    return array[random];
}

/**
 * Fills the showcase to show progress when guessing letters
 * @param word the randomly picked word 
 * @return the showcasse with correct amounts of _
*/
string fillShowCase(string word){
    string showCase;
    for (int i = 0; i < word.length(); i++){
        showCase.append("_");
    }
    return showCase;
}

// If possible find alternative here cuz its ugly af (like zimmer)
/**
 * Prints the state of the game according to the amount of guesses the player has wrong. It is very long due to the art. Sorry Bjarne
 * @param state the amount of wrong guesses the player has
*/
void printHangMan(int state){

    switch (state)
    {
    case 1: 
        cout<<"    "<<"\n";
        cout<<"    "<<"\n";
        cout<<"    "<<"\n";
        cout<<"    "<<"\n";
        cout<<"    "<<"\n";
        cout<<" __________"<<"\n";
        break;
    case 2:
        cout<<"     "<<"\n";
        cout<<"|    "<<"\n";
        cout<<"|    "<<"\n";
        cout<<"|    "<<"\n";
        cout<<"|    "<<"\n";
        cout<<"|__________"<<"\n";
        break;
    case 3:
        cout<<"    _______"<<"\n";
        cout<<"|    "<<"\n";
        cout<<"|    "<<"\n";
        cout<<"|    "<<"\n";
        cout<<"|    "<<"\n";
        cout<<"|__________"<<"\n";
        break;
    case 4:
        cout<<"    _______"<<"\n";
        cout<<"|     |"<<"\n";
        cout<<"|      "<<"\n";
        cout<<"|      "<<"\n";
        cout<<"|      "<<"\n";
        cout<<"|__________"<<"\n";
        break;
    case 5:
        cout<<"    _______"<<"\n";
        cout<<"|     |"<<"\n";
        cout<<"|     O"<<"\n";
        cout<<"|      "<<"\n";
        cout<<"|      "<<"\n";
        cout<<"|__________"<<"\n";
        break;
    case 6:
        cout<<"    _______"<<"\n";
        cout<<"|     |"<<"\n";
        cout<<"|     O"<<"\n";
        cout<<"|     |"<<"\n";
        cout<<"|      "<<"\n";
        cout<<"|__________"<<"\n";
        break;
    case 7:
        cout<<"    _______"<<"\n";
        cout<<"|     |"<<"\n";
        cout<<"|     O"<<"\n";
        cout<<"|    /|"<<"\n";
        cout<<"|      "<<"\n";
        cout<<"|__________"<<"\n";
        break;
    case 8:
        cout<<"    _______"<<"\n";
        cout<<"|     |"<<"\n";
        cout<<"|     O"<<"\n";
        cout<<"|    /|\\"<<"\n";
        cout<<"|        "<<"\n";
        cout<<"|__________"<<"\n";
        break;
    case 9:
        cout<<"    _______"<<"\n";
        cout<<"|     |"<<"\n";
        cout<<"|     O"<<"\n";
        cout<<"|    /|\\"<<"\n";
        cout<<"|    /   "<<"\n";
        cout<<"|__________"<<"\n";
        break;
    default:
        cout<<"    _______"<<"\n";
        cout<<"|     |"<<"\n";
        cout<<"|     O"<<"\n";
        cout<<"|    /|\\"<<"\n";
        cout<<"|    / \\"<<"\n";
        cout<<"|__________"<<"\n";
        break;
    }
}