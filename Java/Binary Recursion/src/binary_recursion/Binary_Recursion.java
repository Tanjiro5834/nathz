package binary_recursion;
import java.util.*;

public class Binary_Recursion {

    public static void main(String[] args) {
        System.out.println("1.");
        
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number higher than 0:");
        int number = scan.nextInt();
        
        if(number <= 0){
            System.out.println("Please enter a number greater than 0.");
        }else{
            for(int i = 0;i < number; i++){
                int res = fib(i);
                System.out.println(res);
            }
        }
    }
    
    public static int fib(int n){
        if(n <= 1){
            return n;
        }else{
            return fib(n - 1) + fib(n - 2);
        }
    }
    
}
