#include<stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter Random Array: ");
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }

    int n= sizeof(arr)/sizeof(arr[0]);
    int swap =0,counter=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            counter++;
            if(arr[j]>arr[j+1]){
                //swapping
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=1;
            }
        }
        //Time Complixity
        if(swap==0){
            break;
        }
    }
    printf("After sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nTotal loop:%d",counter);
    printf("\n");
    return 0;
}