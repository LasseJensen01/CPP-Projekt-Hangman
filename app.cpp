#include <iostream>
#include <cstdlib>
#include <ctime>
#include <valarray> //Opfylder STL Requirement :D
#include <ctype.h>
using namespace std;

string pickRandomWord();
void printHangMan();
bool isAWord();
bool validGuess();
valarray<string> array = {"Kaj", "Andrea", "Kurt", "Library", "Haj"};

int main(){
    string randomWord = pickRandomWord();
    bool isDone = false;
    string guess;
    cout<< "Guess either a letter or a word"<< "\n";
    printHangMan();
    while (!isDone){
        cin>>guess;

        if (guess == randomWord){
            cout<< "Correct the word was " << randomWord;
            isDone = true;
        } else{cout<< "Wrong!"<< "\n";}
    }
    return 0;
}

bool validGuess(string s){
    if (s.empty()){
        return false;
    } else if (isdigit(s[0])){
        return false;
    }
    return true;
    
}


bool isAWord(string s){
    if (s.length() > 1){
        return true;
    } else return false;
}
string pickRandomWord(){
    int lb = 0;
    int ub = 5;
    srand(time(0));
    int random = (rand() % (ub - lb + 1)) + lb;
    return array[random];
}

void printHangMan(){
//     _______
// |     |
// |     O
// |    /|\
// |    / \
// |__________

cout<<"    _______"<<"\n";
cout<<"|     |"<<"\n";
cout<<"|     O"<<"\n";
cout<<"|    /|\\"<<"\n";
cout<<"|    / \\"<<"\n";
cout<<"|__________"<<"\n";

}