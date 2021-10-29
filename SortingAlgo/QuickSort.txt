#include <iostream>
using namespace std;
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int partition(int arr[],int l,int r){
    int pivot=arr[0];
    int i=1;
    int j=r-1;
    int temp;
    while(i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    arr[0]=arr[j];
    arr[j]=pivot;
    printArr(arr,7);
        return j;
}

void quickSort(int arr[],int l,int r){
    int pivotPos;
    if(l<r){
        pivotPos=partition(arr,l,r);
        quickSort(arr,l,pivotPos-1);
        quickSort(arr,pivotPos+1,r);
    }
}

int main(){
    int t;int *arr;int n;
    cin>>t;
    while(t--){
        cin>>n;
        arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int l=0;
        int r=n-1;
        quickSort(arr,l,r);
        printArr(arr,n);
    }
    return 0;
}