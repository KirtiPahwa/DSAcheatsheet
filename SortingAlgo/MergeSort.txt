#include <iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r){
int i=l;
int k=0;
int j=mid+1;
int temp[r+1];
while(i<=mid && j<=r){
    if(arr[i]<=arr[j]){
        temp[k]=arr[i];
        i++;
    }else{
        temp[k]=arr[j];
        j++;
    }
    k++;
}
while(i<=mid){
    temp[k]=arr[i];
    i++;
    k++;
}
while(j<=r){
    temp[k]=arr[j];
    k++;
    j++;
}
for(int i=0;i<=r;i++){
    cout<<temp[i]<<endl;
    arr[i]=temp[k];
}

}
void mergeSort(int arr[],int l,int r){
    if(l<r){
    int mid=l+(r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
    }
}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[7]={2,0,9,5,3,2,6};
    int l=0,r=6;
    mergeSort(arr,l,r);
    printArr(arr,7);
    return 0;
}