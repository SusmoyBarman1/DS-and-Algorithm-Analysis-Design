#include<iostream>
#include<fstream>
#include<vector>
#include<list>
using namespace std;

int main()
{
    int totalnode,node1,node2;
    ifstream input("adj_test.txt");
    ofstream output("list.txt");
    if(input.is_open())
    {
        cout<<"File open."<<endl;
        input>>totalnode;
        vector< list<int> > adjlist(totalnode);
        
        while(input>>node1>>node2)
        {
            adjlist[node1].push_back(node2);
        }
        vector< list<int> >:: iterator i;
        int c=0;
        for(i=adjlist.begin();i!=adjlist.end();i++)
        {
            output<<c<<" -> ";
            list<int> li = *i;
            list<int>:: iterator iter;
            for(iter = li.begin();iter!=li.end();iter++)
            {
                output<<*iter<<" ";
            }
            output<<endl;
            c++;
        }
    }
    else
    {
        cout<<"File no open."<<endl;
    }

    return 0;
}
