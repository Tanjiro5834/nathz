
/*
Online Java - IDE, Code Editor, Compiler

Online Java is a quick and easy tool that helps you to build, compile, test your programs online.
*/
public class Main
{
    public static void main(String[] args) {
        String input = "oh";
        boolean i = true;
        
        System.out.println(theEnd(input, i));
    }
    
    public static String theEnd(String str, boolean front){
        String getFirstLetter = "", getBack = "";
        if(front){
            return str.substring(0, 1);
        }else{
            return str.substring(str.length() - 1);
        } 
    }
}
