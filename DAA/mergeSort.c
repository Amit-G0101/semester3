#include<stdio.h>
void mergeSort(int arr[],int low, int high);
void merge(int arr[],int low,int mid,int high);
void main(){

  int size;
  printf("enter array's size:");
  scanf("%d",&size);
  int arr[size];

  printf("\nEnter %d elements:\n",size);
  for(int i=0;i<size;i++){

      scanf("%d",&arr[i]);
  }

  mergeSort(arr,0,size-1);
  printf("\nAfter applying MergeSort:\n");
  for(int i=0;i<size;i++){

      printf("%d ",arr[i]);
  }
}

void mergeSort(int arr[],int low, int high){

    if(low<high){
      int mid= (low+high)/2;
       mergeSort(arr,low,mid);
       mergeSort(arr,mid+1,high);

       merge(arr,low,mid,high);

    }

}
 void merge(int arr[],int low,int mid,int high){
    int mixlen=high-low+1;
    int mix[mixlen];
    int i,j,k;
    i=low;
    j=mid+1;
    k=0;
    while(i<=mid && j<=high){
      
      if(arr[i]<arr[j]){
          mix[k]=arr[i];
          i++;
      }
      else{
          mix[k]=arr[j];
          j++;
      }
      k++;

    }

    while(i<=mid){
        mix[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high){
        mix[k]=arr[j];
        j++;
        k++;
    }
    // copying from merge array into original array
    for(int i=0;i<mixlen;i++){

        arr[low++]=mix[i];
        
    }



}

