#include<stdio.h>
void ArraySort(int n[],int Size){
    for(int i=0;i<Size-1;i++){
        for(int j=0;j<Size-i-1;j++){
            if(n[j]>n[j+1]){
                //swapping
                int temp=n[j];
                n[j]=n[j+1];
                n[j+1]=temp;
            }
        }
    }
    for(int i=0;i<Size;i++){
        printf("%d ",n[i]);
    }


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