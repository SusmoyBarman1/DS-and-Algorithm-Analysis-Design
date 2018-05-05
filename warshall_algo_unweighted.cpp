#include<bits/stdc++.h>
using namespace std;

int A[100][100],P[100][100],m;

void input()
{
    cin>>m;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
}
void warshall()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==0)
            {
                P[i][j] = 0;
            }
            else
            {
                P[i][j] = 1;
            }
        }
    }
    for(int k=0;k<m;k++)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                P[i][j] = P[i][j] | (P[i][k] & P[k][j]);
            }
        }
    }
}
void print()
{
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<P[i][j]<<"  ";
        }
        cout<<endl;
    }
}
int main()
{
    input();
    warshall();
    print();

    return 0;
}