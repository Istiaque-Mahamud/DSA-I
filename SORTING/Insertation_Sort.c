#include<stdio.h>
int main(){
int n;
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}
int value,hole;
int size= sizeof(arr)/sizeof(arr[0]);
for(int i=1;i<5;i++){
    value= arr[i];
    hole=i;

    while(hole>0 && arr[hole-1]>value){
        arr[hole]= arr[hole-1];
        hole--;
    }
    arr[hole]= value;

}
printf("Sorted Array: \n");
for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
}
printf("\n");

    return 0;
}