
/*
Online Java - IDE, Code Editor, Compiler

Online Java is a quick and easy tool that helps you to build, compile, test your programs online.
*/
public class Main
{
    public static void main(String[] args) {
        String input = "olydd";
        System.out.println(endsLy(input));
    }
    
    public static boolean endsLy(String str){
        if(str.length() < 2){
            return false;
        }else{
            return str.endsWith("ly");
        }
    }
}
