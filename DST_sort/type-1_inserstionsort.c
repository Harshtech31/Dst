#include <stdio.h> 
void acceptelem(int arr[], int n) 
{ 
    for(int i =0;i<n;i++) 
    { 
        scanf("%d",&arr[i]); 
    } 
} 
void display(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++)  
    { 
        printf("%d ", arr[i]); 
    } 
} 
void insertionsort(int arr[], int n)  
{ 
    int i, j; 
    for (i = 1; i < n; i++) { 
        int temp = arr[i]; 
        j = i - 1;
        while (j >= 0 && arr[j] > temp) 
        { 
            arr[j + 1] = arr[j]; 
            j = j--; 
        } 
        arr[j + 1] = temp; 
    } 
} 
 
int main() { 
    int n; 
    printf("Enter size of an array"); 
    scanf("%d",&n); 
    int arr[n]; 
    acceptelem(arr,n); 
    insertionsort(arr, n); 
    printf("After sorting "); 
    display(arr,n); 
    printf("\n"); 
    return 0; 
}