#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream myfile("input.txt");
    int cyclo=0,pn=0;
    if(myfile.is_open())
    {
        string line;

        while(getline(myfile,line))
        {
            if(line.find("if")!=string::npos)
            {
                cyclo++;
            }
            else if(line.find("while")!=string::npos)
            {
                cyclo++;
            }

        }
    }

cout<<cyclo+1<<"\n";
}
