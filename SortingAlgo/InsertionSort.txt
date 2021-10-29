#include <iostream>
using namespace std;
void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int card=arr[i];
        int j=i-1;
        while(j>=0 && card<arr[j]){
           arr[j+1]=arr[j];
           j--;
        }
        arr[j+1]=card;
    }
}
int main(){
    int n=7;
    int arr[n]={2,6,3,2,7,0,1};
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}