#include<iostream>
#include <vector>
const int N=1e5+2;
using namespace std;
class graph{
    public:
    vector<vector<int>> arr;
    graph(int);
    void addEdge(int,int);
    void displayGraph();
    ~graph();
};
graph::graph(int v){
        arr.resize(v,vector<int>(v,0));
        cout<<"Graph Created"<<endl;
}
void graph::addEdge(int m,int n){
    arr[m][n]=1;
    arr[n][m]=1;
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


int main(){
    graph g(5);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.displayGraph();

    return 0;
}