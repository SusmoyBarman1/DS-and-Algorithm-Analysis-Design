#include<iostream>
#include<fstream> // read = ofstream & write = ifstream
using namespace std;

int main()
{
	int roll;
	string name;

	ofstream myfile; // creating object for the class ofstream
	myfile.open("test.txt"); // opening file using open() function
	// We can create a file using the defult constructor like: ofstream myfile("test.txt")

	// when we write those two line, then a file will be created
	
	if(myfile.is_open())
	{
		cout<<"File created."<<endl; // checking that, is the file created of not
		myfile<<"My name is susmoy and I am not a terorist."<<endl;
		for(int i=0;i<5;i++)		
		{
			cin>>name>>roll;
			myfile<<endl<<name<<"  "<<roll<<endl;
		}		
	}		
	else
	{
		cout<<"File not created."<<endl;
	}
	myfile.close();  // closing the file

	return 0;
}
