import java.util.Scanner;
public class palindrome {
    public static void main(String[]args){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.print("Enter a word:");
            String input = scan.next().toLowerCase();
            System.out.print("Result:");
            String res = checkWord(input);
            if(res.equals("")){
                dispOutput(input);
            }else{
                System.out.println(res);
            }
        }
    }
    static String dispOutput(String word){
        String wordCount = word.length();
        int mid = Math.round(wordCount / 2) + 1;
        for(int i = 0; i < wordCount; i++){
            for()
        }
    }
    static String checkWord(String word){
        if(word.length() < 3){
            return "Enter at least 3 characters.";
        }else if(word.length() % 2 == 0){
            return "Character count is not an odd number.";
        }
        String reversed = "";
        char[]reversedArray = new char[word.length()];
        for(int i = word.length() - 1, j = 0; i >= 0; i--, j++){
            reversedArray[j] += word.charAt(i);
        }
        String reversedWord = new String[reversedArray];
        if(!word.equals(reversedWord)){
            System.out.println(word + " is not a palindrome word.");
        }
        return "";
    }
}
