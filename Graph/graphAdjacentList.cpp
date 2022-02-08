#include <iostream>
#include<list>
using namespace std;

const int N=1e5+2;
class graph
{
private:
    list<int> *arr;
    int *size;
public:
    graph(int);
    ~graph();
    void addEdge(int,int);
    void displayGraph();
};

graph::graph(int size)
{
    arr=new list<int>[size];
    this->size=&size;
    cout<<"Graph created"<<endl;
}

graph::~graph()
{
    cout<<"You destroyed the graph"<<endl;
}

void graph::addEdge(int u,int v){
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void graph::displayGraph(){
    for(int i=0;i<(*size);i++){
        cout<<i<<"->";
        for(int j:arr[i]){
            cout<<j<<",";
        }
        cout<<endl;
    }
}


int main(){
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.displayGraph();


    return 0;
}