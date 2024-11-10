package insertionsort;
import java.util.Scanner;
import java.util.Random;

public class InsertionSort {

    private static Scanner scan = new Scanner(System.in);
    private static Random rand = new Random();
    
    public static void main(String[] args) {
        System.out.print("Enter an option:\n1. Sort Numbers\n2. Resort Numbers\n3. Exit");
        String choice = scan.next();
        if(choice.equalsIgnoreCase("exit")){
            System.out.println("Exiting the program...");
            System.exit(0);
        }else if(choice.equals("s")){
           sortNums();
        }else if(choice.equals("r")){
            resortNums();
        }else{
            System.out.println("Invalid response. Please try again.");
        }     
    }
    
    public static void sortNums(){
        System.out.print("Enter limit e.g (10):");
        int limit = scan.nextInt();
        
        System.out.println("Enter how many numbers are to be generated:");
        int randomized = scan.nextInt();
        
        int[]randomNums = new int[randomized];
        
        System.out.println("Generated numbers:");
        for(int i = 0; i < randomized; i++){
            randomNums[i] = rand.nextInt(limit)+1;
            System.out.println(randomNums[i]+"");
        }
        System.out.println();
        
        insertionSort(randomNums);
        
        System.out.println("Sorted version:");
        for(int n : randomNums){
            System.out.print(n+"");
        }
        
    }
    
    public static void resortNums(){
        
        
    }
    public static void insertionSort(int[]inputArr){
        for(int i = 1; i < inputArr.length; i++){ // first element is sorted, so we start with the next element
            int temp = inputArr[i];
            int j = i - 1; //walk back towards the beggining of the array
            
            // j<= 0: pine prevent nito tayong mag walk back pa once na ma reach na natin yung simula nang array
            // inputArr[j] > temp: let's us walk back papuntang pinaka simula nang array and titigil lang if na reach na natin yung simula nang array or if maka encounter tayo ng value na less than or equal sa value (temp)  na gusto nating i-insert
            while(j >= 0 && inputArr[j] > temp){
                inputArr[j + 1] = inputArr[j];
                j--;
            }
            inputArr[j + 1] = temp;
        }
    }
    
}
