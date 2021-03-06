#include<iostream>
using namespace std;
class dLL
{
 	  public:
	   int data;
	   dLL* prev;
	   dLL* next;
	   dLL *ps, *pe, *q;											
	   dLL()
	   {
	   		ps=NULL;
	   		pe=NULL;
	   }
	   void insert_end();
	   void search();
	   void insert_begin();
	   void display_forward();
	   void display_backward();
       void insert_random();
	   void delete_end();	
	   void delete_random();
	   void delete_begin();
};
void dLL::search(){
	int data,i=1;
	q=ps;
	cout<<"Enter which number you want to search: ";
	cin>>data;
	while(q!=NULL){
		if(q->data==data){
			cout<<"Node of "<<data<<" is found at index "<<i<<endl;
			return;
		}
		i++;
	}
	cout<<"No node of "<<data<<"is found"<<endl;
}
void dLL::insert_end()
{
	dLL *temp;
	int data;
	temp=new dLL;
	cout<<"Enter data to insert at end: ";
	cin>>data;
	temp->data=data;
	temp->prev=NULL;
	temp->next=NULL;
	if(ps==NULL)
	{
	     ps=temp;  // ps is of obj which is calling this insert end funtion 
	     pe=temp;
	     return;
    }
    else
    {
    	//q=pe;
		pe->next=temp;
		temp->prev=pe;
		pe=pe->next;
	}
}

void dLL::insert_begin()
{
	dLL *temp;
	int data;
	temp=new dLL;
	cout<<"Enter data to insert at begin: ";
	cin>>data;
	temp->data=data;
	temp->prev=NULL;
	temp->next=NULL;
	if(ps==NULL)
	{
	     ps=temp;
	     pe=temp;
	     return;
    }
    else
    {
    	//q=pe;
		ps->prev=temp;
		temp->next=ps;
		ps=ps->prev;
	}
}

void dLL::insert_random(){
    int i,index;
    dLL *temp;
	int data;
	temp=new dLL;
    cout<<"Do you want to insert from beginning (Enter 1) and (Enter 0) to insert from End";
    cin>>i;
    if(i==1){
        cout<<"Enter the Index where you want to insert new NODE";
        cin>>index;
        q=ps;
        while(index>1){
            q=q->next;
            index--;
        }
        
	cout<<"Enter data to insert at begin: ";
	cin>>data;
	temp->data=data;
	temp->prev=NULL;
	temp->next=NULL;
    q->next->prev=temp;
    temp->next=q->next;
    q->next=temp;
    temp->prev=q;
    }
	
	else if(i==0){
        cout<<"Enter the Index where you want to insert new NODE";
        cin>>index;
		q=pe;
		while(index>2){
			q=q->prev;
			index--;
	}
	cout<<"Enter data to insert at end: ";
	cin>>data;
	temp->data=data;
	temp->prev=NULL;
	temp->next=NULL;
	q->prev->next=temp;
	temp->next=q;
	temp->prev=q->prev;
	q->prev=temp;
    }
}

void dLL::delete_end(){
	pe=pe->prev;
	delete pe->next;
	pe->next=NULL;

}
void dLL::delete_begin(){
	ps=ps->next;
	delete ps->prev;
	ps->prev=NULL;
}

void dLL::delete_random(){
	int pos,i=1;
	cout<<"Enter position where you want to delete: ";
	cin>>pos;
	while(i<pos-1){
		i++;
		q=q->next;
	}
	dLL* temp=q->next;
	q->next=q->next->next;
	delete temp;
	q->next->prev=q;
}

void dLL::display_forward()
{
	q=ps;
	while(q->next!=NULL) 
	{
	      cout<<q->data<<" -> ";
	      q=q->next;
    }
    cout<<q->data;
 
}

void dLL::display_backward()
{
	q=pe;
	while(q->prev!=NULL)
	{
		cout<<q->data<<" -> ";
		q=q->prev;
	}
	cout<<q->data;
}


int main()
{
	dLL obj1;
	int i=1,c;
	cout<<endl;
	while(i)
	{
	cout<<"Enter 1 to Insert an element at end of LL"<<endl;
	cout<<"Enter 2 to Insert an element at begin of LL"<<endl;
	cout<<"Enter 3 to Insert an element randomly of LL"<<endl;
	cout<<"Enter 4 to delete a last element of LL"<<endl;
	cout<<"Enter 5 to delete a first element of LL"<<endl;
	cout<<"Enter 6 to delete a first element of LL"<<endl;
	cout<<"Enter 7 to search a  element of dLL"<<endl;
	cin>>c;
	switch (c)
	{
		case 1:
			obj1.insert_end();
			cout<<endl;
			obj1.display_forward();
			cout<<endl;
			obj1.display_backward();
			break;
		case 2:
			obj1.insert_begin();
			cout<<endl;
			obj1.display_forward();
			cout<<endl;
			obj1.display_backward();
			break;
	    case 3:
		obj1.insert_random();
		cout<<endl;
		obj1.display_forward();
		cout<<endl;
		obj1.display_backward();
		cout<<endl;
		case 4:
		obj1.delete_end();
		cout<<endl;
		obj1.display_forward();
		cout<<endl;
		obj1.display_backward();
		cout<<endl;
		case 5:
		obj1.delete_begin();
		cout<<endl;
		obj1.display_forward();
		cout<<endl;
		obj1.display_backward();
		cout<<endl;
		case 6:
		obj1.delete_random();
		cout<<endl;
		obj1.display_forward();
		cout<<endl;
		obj1.display_backward();
		cout<<endl;
		case7:
		obj1.search();
	}
	
	
	cout<<endl<<endl<<"Do you want to Continue: 1(Yes) and 0(No)";
	cin>>i;
	}
	
}
