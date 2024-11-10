function palindromeCheck(str){
    let left = 0
    let right = str.length - 1
    while(left < right){
        if(str.charAt(left) != str.charAt(right)){
            return false
        }
        left++
        right--
    }
    return true
}

var word = "awesome"
if(palindromeCheck(word)){
    console.log("The word is palindrome.")
}else{
    console.log("The word is not a palindrome.")
}