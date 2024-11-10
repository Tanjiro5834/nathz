
/*
Online Java - IDE, Code Editor, Compiler

Online Java is a quick and easy tool that helps you to build, compile, test your programs online.
*/
public class Main
{
    public static void main(String[] args) {
		String word = "WooHoo";
		System.out.println(firstHalf(word));
	}
	
	static String firstHalf(String str) {
	    int mid = str.length() / 2;
		String subStr = str.substring(0, mid);
		return subStr;
	}
}
