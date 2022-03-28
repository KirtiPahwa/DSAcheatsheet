#include<iostream>
#include <vector>
#include <stack>
const int N=1e5+2;
using namespace std;
class graph{
    public:
    vector<vector<int>> arr;
    graph(int);
    void addEdge(int,int);
    void displayGraph();
    bool checkGraphConnectedDFS();
    void checkThroughDFS(int[],int);
    ~graph();
};
graph::graph(int v){
        arr.resize(v,vector<int>(v,0));
        cout<<"Graph Created"<<endl;
}
void graph::addEdge(int m,int n){
    arr[m][n]=1;
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
bool graph::checkGraphConnectedDFS(){
    int vis[arr.size()]={0};
    for(int i=0;i<arr.size();i++){
        if(!vis[i]){
            checkThroughDFS(vis,i);
        }
    }
    for(int i=0;i<arr.size();i++){
        if(!vis[i]){
            return 0;
        }
    }
    return 1;
}

void graph::checkThroughDFS(int vis[],int node){
    stack<int>s;
    s.push(node);
    vis[node]=1;
    while(!s.empty()){
        int n=s.top();
        s.pop();
        for(int i=0;i<arr.size();i++){
            if(arr[n][i] && !vis[i]){
                s.push(i);
                vis[i]=1;  
            }
        }
    }
}


int main(){
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(3,2);
    g.addEdge(0,3);
    cout<<g.checkGraphConnectedDFS()<<endl;


    return 0;
}