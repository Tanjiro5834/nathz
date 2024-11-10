
/*
Online Java - IDE, Code Editor, Compiler

Online Java is a quick and easy tool that helps you to build, compile, test your programs online.
*/
public class Main
{
    public static void main(String[] args) {
        String word1 = "Hello", word2 = "There";
        System.out.println(nonStart(word1, word2));
    }
    
    public static String nonStart(String a, String b){
        String getHalfA = a.substring(1);
        String getHalfB = b.substring(1);
        
        String result = getHalfA + getHalfB;
        return result;
    }
}
