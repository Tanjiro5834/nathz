public class Main
{
    public static void main(String[] args) {
       String word = "the";
       System.out.println(doubleChar(word));
    }
    
    static String doubleChar(String str){
        String result = "";
        
        for(char c : str.toCharArray()){
            result += c + "" + c;
        }
        
        return result;
    }
}
