public class Main
{
    public static void main(String[] args) {
       String word = "hippo", word2 = "hi";
        System.out.println(startWord(word, word2));
       
    }
    
    static String startWord(String str, String word) {
        if(word.length() < 1  || str.length() < word.length()) return "";
        
        String subStr = str.substring(0, word.length());
        
        if(subStr.substring(1).equals(word.substring(1))){
            return subStr;
        }else{
            return "";
        }
    }
}
