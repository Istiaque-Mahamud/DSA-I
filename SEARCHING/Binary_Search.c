#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int size= sizeof(arr)/sizeof(arr[0]);
    printf("Enter Search Item: ");
    int SearchItem;
    scanf("%d",&SearchItem);

    int left=0;
    int right=size-1;
    int middle;
    while(left<=right){
    middle=(left+right)/2;
    if(arr[middle]==SearchItem){
        printf("Item found at index: %d\n",middle);
        return 0;
    }else if(arr[middle<SearchItem]){
        left=middle+1;

    }else{
        right =middle-1;
    }

    }
    printf("Item not found\n");
    return 0;
}