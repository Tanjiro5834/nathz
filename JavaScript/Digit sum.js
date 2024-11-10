function digitSum(nums){
    let sum = 0
    for(let i = 0; i < nums.length; i++){
        sum += nums[i]
    }
    return sum
}

let nums = [1, 2, 3, 4]
let sum = digitSum(nums)
console.log("Sum of the digits: " + sum)