#include<stdio.h>
void quickSort(int arr[],int low,int high);
int partiton(int arr[],int low,int high);
void swap(int arr[],int index1,int index2);
void main(){

  int size;
  printf("enter array's size:");
  scanf("%d",&size);
  int arr[size];

  printf("\nEnter %d elements:\n",size);
  for(int i=0;i<size;i++){

      scanf("%d",&arr[i]);
  }

  quickSort(arr,0,size-1);
  printf("\nAfter applying QuickSort:\n");
  for(int i=0;i<size;i++){

      printf("%d ",arr[i]);
  }
}

void quickSort(int arr[],int low,int high){

    if(low<high){

        int piv=partiton(arr,low,high);
        quickSort(arr,low,piv-1);
        quickSort(arr,piv+1,high);
    }
}

int partiton(int arr[],int low,int high){

    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j){

        while(i<=high && arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr,i,j);
        }
    }
    swap(arr,low,j);
    return j;
}
void swap(int arr[],int index1,int index2){

    int temp=arr[index1];
    arr[index1]=arr[index2];
    arr[index2]=temp;
}