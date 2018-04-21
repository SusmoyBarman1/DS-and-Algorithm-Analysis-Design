#include<iostream>
#include<fstream>
#include<vector>
#include<list>
using namespace std;

class edge
{
    private:
        int nodeid,weight;
    public:
        edge(int id,int wei)
        {
            nodeid = id;
            weight  = wei;
        }
        int getnodeid()
        {
            return nodeid;
        }
        int getweight()
        {
            return weight;
        }
};

int main()
{
    int totalnode,node1,node2,wt;
    ifstream input("adj_test_weight.txt");
    ofstream output("list.txt");

    input>>totalnode;
    vector< list<edge> > adjList(totalnode);
    while(input>>node1>>node2>>wt)
    {
        adjList[node1-1].push_back(edge(node2,wt));
    }
    int c = 1;
    vector< list<edge> >::iterator i;
    for(i = adjList.begin();i!=adjList.end();i++)
    {
        output<<c<<" -> ";
        list<edge> li = *i;
        list<edge>::iterator iter;
        for(iter = li.begin();iter!=li.end();iter++)
        {
            output<<"["<<(*iter).getnodeid()<<", "<<(*iter).getweight()<<"] -> ";
        }
        output<<endl;
        c++;
    }

    return 0;
}