#include<stdio.h>
int main(){
    int n;
    printf("Enter a Random Array Size: ");
    scanf("%d",&n);
    printf("Enter Array Numbers: \n");
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int size=sizeof(arr)/sizeof(arr[0]);
    int SearchItem;
    printf("Enter a number for search: ");
    scanf("%d",&SearchItem);
    for(int i=0;i<size;i++){
        if(arr[i]==SearchItem){
            printf("Item found at index: %d\n",i);
            //return 0;
        }
    }
    printf("Item not found\n");


    return 0;
}