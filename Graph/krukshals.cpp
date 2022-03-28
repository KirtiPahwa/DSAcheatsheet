#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src;
    int des;
    int wei;
};
int getParent(int *parent,int node){
    if(node==parent[node]){
        return node;
    }
    return getParent(parent,parent[node]);
}
bool comp(Edge a,Edge b){
    return a.wei<b.wei;
}
int krushkalAlgo(Edge* edge,int e,int v){
    sort(edge,edge+e,comp);
        int *parent=new int[v];
        for(int i=0;i<v;i++){
            parent[i]=i;
        }
        Edge* ans=new Edge[v-1];
        int i=0;
        int j=0;
        int count=0;
        while(count!=v-1){
            int srcParent=getParent(parent,edge[i].src);
            int desParent=getParent(parent,edge[i].des);
            if(srcParent!=desParent){
                ans[j]=edge[i];
                parent[edge[i].des]=srcParent;
                    j++;
                    count++;
            }
            i++;
        }
        int sum=0;
        cout<<v-1<<endl;
        for(int i=0;i<v-1;i++){
            cout<<ans[i].src<<" "<<ans[i].des<<" "<<ans[i].wei<<endl;
            sum+=ans[i].wei;
        }
        return sum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        Edge* edge=new Edge[e];
        
        for(int i=0;i<e;i++){ 
            cin>>edge[i].src>>edge[i].des>>edge[i].wei;
        }
        cout<<krushkalAlgo(edge,e,v)<<endl;
    }
   
    return 0;
}