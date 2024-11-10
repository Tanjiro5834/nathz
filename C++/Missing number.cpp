#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>arr, int n);

int missingNumber(vector<int> arr, int n){
    int expectedSum = (n + 1) * (n + 2) / 2; 
    int actualSum = 0;
    
    for(int x : arr){
        actualSum += x;
    }
    
    int missing_number = expectedSum - actualSum;
    
    return missing_number;
}

int main(){
    vector<int> nums = {1,2,4,5,6};
    int n = nums.size();

    cout << "Missing number: " << missingNumber(nums, n) << endl;
}