function compressString(str){
    let count = 1;
    let sb = [];

    for(let i = 0; i < str.length; i++){
        if(i + 1 < str.length && str.charAt(i) == str.charAt(i + 1)){
            count++;
        }else{
            sb.push(str.charAt(i).push(count));
            if(count > 1){
                sb.push(count);
            }
        }
    }
    return sb.join('');
}

console.log(compressString("aaabccdd"));  
console.log(compressString("abc"));        
console.log(compressString("aabbcc")); 
