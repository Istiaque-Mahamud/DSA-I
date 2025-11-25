#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
int size=sizeof(arr)/sizeof(arr[0]);
//outer loop to iterate over all the numbers
int min_index;
for(int i=0;i<size;i++){
    min_index=i;
    //inner loop to find the minimum index 
    for(int j=i+1;j<size;j++){
        if(arr[j]<arr[min_index]){
            min_index=j;
        }
    }
    //swap two numbers
    int temp=arr[i];
    arr[i]=arr[min_index];
    arr[min_index]=temp;

 }
 //print the sorted array
 for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
 }
 printf("\n");

    return 0;
}