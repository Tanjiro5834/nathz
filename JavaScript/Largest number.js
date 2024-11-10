function largestNumber(nums){
    let max = 0
    for(let i = 1; i < nums.length; i++){
        if(nums[i] > max){
            max = nums[i]
        }
    }
    return max
}

let nums = [7, 10, 100, 13]
console.log(nums)
console.log("Largest number in the array: " + largestNumber(nums))