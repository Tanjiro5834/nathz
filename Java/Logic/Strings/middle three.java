
/*
Online Java - IDE, Code Editor, Compiler

Online Java is a quick and easy tool that helps you to build, compile, test your programs online.
*/
public class Main
{
    public static void main(String[] args) {
        String input = "solving";
        System.out.println(middleThree(input));
    }
    
    public static String middleThree(String str) {
        int mid = str.length() / 2; 
        if(str.length() >= 3){
            return str.substring(mid - 1, mid + 2);
        }else if(str.length() == 3){
            return str;
        }
        
        return "";
    }
}
