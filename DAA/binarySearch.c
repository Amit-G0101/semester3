#include<stdio.h>
int binarySearch(int arr[],int size,int key);
void main(){

  int size,key,indexFound=-1;
  printf("enter array's size:");
  scanf("%d",&size);
  int arr[size];

  printf("\nEnter %d elements in ascending order:\n",size);
  for(int i=0;i<size;i++){

      scanf("%d",&arr[i]);
  }
  printf("\nEnter element to be searched: ");
  scanf("%d",&key);

  indexFound=binarySearch(arr,size,key);
  if(indexFound>-1){
   printf("%d found at index[%d]",key,indexFound);
  }
  else
  printf("%d doesnot exist in the array",key);
  

}

int binarySearch(int arr[],int size,int key){

    if(size<1){
        return -1;
    }

    int start=0;
    int end=size-1;
    int mid=0;
    while(start<end){

        mid=(start+end)/2;

        if(key==arr[mid]){
            return mid;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}
