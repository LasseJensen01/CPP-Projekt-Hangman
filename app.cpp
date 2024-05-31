#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector> // STL Req
#include <ctype.h>
#include <algorithm>
#include "header.h" // Header with classes and functions not directly involved in the gameLoop() function
using namespace std;

void gameLoop();
string pickRandomWord();
void printHangMan(int state);
bool isAWord(string s);
bool validGuess(string s);
string fillShowCase(string word);
vector<string> wordVector;
string randomWord;
string* rWordPtr = &randomWord;
int wrongGuesses = 0;
vector<string> wrongVector;



int main(){
    fileReader reader("words.txt");
    wordVector = reader.readFile();
    bool playing = true;
    while (playing)
    {
      gameLoop();
      cout << "To play again type 1\n";
      cout << "To quit type 2\n";
      string s;
      cin >> s;
      if (s == "2"){
        playing = false;
      } else {
        wrongGuesses = 0;
        wrongVector.clear();
      }
    }
    
    
    
    return 0;
}
/**
 * Game Loop function to run the game
*/
void gameLoop(){
    cout << "-- HANGMAN --\n";
    randomWord = pickRandomWord();
    string showCase = fillShowCase(*rWordPtr);
    bool isDone = false;
    string guess;
    cout<< "Guess either a letter or a word"<< "\n";
    while (!isDone){
        cout << "-- HANGMAN --\n";
        printHangMan(wrongGuesses);
        cout << "Progress: " << showCase << "\n";
        cout << "Previous guesses: ";
        for (string s : wrongVector){ // Displays all wrong previous letter guesses
            cout << s << ", ";
        }
        cout << "\n";
        cin>>guess;
        transform(guess.begin(), guess.end(), guess.begin(), ::toupper); // Transforms the guess into uppercase
        if (validGuess(guess)){ // Checks if the guess is valid
            if (isAWord(guess)){ // Checks if the guess is a word or a letter
                if (guess == *rWordPtr){// Check if guessed word is correct and fill in on showCase
                    isDone = true;
                    cout << "Correct! The word was: " << *rWordPtr << "\n";
                } else {
                    wrongGuesses++;
                    if (wrongGuesses > 9){
                        cout << "You ran out of guesses... The word was: " << *rWordPtr << "\n";
                        isDone = true;
                    }
                }
            } else {
                int idx = randomWord.find(guess); // Finds the index of the guess, if it is not in the word will return -1
                if (idx != -1){
                 for (int i = 0; i < randomWord.length(); i++){ // Goes through random word and reveals all the instances of the the guess.
                 // Dosen't use idx param since more instances could of guess could appear in the word and the find method only reveals the first
                    if (randomWord[i] == guess[0]){
                        showCase[i] = guess[0];
                    }
                 }
                 if (showCase.find("_") == -1){ // Checks wether or not any more blankspaces are in the random word if not, the game is done
                    isDone = true;
                    cout << "Correct! The word was: " << *rWordPtr << "\n";
                 }   
                }else {
                    wrongVector.push_back(guess);
                    wrongGuesses++;
                    if (wrongGuesses > 9){
                        printHangMan(wrongGuesses);
                        cout << "You ran out of guesses... The word was: " << *rWordPtr << "\n";
                        isDone = true;
                    }
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
    int ub = wordVector.size();
    srand(time(0));
    int random = (rand() % (ub - lb + 1)) + lb;
    return wordVector[random];
}