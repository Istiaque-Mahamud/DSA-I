#include<stdio.h>
void ArraySort(int n[],int Size){
    int swap=0,count=0;
    for(int i=0;i<Size-1;i++){
        for(int j=0;j<Size-i-1;j++){
            count++;
            if(n[j]>n[j+1]){
                //swapping
                int temp=n[j];
                n[j]=n[j+1];
                n[j+1]=temp;
                swap=1;
            }
        }
        if(swap==0){
            break;
        }
    }
    for(int i=0;i<Size;i++){
        printf("%d ",n[i]);
    }
    printf("\nTotal loop:%d",count);
    
}
int main(){
    int num;
    printf("Enter a Random Number: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter a Random Array: ");
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    int size= sizeof(arr)/sizeof(arr[0]);

    ArraySort(arr,size);
    return 0;
}