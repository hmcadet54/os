#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(int argc, char *argv[])
{
    float number[argc];
    float N=argc;
    for (int i=0;i<argc;i++)
    {
        number[i]=atoi(argv[i+1]);
    }
    float sum=0;
    for (int i=0;i<argc-1;i++)
    {
        sum+=number[i];
    }
    float mean = sum / (N - 1);
    int median=0;
    if(static_cast<int>(N)%2==0)
    {
        median=(number[static_cast<int>(N)/2]+number[static_cast<int>(N)/2-1])/2;
    }
    else
    {
        median=number[static_cast<int>(N)/2];
    }
  
    sum=0;
    for (int i=0;i<argc-1;i++)
    {
        sum+=pow((number[i]-mean),2);
    }
    cout<<"Mean: "<<mean<<endl;
    cout<<"Median: "<<median<<endl;
    cout<<"Standard Deviation: "<<sqrt(sum/(N-1))<<endl;
    return 0;
}