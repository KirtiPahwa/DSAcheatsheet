#include<bits/stdc++.h>
using namespace std;
vector<int> printConnectedComponents(int node,int** arr,int v,int* vis,vector<int> &ans){
    ans.push_back(node);
    vis[node]=1;
    for(int i=0;i<v;i++){
        if(arr[v][i] && !vis[i]){
            printConnectedComponents(i,arr,v,vis,ans);
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        int** arr=new int*[v];
        for(int i=0;i<v;i++){
            arr[i]=new int[v];
        }
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                arr[i][j]=0;
            }
        }
        int m,n;
        for(int i=0;i<e;i++){
            cin>>m>>n;
            cout<<e<<endl;
            arr[m][n]=1;
            arr[n][m]=1;
        }
        

        int* vis=new int[v];
        for(int i=0;i<v;i++){
            vis[i]=0;
        }
        vector<int>ans;
        for(int i=0;i<v;i++){
            cout<<i<<endl;
            if(!vis[i]){
               ans=printConnectedComponents(i,arr,v,vis,ans);
               cout<<ans.size()<<" ";
                for(int i=0;i<ans.size();i++){
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
            }
        } 
    }
    return 0;
}