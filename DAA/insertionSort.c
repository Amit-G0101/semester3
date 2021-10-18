#include<stdio.h>
void insertionSort(int arr[],int n);
void main(){

  int size;
  printf("enter array's size:");
  scanf("%d",&size);
  int arr[size];

  printf("\nEnter %d elements:\n",size);
  for(int i=0;i<size;i++){

      scanf("%d",&arr[i]);
  }

  insertionSort(arr,size);
  printf("\nAfter applying InsertionSort:\n");
  for(int i=0;i<size;i++){

      printf("%d ",arr[i]);
  }
}

void insertionSort(int arr[],int n){

    for(int i=0;i<n-1;i++){
        int j=i+1;
        int key=arr[j];
          while(j>0){
              if(key<arr[j-1]){
                  arr[j]=arr[j-1];
                  j--;
              }
              else
              break;
          }
       arr[j]=key;
    }
}