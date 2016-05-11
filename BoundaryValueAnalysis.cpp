#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    cout<<"enter the number of variables:";
    int n;
    cin>>n;
    int arr[n][5];
    ofstream outfile;
    outfile.open("BVA.txt");
    for(int i=0;i<n;i++)
    {
        int a,b;
        cout<<"enter the range of "<<i+1<<" variable:";
        cin>>a>>b;
        int avg=(a+b)/2;
        arr[i][0]=avg;
        arr[i][1]=a;
        arr[i][2]=a+1;
        arr[i][3]=b-1;
        arr[i][4]=b;
    }
    cout<<"number of test cases:"<<(4*n)+1<<"\n";
    outfile<<"number of test cases:"<<(4*n)+1<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i][0]<<" ";
    }
    cout<<"\n";
    outfile<<"\n";

    for(int i=0;i<n;i++)
    {
         for(int j=1;j<=4;j++)
        {
            int w=-100000;
        for(int z=0;z<=i-1;z++)
        {
            cout<<arr[z][0]<<" ";
            outfile<<arr[z][0]<<" ";
            w=max(w,arr[z][0]);
        }

            cout<<arr[i][j]<<" ";
            outfile<<arr[i][j]<<" ";
            w=max(w,arr[i][j]);

        for(int z=i+1;z<n;z++)
        {
            cout<<arr[z][0]<<" ";
            outfile<<arr[z][0]<<" ";
            w=max(w,arr[z][0]);
        }
        cout<<w;
        cout<<"\n";
        outfile<<w<<"\n";
        }


    }
    outfile.close();

}
