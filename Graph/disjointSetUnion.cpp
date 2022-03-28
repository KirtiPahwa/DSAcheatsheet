#include<iostream>
#include<map>
using namespace std;
class DSNode{
    public:
    int data;
    DSNode* parent;
    int rank;
};
class DisjointSet{
    private:
    map<int,DSNode*> hash;
    public:
    void intialisedSet(int n){
        DSNode* node= new DSNode();
        node->data=n;
        node->parent=node;
        node->rank=0;  
        hash[n]=node;
    }
    DSNode* searchInSetHelper(DSNode* node){
        if(node==node->parent){
            return node;
        }
        node->parent=searchInSetHelper(node->parent);
        return node->parent;
    }
    void Union(int data1,int data2){
        DSNode* node1=hash[data1];
        DSNode* node2=hash[data2];
        DSNode* parent1=searchInSetHelper(node1);
        DSNode* parent2=searchInSetHelper(node2);
        if(parent1->data==parent2->data){
            return;
        }
        if(parent1->rank>=parent2->rank){
            if(parent1->rank==parent2->rank){
                parent1->rank=parent1->rank+1;
            }
            parent2->parent=parent1;
        }else{
            parent1->parent=parent2;
        }
    }
    int searchInSet(int data){
        return searchInSetHelper(hash[data])->data;
    }
};
int main(){
    DisjointSet d;
    d.intialisedSet(0);
    d.intialisedSet(1);
    d.intialisedSet(2);
    d.intialisedSet(3);
    d.intialisedSet(4);
    d.intialisedSet(5);
    d.intialisedSet(6);
    d.intialisedSet(7);
    
    d.Union(0,1);
    d.Union(1,2);
    d.Union(3,4);
    d.Union(2,4);
    d.Union(5,6);
    d.Union(4,6);

    cout<<d.searchInSet(5)<<endl;
    cout<<d.searchInSet(7)<<endl;


    return 0;
}