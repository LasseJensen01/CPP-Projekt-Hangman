#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/**
 * Helper class to read file for the words to guess during the game
*/
class fileReader{
    public:
    fileReader(string path){
        reader.open(path);
    }
    /**
     * Reads the file from the given path and saves all elements into wordVector
     * @param path the path to the given file
     * @return a vector containing the words
    */
    vector<string> readFile(){
        vector<string> temp;
        if (reader.is_open()){
            string s;
          while (getline(reader, s)){
            temp.push_back(s);
            }
            reader.close();  
        }
        return temp;   
    }

    private:
    fstream reader;
};


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
//TODO If possible find alternative here cuz its ugly af (like zimmer)
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



#endif // MY_HEADER_FILE_H