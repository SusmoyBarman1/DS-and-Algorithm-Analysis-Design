#include<iostream>
#include<fstream>
#include<vector>
#include<list>
using namespace std;

class nodeproperty
{
	public:
		int nodeid;
		char color;
		int distance;
		int parent;
		
		nodeproperty(int nid,char col,int dis,int par)
		{
			nodeid = nid;
			color = col;
			distance = dis;
			parent = par;
		}
};

vector<nodeproperty>node;
vector<int>path;

bool invisited(int v)
{
    vector<nodeproperty>::iterator i;
    i = node.begin();
    advance(i,v);
    if((*i).color!='w')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int destpath(int nid)
{
    vector<nodeproperty>::iterator i;
    i = node.begin();
    advance(i,nid);
    return (*i).parent;
}

void searchpath(int dest)
{
    vector<nodeproperty>::iterator i;
    i = node.begin();
    advance(i,dest);
    cout<<"Distance: "<<(*i).distance<<endl;
    if((*i).distance==5555555)
    {
        cout<<"Path not available!!"<<endl;
        return;
    }
    int parent = (*i).parent;
    path.push_back(dest);
    path.push_back(parent);

    while(1)
    {
        parent = destpath(parent);
        if(parent==-1)
        {
            break;
        }
        path.push_back(parent);
    }
    cout<<"Path: ";
    for(int m=path.size()-1;m>=0;m--)
    {
        cout<<path[m];
        if(m!=0)
        {
            cout<<" -> ";
        }
    }
    cout<<endl;
}

int distanceofU(int u)
{
    vector<nodeproperty>::iterator i;
    i = node.begin();
    advance(i,u);
    return (*i).distance;
}

void colorchangeofU(int u)
{
    vector<nodeproperty>::iterator i;
    i = node.begin();
    advance(i,u);
    (*i).color = 'b';
}

void setnodeproperty(int nid,char col,int dis,int par)
{
	vector<nodeproperty>::iterator i;
	i = node.begin();
	advance(i,nid);  // move i from begin to nid
    //cout<<nid<<" "<<col<<" "<<dis<<" "<<par<<endl;
	(*i).color = col;
	(*i).distance = dis;
	(*i).parent = par;
}

void BFS(vector<list<int> >adjlist,int source)
{
	setnodeproperty(source,'g',0,-1);
    int size = adjlist.size();
    int nodequeue[size],front=0,rear=0;
    nodequeue[front++] = source; //cout<<"front: "<<front<<" rear: "<<rear<<" "<<nodequeue[front-1]<<endl;

    while(front!=rear)
    {
        int u = nodequeue[rear++]; //cout<<"\nU is: "<<u<<endl;
        vector<list<int> >::iterator i;
        i = adjlist.begin();
        advance(i,u);
        list<int> li = *i;
        list<int>::iterator iter;
        for(iter=li.begin();iter!=li.end();iter++)
        {
            if(!invisited(*iter))
            {
                int d = distanceofU(u);
                setnodeproperty(*iter,'g',d+1,u);
                nodequeue[front++] = *iter; //cout<<"front: "<<front<<endl;
            }
        }
        colorchangeofU(u);
    }
}

int main()
{
	int totalnode,node1,node2,source,destination;
	ifstream input("input.txt");
	input>>totalnode;
	vector< list<int> > adjlist(totalnode);
	while(input>>node1>>node2)
	{
		adjlist[node1].push_back(node2);
	}
	input.close();
	
	for(int i=0;i<totalnode;i++)
	{
		node.push_back(nodeproperty(i,'w',5555555,-1));
	}

	
	cout<<"Enter Source: ";
	cin>>source;
	BFS(adjlist,source);
    cout<<"Enter destination ";
    cin>>destination;
    searchpath(destination);
	
   /* vector<nodeproperty>::iterator i;
	for(i = node.begin();i!=node.end();i++)
	{
		cout<<"[ "<<(*i).nodeid<<", "<<(*i).color<<", "<<(*i).distance<<", "<<(*i).parent<<" ]"<<endl;
	} */

	
	return 0;
}