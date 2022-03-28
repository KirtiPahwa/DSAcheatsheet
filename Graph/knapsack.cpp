#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b){
    double c=((double)a.second/a.first);
    double d=((double)b.second/b.first);
    return c>d;
}
int knapsack(vector<pair<int,int>>v,int n,int c){
    sort(v.begin(),v.end(),compare);
    int weight=0;
    int profit=0;
    for(int i=0;i<n;i++){
    if(v[i].first<=c){
    c-=v[i].first;
    profit+=v[i].second;
    }else{
        profit+=((double)v[i].second/v[i].first)*c;
        break;
    }
    }
    return profit;
    }

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    int capacity;
    cin>>capacity;
    cout<<knapsack(v,n,capacity)<<endl;

    return 0;
}