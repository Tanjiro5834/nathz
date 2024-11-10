#include <iostream>

using namespace std;

int secondLargest(int arr[]);

int secondLargest(int arr[], int size){
    int largest = arr[0];
    int secondlargest = arr[1];
    
    if(size < 2) return -1;
    
    for(int i = 0; i < size; i++){
        if(arr[i] > largest){
            secondlargest = largest;
            largest = arr[i];
        }else if(arr[i] > secondlargest && arr[i] != largest){
            secondlargest = arr[i];
        }
    }
    return secondlargest;
}

int main(){
    int array[] = {1,5,3,10,9,6,8};
    int size = sizeof(array) / sizeof(array[0]);
    
    cout << "Array:" << endl;
    for(int i : array){
        cout << i << " ";
    }
    cout << endl;
    cout << "Second largest number in the array: " << secondLargest(array, size) << endl;
    return 0;
}

