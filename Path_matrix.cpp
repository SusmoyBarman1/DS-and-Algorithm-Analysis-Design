#include<bits/stdc++.h>
using namespace std;

int m,matrix[100][100][100],B[100][100],P[100][100];

void input()
{
    cout<<"Give the number of node: ";
    cin>>m;

    cout<<"\nGive the input matrix bellow"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[0][i][j];
        }
    }
}
void path_matrix()
{
    for(int a=1;a<m;a++)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[a][i][j] = 0;
                for(int k=0;k<m;k++)
                {
                    matrix[a][i][j] += matrix[0][i][k] * matrix[a-1][k][j];
                }
            }
        }
    }
}
void printA()
{
    for(int a=0;a<m;a++)
    {
        cout<<"\nA -> "<<a+1<<endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<matrix[a][i][j]<<"  ";
            }
            cout<<endl;
        }
    }
}
void Br()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            B[i][j] = 0;
        }
    }
    for(int a=0;a<m;a++)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                B[i][j] += matrix[a][i][j];
            }
        }
    }
}
void printB()
{
    cout<<"\nThe value of B: "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<B[i][j]<<"  ";
        }
        cout<<endl;
    }
}
void path()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(B[i][j]==0)
            {
                P[i][j] = 0;
            }
            else
            {
                P[i][j] = 1;   
            }
        }
    }
}
void printP()
{
    cout<<"\nThe value of P: "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<P[i][j]<<"  ";
        }
        cout<<endl;
    }
}
bool is_strong()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(P[i][j]==0)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    input();
    path_matrix();
    printA();
    Br();
    printB();
    path();
    printP();
    if(is_strong())
    {
        cout<<"\nThe graph is strongly connected!"<<endl;
    }
    else
    {
        cout<<"\nThe graph is not strongly connected."<<endl;
    }
    return 0;
}