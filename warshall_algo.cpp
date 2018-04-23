/*
--> Floyd - Warshall's algorithm
	
	--> All Pairs shortest path algoritm
	--> Applicable for Negative vartex/edges
	--> Not applicable for negative cycle
	--> complexity: x^3
*/
#include<bits/stdc++.h>
using namespace std;

int n,w[100][100],q[100][100],INF;

void print()
{
	cout<<"\nHere is the shortest path matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(q[i][j]==INF)
			{
				cout<<"INF  ";
			}
			else
			{
				cout<<q[i][j]<<"  ";
			}
		}
		cout<<endl;
	}
}

void assign()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(w[i][j]>0)
			{
				q[i][j] = w[i][j];
			}
			else
			{
				q[i][j] = INF;
			}
		}
	}
}

void floydWarshall()
{
	assign();

	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{ 
				if((q[i][k]+q[k][j])<q[i][j])
				{
					q[i][j] = q[i][k]+q[k][j];
				}
			}
		}
		print();
		cout<<endl;
	}
}
void input()
{
	cout<<"Give the number of node and Please give the weighted graph matrix."<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>w[i][j];
		}
	}
}
int main()
{
	INF = 55555;
	input();
	floydWarshall();		
	//print();

	return 0;
}