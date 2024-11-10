
package fruitbasket;
import java.util.Stack;
import java.util.Scanner;

public class FruitBasket {

    
    public static void main(String[] args) {
         Stack<String> basket = new Stack();
         Scanner s = new Scanner(System.in);
         
         System.out.println("Enter amount of fruits to catch:");
         int amount = s.nextInt();
         
         basket.push("Apple");
         basket.push("Orange");
         basket.push("Mango");
         basket.push("Guava");
         
         System.out.println(basket);
         for(int i=0;i<amount;i++){
             System.out.println("Press A for apple, O for orange, M for mango, and G for guava:");
             char pick = s.next().charAt(0);
             switch(pick){
                 case 'A':
                     System.out.println("Apple");
                     break;
                 case 'O':
                     System.out.println("Orange");
                     break;
                 case 'M':
                     System.out.println("Mango");
                     break;
                 case 'G':
                     System.out.println("Guava");
                     break;
                 default:
                     System.out.println("Invalid input! Please try again.");
                     break;
             }
             System.out.println("You chose "+pick+".");
         }
         while(!basket.isEmpty()){
             System.out.println("Press E to eat a fruit.");
             char eat = s.next().charAt(0);
             if(eat == 'E'){
                 basket.pop();
                 System.out.println(basket);
             }
         }
         System.out.println("No more fruits.");
    }
    
}
