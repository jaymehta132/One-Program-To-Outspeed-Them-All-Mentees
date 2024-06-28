#include <iostream>
using namespace std;

/*

TASK : Implement Radix Sort

Binary radix sort is a non-comparative integer sorting algorithm that sorts data by processing individual bits of the numbers.
The algorithm sorts the numbers by examining each bit from the most significant bit (MSB) to the least significant bit (LSB).
For each bit position, it partitions the numbers into two groups: those with the bit set to 0 and those with the bit set to 1.
This process is repeated for each bit position, and the numbers are merged back together after each bit pass. 
Binary radix sort is efficient for fixed-length integer keys, offering a time complexity of O(n) per pass, where n is the number of elements, 
making it suitable for sorting large datasets of integers.
EXPECTED TIME COMPLEXITY : O(n*log(q)) where q = max(arr)

*/

int getMax(int* arr, int size){
    int max = arr[0];
    for (int i=0; i<size; i++){
        if (arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int* arr, int size, int exp){
    int output[size];
    int count[2] = {0, 0};
    for (int i=0; i<size; i++){
        count[(arr[i]/exp)%2] += 1;
    }
    int i=0;
    int j=count[0];
    for (int k=0; k<size; k++){
        if ((arr[k]/exp)%2==0){
            output[i] = arr[k];
            i++;
        }
        else{
            output[j] = arr[k];
            j++;
        }
    }
    for (int k=0; k<size; k++){
        arr[k] = output[k];
    }
    return;
}

void radixSort (int *arr, int size) {
    
    int max = getMax(arr, size);
    for (int exp=1; max/exp > 0; exp*=2){
        countSort(arr, size, exp);
    }
    
    //cout<<"STUDENT CODE NOT IMPLEMENTED!\n";
    //exit(1);
}

int main () {

    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++) {
        arr[i] = rand();
    }
    radixSort(arr,n);
    for (int i=0; i<n-1; i++) {
        if (arr[i] > arr[i+1]) {
            cout<<"Sorting not done correctly!\n";
            exit(1);
        }
    }
    cout<<"Good job, array is sorted\n";
    return 0;
}