
/*
Online Java - IDE, Code Editor, Compiler

Online Java is a quick and easy tool that helps you to build, compile, test your programs online.
*/
public class Main
{
    public static void main(String[] args) {
        String word1 = "hi";
        String word2 = "";
        System.out.println(lastChars(word1, word2));
    }
    
    static String lastChars(String a, String b) {
       String aSubStr, bSubStr;
       
       if(a.length() > 0){
           aSubStr = a.substring(0, 1);
       }else{
           aSubStr = "@";
       }
       
       if(b.length() > 0){
           bSubStr = b.substring(b.length() - 1);
       }else{
           bSubStr = "@";
       }
       
       return aSubStr + bSubStr;
    }
}
