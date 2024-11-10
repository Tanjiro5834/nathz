public class Main
{
    public static void main(String[] args) {
       String word = "blueTimes";
       System.out.println(seeColor(word));
    }
    
    static String seeColor(String str){
        if(str.startsWith("red")){
            return "red";
        }else if(str.contains("blue")){
            return "blue";
        }else{
            return "";
        }
    }
}
