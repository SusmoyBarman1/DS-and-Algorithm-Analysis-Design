#include<iostream>
#include<fstream>
using namespace std;
// we will read a file in this code

int main()
{
	int roll;
	char name[20];

	ifstream myfile("test.txt");

	if(myfile.is_open())
	{
		cout<<"File open."<<endl;
		while(myfile>>name>>roll)
		{
			cout<<roll<<"  "<<name<<endl;
		}
	}
	else
	{
		cout<<"File is not open!!"<<endl;
	}

	return 0;
}
