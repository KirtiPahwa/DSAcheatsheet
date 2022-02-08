#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtEnd(Node* &head,int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void insertAtBegin(Node* &head,int val){
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;
}
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;

}
void insertAtRandomPostion(Node* &head,int pos,int val){
    Node * newNode=new Node(val);
    Node * temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void search(Node* head,int key){
    int position=1;
    while(head->next!=NULL){
        if(head->data==key){
            cout<<"key: "<<key<<" is present at "<<position<<endl;
            return;
        }
        head=head->next;
        position++;
    }
    return;
} 
void insertSorted(Node* head,int val){
    Node* newNode=new Node(val);
    while(head->data<val){
        head=head->next;
    }
    newNode->next=head->next;
    head->next=newNode;
}
void insertAtmiddle(Node* head,int val){
    Node *temp=head;
    int n=0;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    
}
void deleteFirst(Node* &head){
    if(head==NULL){
        return;
    }
    Node *tobeDelete=head;
    head=head->next;
    delete tobeDelete;
}
void deleteRdm(Node *head,int pos){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        if(pos>1){
            cout<<"There is only one node";
            return;
        }else{
            delete head;
            head=NULL;
            return;
        }
    }
    Node *temp=head;
    int i=1;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    Node* tobeDelete=temp->next;
    temp->next=temp->next->next;
    delete tobeDelete;
    return;
}
void deleteEnd(Node * &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }
    Node * temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node* tobeDelete=temp->next;
    temp->next=NULL;
    delete tobeDelete;
    return;
}
void reverse(Node*&head){
    Node*pre=NULL;
    Node*current=head;
    Node*next;
    while(current!=NULL){
        next=current->next;
        current->next=pre;
        pre=current;
        current=next;
    }
    head=pre;
}
void reverseSublinkedList(Node *&head){
    int n=0;
    Node *temp=head;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    int m=n/2,mid;
    temp=head;
    mid=m;
    while(mid>1){
        temp=temp->next;
        mid--;
    }
    reverse(temp->next);
}
Node* recursiveReverse(Node * head,Node*pre,Node*nex){
    if(head->next==NULL){
        head->next=pre;
        return head;
    }
    head->next=pre;
    head=recursiveReverse(nex,head,nex->next);
    return head;
}
Node * recursiveReverseAnotherApproach(Node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *newHead=recursiveReverseAnotherApproach(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}


int main(){
    Node* head=NULL;
    for(int i=5;i>0;i--){
        insertAtBegin(head,i);
    }    
    return 0;
}