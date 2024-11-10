#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(string str);
string removeSpace(const string &str);
string toLowerCase(const string &str);

int main(){
    string word = "A man a plan a canal Panama";
    cout << (isPalindrome(word) ? "The word is a palindrome." : "The word is not a palindrome.") << endl;
    return 0;
}

bool isPalindrome(string str){
    str = removeSpace(str);
    str = toLowerCase(str);
    
    int left = 0;
    int right = str.length() - 1;
    
    while(left < right){
        if(str[left] != str[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

string removeSpace(const string &str){
    string result;
    
    for(char c : result){
        if(c != ' '){
            result += c;
        }
    }
    return result;
}

string toLowerCase(const string &str){
    string result = str;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c){
        return tolower(c);
    });
    return result;
}