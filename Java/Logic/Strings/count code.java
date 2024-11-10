public class Main
{
    public static void main(String[] args) {
       System.out.println(countCode("aaacodebbb"));
    }
    
    static String countCode(String str){
       int count = 0;
       for(int i = 0; i < str.length() - 4; i++){
           if (str.charAt(i) == 'c' && 
            str.charAt(i + 1) == 'o' && 
            str.charAt(i + 3) == 'e') {
            count++;
          }
       }
       return String.valueOf(count);
    }
}
