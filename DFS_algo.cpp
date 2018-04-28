#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void init();
void DFS(int source);
void Insert(int j,int x);
int Input();
void Print();
bool isvisited(int data);
Node *head[100],*temp_head;
int Stack[100],top=-1,n=-1,arr[100] = {0};

int main()
{
    int source;
    cout<<"Put the source: ";
    cin>>source;
    DFS(source);

    return 0;
}

void Print()
{
    int totalnode = Input();
    cout<<"\nPrinting the list: "<<endl;
    for(int j=0;j<totalnode;j++)
    {
        Node* temp = head[j];
        cout<<j<<" -> ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
int Input()
{
    ifstream input("input.txt");;
    int node1,node2,totalnode;
    input>>totalnode;
    while(input>>node1>>node2)
    {
        Insert(node1,node2);
    }
    input.close();
    return totalnode;
}
void init()
{
    for(int j=0;j<100;j++)
    {
        head[j] = NULL;
    }
}
void Insert(int j,int x){
	Node* temp = new Node();
	if(head[j]==NULL)
		head[j] = temp;
	else
		temp_head->next = temp;
	temp->data = x;
	temp->next = NULL;
	temp_head = temp;
	return;
}
void DFS(int source)
{
    init();
    Print();
    cout<<"\nThe adjacency list is: "<<endl;
    Stack[++top] = source;
    arr[source] = 1;
    while(top!=-1)
    {
        cout<<Stack[top]<<"  ";
        Node* temp = head[Stack[top]];  
        top--;
        while(temp!=NULL)
        {
            if(arr[temp->data]==0)
            {
                Stack[++top] = temp->data;
                arr[temp->data] = 1; 
            }
            temp = temp->next;
        }
    }
    cout<<endl<<endl;
}