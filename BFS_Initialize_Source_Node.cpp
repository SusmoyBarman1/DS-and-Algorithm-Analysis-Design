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

void setnodeproperty(int nid,char col,int dis,int par)
{
	vector<nodeproperty>::iterator i;
	i = node.begin();
	advance(i,nid);  // move i from begin to nid
	(*i).color = col;
	(*i).distance = dis;
	(*i).parent = par;
}

int BFS(vector<list<int> >adjlist,int source)
{
	setnodeproperty(source,'g',0,-1);
	return 0;
}

int main()
{
	int totalnode,node1,node2,source;
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
	vector<nodeproperty>::iterator i;
	for(i = node.begin();i!=node.end();i++)
	{
		cout<<"[ "<<(*i).nodeid<<", "<<(*i).color<<", "<<(*i).distance<<", "<<(*i).parent<<" ]"<<endl;
	}
	
	return 0;
}
