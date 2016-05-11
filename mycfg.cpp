#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
#include<string.h>
using namespace std;
/*
void ddpathgraph( vector<vector<int>> graph)
{
    vector<vector<int>> ddpath(n+1);
    int i=1;
    int t=1;
    while(i<graph.size())
    {
       if(graph[i].size()==1&&graph[i][0]=i+1)
       {
           i++;
       }
       else{
        ddpath[t].push_back(i);
        t++;
       }
    }
    for(int i=1;i<ddpath.size();i++)
    {
        cout<<i<<": ";
        for(int j=0;j<ddpath[i].size();j++)
            cout<<ddpath[i][j]<<" ";
        cout<<"\n";
    }
}*/
int main()
{
    string line;
    stack<pair<string,int>>s;
    ifstream myfile("input.txt");
    int n=0;
    while(getline(myfile,line))
    {
        n++;
    }
    cout<<n;
    vector<vector<int>> graph(n+1);
    myfile.close();
    myfile.open("input.txt");
    int i=1;
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {

            if(line.find("#")!=string::npos)
                continue;

            if(line.find("using")!=string::npos)
                continue;

            if(line.find("if")!=string::npos)
            {
                pair<string,int> p=make_pair("if",i);
                graph[i-1].push_back(i);
                s.push(p);
                cout<<line<<"\n";

            }
            else if(line.find("else")!=string::npos&&!s.empty())
            {
                pair<string,int> p=make_pair("else",i);
                pair<string,int> x=s.top();
                s.pop();
                graph[s.top().second].push_back(i);
                s.push(x);
                s.push(p);
                cout<<line<<"\n";
            }
            else if(line.find("}")!=string::npos&&!s.empty())
            {
                if(s.top().first=="if")
                {
                    pair<string,int> p=make_pair("}",i);
                    graph[i-1].push_back(i);
                    s.push(p);
                    cout<<line<<"\n";
                }
                else if(s.top().first=="else")
                {
                    graph[i-1].push_back(i);
                    s.pop();
                    cout<<line<<"\n";
                }
                else if(s.top().first=="}")
                {
                    graph[s.top().second].push_back(i);
                    graph[i-1].push_back(i);
                    s.pop();
                    s.pop();
                    if(!s.empty()&&s.top().first=="else")
                    {
                        s.pop();
                    }
                    else{
                    pair<string,int> p=make_pair("}",i);
                    s.push(p);
                }
                    cout<<line<<"\n";
                }

            }
            else if(!s.empty()&&s.top().first=="}")
            {
                //s.pop();
                graph[s.top().second].push_back(i);

                graph[i-1].push_back(i);
                s.pop();
                s.pop();
                cout<<line<<"\n";
            }
            else
            {
                cout<<line<<"\n";
                graph[i-1].push_back(i);

            }
            i++;

        }
    }

 for(int i=1;i<graph.size();i++)
    {
        cout<<i<<": ";
        for(int j=0;j<graph[i].size();j++)
            cout<<graph[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
   // ddpathgraph();
}
