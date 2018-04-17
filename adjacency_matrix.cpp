#include<iostream>
#include<fstream>
using namespace std;

int main()
{	
	int totalnode,node1,node2,weight;
	int Adjmatrix[100][100] = {0};
	ifstream input("test.txt");
	
	if(input.is_open())
	{
		cout<<"File is opened."<<endl;
		input>>totalnode;
		while(input>>node1>>node2>>weight)
		{
			Adjmatrix[node1][node2] = weight;
		}
		ofstream output("AdjacencyMatrix.txt");
		if(output.is_open())
		{
			cout<<"Created."<<endl;
			for(int i=1;i<=totalnode;i++)
			{
				for(int j=1;j<=totalnode;j++)
				{
					output<<Adjmatrix[i][j]<<" ";
				}
				output<<endl;
			}
		}
		else
		{
			cout<<"Not created."<<endl;
		}
	}
	else
	{
		cout<<"File is not opened."<<endl;
	}
	
	return 0;
}
