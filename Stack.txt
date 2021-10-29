#include<iostream>
#include <cmath>
#include <cstring>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
    }
};
class Stack{
    Node *top;
    int size;
    public:
    Stack(){
        top=NULL;
        size=10;
    }
    bool isfull();
    bool isempty();
    void push(int data);
    int pop();
    void display();
    bool isNumber(char a);
    int postfix_eval(char * arr);
    int prefix_eval(char* arr);
    void infixTopostfix(char * arr,char* final);
};
bool Stack::isNumber(char a){
    return a>='0' && a<='9';
}
int Stack::postfix_eval(char *arr)
{
	Stack s;
	int n=strlen(arr);
	for(int i=0;i<n;i++)
	{
		if(isNumber(arr[i])){
		      s.push(arr[i]-'0');
        }
        else
        {
        	int a,b;
        	b=s.pop();
        	a=s.pop();
        	switch (arr[i])
        	{
        		case '^':
       			case '$':
       				s.push(pow(a,b));
       				break;
		        case '*':
		        	s.push(a*b);
		        	break;
	        	case '/':
		        	s.push(a/b);
		        	break;
	        	case '+':
		        	s.push(a+b);
		        	break;
	        	case '-':
		        	s.push(a-b);
		        	break;
			}
		}
	}
	return s.pop();
}
int Stack::prefix_eval(char *arr)
{
	Stack s;
	int n=strlen(arr);
	for(int i=n-1;i>=0;i++)
	{
		if(isNumber(arr[i]))
		      s.push(arr[i]-'0');
        else
        {
        	int a,b;
        	a=s.pop();
        	b=s.pop();
        	switch (arr[i])
        	{
        		case '^':
       			case '$':
       				s.push(pow(a,b));
       				break;
		        case '*':
		        	s.push(a*b);
		        	break;
	        	case '/':
		        	s.push(a/b);
		        	break;
	        	case '+':
		        	s.push(a+b);
		        	break;
	        	case '-':
		        	s.push(a-b);
		        	break;
			}
		}
	}
	return s.pop();
}
bool Stack::isempty(){
    return top==NULL;
}
void Stack::push(int data){
    cout<<data<<" is pushed in the stack"<<endl;
    Node* temp=new Node(data);
    temp->next=top;
    top=temp;
    size++;
    return;
}
bool is_operand(char a){
    if((a>='0' && a<='9') || (a>='a' && a<='z') || (a>='A' && a<='Z')){
        return true;
    }
    return false;
}
int check_precedence(char a){
    if(a=='$' || a=='^'){
        return 3;
    }else if(a=='*' || a=='/'){
        return 2;
    }else if(a=='+' || a=='-'){
        return 1;
    }
}
void Stack::infixTopostfix(char * arr,char * final){
    int j=0;
    int n=strlen(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;    
        if(is_operand(arr[i])){
            final[j++]=arr[i];
        }else if(arr[i]=='('){
            push(arr[i]);
        }else if(arr[i]==')'){
            while(top->data!='(' || top!=NULL){
                final[j++]=pop();
            }
            pop();
        }else{
            if(top==NULL || top->data=='(' ){
                push(arr[i]);
            }
            else{
              while(check_precedence(arr[i])<=check_precedence(top->data) && top!=NULL){
                  final[j++]=pop();
                }
                push(arr[i]);
            }
        }
    }
    while(top!=NULL){
        final[j++]=pop();
    }
}

int Stack::pop(){
    if(isempty()){
        cout<<"Underflow"<<endl;
        return -1;
    }
        size--;
        cout<<top->data<<" Popped out from the stack"<<endl;
        Node * todelete=top;
        top=top->next;
        delete todelete;
        return todelete->data;
    }

void Stack::display(){
    Node* temp=top;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Stack s1,s2;

    char carr[]="23+4/^234";
    char iarr[]="4$2*3-3+8/4/(1+1)";
    char final[]="";
    s1.infixTopostfix(iarr,final);
    cout<<final;
    return 0;
}