import java.util.Scanner;
public class PineTreePrinter {

	public static void main(String[] args) {
		var scan = new Scanner(System.in);
		System.out.print("Enter number of asterisks to print: ");
		int n = scan.nextInt();
		
		printTree(n);
		
		scan.close();
	}
	
	static void printTree(int height){
		for(int i = 1; i <= height; i++) {
			for(int j = i; j < height; j++) {
				System.out.print(" ");
			}
			
			for(int k = 1; k <= (2 * i - 1); k++){
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
