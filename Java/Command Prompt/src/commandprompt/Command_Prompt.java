package commandprompt;
import java.util.Scanner;
import java.io.*;
/**
 *
 * @author Nathaniel
 */
public class Command_Prompt {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("""
                           Microsoft Windows [Version 10.0.19045.5131]
                           (c) Microsoft Corporation. All rights reserved.""");
        while(true){     
             System.out.print("C:\\Users\\User>");
             String command = scanner.nextLine();
             if(command.equalsIgnoreCase("exit")){
                 System.exit(0);
                 break;
             }           
             executeCommand(command);
        }
        scanner.close();
    }
    
    static void executeCommand(String command){
        try{
            ProcessBuilder pb = new ProcessBuilder("cmd", "/c", command);
            Process process = pb.start();
            
            BufferedReader br = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;            
            while((line = br.readLine()) != null){
                System.out.println(line);
            }
            process.waitFor();
        }catch(IOException | InterruptedException e){
            System.out.println("Error executing command: ".concat(e.getMessage()));
        }
    }
}
