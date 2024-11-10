#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

char firstNonRepeatedCharacter(const string& str) {
    unordered_map<char, int> charCount;
    
    for(char c : str){
        charCount[c]++;
    }
    
    for(char c : str){
        if(charCount[c] == 1){
            return c;
        }
    }
    return ' ';
}

int main() {
    string word = "swiss";
    cout << "First non-repeated character: " << firstNonRepeatedCharacter(word) << endl;
    return 0;
}
