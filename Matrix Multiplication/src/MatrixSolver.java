import java.util.Scanner;

public class MatrixSolver {
	
	static int e1, e2, e3;
	static final int MAX_ATTEMPTS = 8;
	static int attempts = 0, size = 3, result;
	
	public static void main(String[] args) {
		var scan = new Scanner(System.in);
		do{
			System.out.print("Enter matrix A: ");
			int[] nums = new int[size]; //matrix a 
			for(int i = 0; i < size; i++){
				nums[i] = scan.nextInt();
			}
			
			System.out.print("Enter number of rows: ");
			int row = scan.nextInt();
			
			System.out.print("Enter number of columns: ");
			int columns = scan.nextInt();
			
			if(columns != 3){
				System.out.println("Matrix B must have exactly 3 columns!");
				continue;
			}
			
			int[][] mB = new int[row][columns]; //matrix B
			System.out.println("Enter the numbers to fill the matrix B: ");
			for(int r = 0 ; r < row; r++){
				for(int c = 0; c < columns; c++){
					System.out.print("Element [" + r + "][" + c + "]: ");
	                mB[r][c] = scan.nextInt();
				}
			}
			
			//for matrix a: assign values to e1, e2, e3 directly
			e1 = nums[0];
			e2 = nums[1];
			e3 = nums[2];
	        
	        for(int r = 0; r < row; r++){
                int p = (e1 * mB[r][0]) + (e2 * mB[r][1]) + (e3 * mB[r][2]);
                System.out.println("Answer for row " + r + ": " + p);
            }
	        
	        attempts++;
			
		}while(attempts != MAX_ATTEMPTS);
		
		scan.close();
	}
}
