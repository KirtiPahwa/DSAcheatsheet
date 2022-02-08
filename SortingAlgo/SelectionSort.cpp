#include<iostream>       // sort() to sort function
using namespace std;
void selectionSort(int arr[],int n){
    int a=0,min,sorted;
    for(int i=0;i<n-1;i++){
        min=i;
        a++;
        sorted=1;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
            if(arr[j-1]>arr[j]){
                sorted=0;
            }
        }
        if(sorted){
            break;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

int main(){
    int arr[]={2,3,0,1,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    return 0;       
}