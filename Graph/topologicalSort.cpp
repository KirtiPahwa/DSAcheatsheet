#include<iostream>
#include<queue>
#include<stack>
#include<vector>
// #include<bits/stdc++.h>
const int N=1e5+2;
using namespace std;
class graph{
    public:
    vector<vector<int>> arr;
    int *indegree;
    int v;
    queue<int> q;
    graph(int);
    void addEdge(int,int);
    void displayGraph();
    void topologicalSortBFS();
    void topologicalSortDFS();
    void findTopoSort(int[],int,stack<int>&);
    ~graph();
};
graph::graph(int v){
        arr.resize(v,vector<int>(v,0));
        indegree=new int(v);
        this->v=v;
        for(int i=0;i<v;i++){
            indegree[i]=0;
        }
        cout<<"Graph Created"<<endl;
}
void graph::addEdge(int m,int n){
    arr[m][n]=1;
    // cout<<m<<endl;
    indegree[n]++;
}
void graph::displayGraph(){
    for(auto x:arr){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
graph::~graph()
{
    cout<<"You destroyed the graph"<<endl;
}
void graph::findTopoSort(int vis[],int j,stack<int>&stk){
    stack<int>s;
    s.push(j);
    while(!s.empty()){
        int node=s.top();
        s.pop();
        vis[node]=1;
        for(int i=0;i<v;i++){
            if(arr[node][i]==1 && !vis[i]){
                s.push(i);
            }
        }
        stk.push(node);
    }
}
void graph::topologicalSortDFS(){
    int vis[v]={0};
    stack<int>stk;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            findTopoSort(vis,i,stk);
        }
    }
    while(stk.empty()!=1){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
}
void graph::topologicalSortBFS(){
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        cout<<node<<" ";
        q.pop();
        for(int i=0;i<v;i++){
            if(arr[node][i]){
                indegree[i]--;
                if(indegree[i]==0){
                q.push(i);
            }
            }
            
        }
    }
    cout<<endl;
}

int main(){
    graph g(6);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.addEdge(4,0);
    g.topologicalSortBFS();
    g.topologicalSortDFS();

    // g.displayGraph();


    return 0;
}