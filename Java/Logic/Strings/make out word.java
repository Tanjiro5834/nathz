
/*
Online Java - IDE, Code Editor, Compiler

Online Java is a quick and easy tool that helps you to build, compile, test your programs online.
*/
public class Main
{
    public static void main(String[] args) {
        String o = "[[]]";
		String word = "Hello";
		
		System.out.println(makeOutWord(o, word));
    }
    
    static String makeOutWord(String out, String word) {
		String firstHalf = "", secondHalf = "";
		int length = 4, mid = 2;
		if(out.length() == 4){
			firstHalf = out.substring(0, mid);
			secondHalf = out.substring(mid, length);
		}
		String result = firstHalf + word + secondHalf;
		return result;
	}
}
