#include <stdio.h>

int numbers[10];
int size = 10; 

// function prototypes
void swap(int *arr, int index1, int index2);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void s2(int *a, int *b);

int main(){
    int running = 1;
    while (running){
        const char *choices[] = {"Add items to array", "Remove an element from array", "View array items", "Swap indexes", "Reverse order", "Sort"};
        for(int i=0; i<6; i++){
            printf("%d. %s\n", i+1, choices[i]);
        }
        printf("Enter option here: ");
        int desire;
        scanf("%d", &desire);
        switch (desire){
            case 1:
                printf("Enter 10 numbers to add to array: ");
                for(int j=0; j<size; j++){
                    scanf("%d", &numbers[j]);
                }

                printf("Numbers added. Numbers stored:\n");
                for (int i=0; i<size; i++){
                    printf("%d ", numbers[i]);
                }
                printf("\n");
                break;

            case 2:
                printf("Enter index to remove: ");
                int index;
                scanf("%d", &index);
                if (index<0 || index>=size){
                    printf("Invalid index!\n");
                    break;
                }
                for(int k=index; k<size-1; k++){
                    numbers[k] = numbers[k + 1];
                }
                size--;

                printf("Number at index %d has been removed.\n", index);
                break;

            case 3:
                printf("All items in the array:\n");
                for (int l=0; l<size; l++){
                    printf("%d ", numbers[l]);
                }
                printf("\n");
                break;

            case 4:
                printf("Enter two indexes to swap: ");
                int num1, num2;
                scanf("%d %d", &num1, &num2);
                if (num1 < 0 || num1 >= size || num2 < 0 || num2 >= size){
                    printf("Invalid indexes!\n");
                    break;
                }
                swap(numbers, num1, num2);
                printf("Numbers have been swapped. Result:\n");
                for (int i=0; i<size; i++){
                    printf("%d ", numbers[i]);
                }
                printf("\n");
                break;

            case 5:
                for (int m = 0, n = size - 1; m < n; m++, n--){
                    int temp = numbers[m];
                    numbers[m] = numbers[n];
                    numbers[n] = temp;
                }
                printf("Reversed array order:\n");
                for (int p =0;  p<size; p++){
                    printf("%d ", numbers[p]);
                }
                printf("\n");
                break;

            case 6:
                quickSort(numbers, 0, size - 1);
                printf("Sorted Array: ");
                for (int i = 0; i < size; i++){
                    printf("%d ", numbers[i]);
                }
                printf("\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}

void swap(int *arr, int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void s2(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            s2(&arr[i], &arr[j]);
        }
    }
    s2(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}
