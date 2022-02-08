#include <iostream>
#include<list>
#include<queue>
using namespace std;

const int N=1e5+2;
class graph
{
private:
    list<int> *arr;
    int len;
public:
    graph(int);
    ~graph();
    void addEdge(int,int);
    void displayGraph();
    void bfsTraversal();
};

graph::graph(int size)
{
    arr=new list<int>[size+1];
    len=size+1;
    cout<<"Graph created"<<endl;
}

graph::~graph()
{
    cout<<"You destroyed the graph"<<endl;
}

void graph::addEdge(int u,int v){
    arr[u].push_back(v);
}

void graph::displayGraph(){
    for(int i=1;i<=(len+1);i++){
        cout<<i<<"->";
        for(int j:arr[i]){
            cout<<j<<",";
        }
        cout<<endl;
    }

}

void graph::bfsTraversal(){
    int vis[len+1]={0};
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int a=q.front();
        cout<<a<<" ";
        q.pop();
        for(int i: arr[a]){
            if(!vis[i]){
            vis[i]=1;
            q.push(i);
            }
        }
    }
    cout<<endl;
}



int main(){
    graph g(5);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(3,2);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(4,5);

    // g.displayGraph();
    g.bfsTraversal();


    return 0;
}