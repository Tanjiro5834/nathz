
package infixtopostfix_viceversa;
import java.util.Stack;
import java.util.Scanner;

public class InfixToPostFix_ViceVersa {

    
    private static boolean isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '/' || ch == '*';
}
    public static String infixToPostfix(String infix){
        StringBuilder postfix = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        
        for(char ch:infix.toCharArray()){
            if(Character.isLetterOrDigit(ch)){
                postfix.append(ch);
            }else if(isOperator(ch)){
                while(!stack.isEmpty() && stack.peek()!='(' && getPrecedence(stack.peek())>=getPrecedence(ch)){
                    postfix.append(stack.pop());
                }
                stack.push(ch);
            }else if(ch == '('){
                stack.push(ch);
            }else if(ch == ')'){
                while(!stack.isEmpty() && stack.peek()!='('){
                    postfix.append(stack.pop());
                }
                stack.pop();
            }
        }
        while(!stack.isEmpty()){
            postfix.append(stack.pop());
        }
        return postfix.toString();
    }
     
    private static int getPrecedence(char op){
        switch(op){
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
                
        }
        return 0;
    }
    
    public static String postfixToinfix(String postfix){
        Stack<String> stack = new Stack<>();
        for(char ch:postfix.toCharArray()){
            if(Character.isLetterOrDigit(ch)){
                stack.push(String.valueOf(ch));
            }else if(isOperator(ch)){
                String operand2 = stack.pop();
                String operand1 = stack.pop();
                String result = "(" + operand1 + ch + operand2 + ")";
                stack.push(result);
            }
        }
        return stack.pop();
    }
    
    public static void main(String[] args){
        boolean isRunning = true;
        while(isRunning){
            Scanner console = new Scanner(System.in);
        System.out.println("Choose an operation:");
        System.out.println("1. Infix to Postfix");
        System.out.println("2 Postfix to Infix");
        
        int choice = console.nextInt();
        console.nextLine();
        
        if(choice == 1){
            System.out.println("Enter an infix expression:");
            String infix = console.nextLine();
            String postfix = infixToPostfix(infix);
            System.out.println("Postfix Expression: "+postfix);
        }else if(choice == 2){
            System.out.println("Enter a postfix expression: ");
            String postfix = console.nextLine();
            String infix = postfixToinfix(postfix);
            System.out.println("Infix Expression : "+infix);
        }else{
            System.out.println("Invalid choice.");
        }
        if(isRunning == false){
            break;
        }
    }
        
   }
}
