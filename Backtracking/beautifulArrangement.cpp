#include<iostream>
#include<algorithm>
using namespace std;

void arrangement(int ar[],int &n, int i, int &count)
{
    if(i==n)
    {
        count++;
        return;
    }
    for(int j=i;j<n;j++)
    {
        if(ar[j]%(i+1)==0 || (i+1)%ar[j]==0)
        {
            swap(ar[i],ar[j]);
            arrangement(ar,n,i+1,count);
            swap(ar[i],ar[j]);
        }
    }
}
int main()
{
    int count=0;
    int n=0;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        ar[i]=i+1;
    }
    arrangement(ar,n,0,count);
    cout<<count;
    cin.get();
    return 0;
}