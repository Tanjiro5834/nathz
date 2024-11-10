function vowelCount(str){
    let count = 0
    for(let i = 0; i < str.length; i++){
        var ch = str.charAt(i)
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                count++
        }
    }
    return count
}

console.log(vowelCount("hello world"))
