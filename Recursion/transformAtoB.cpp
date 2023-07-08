#include <iostream>
#include <vector>
#define int long long
using namespace std;

bool transformAtoB(int a, int b, int index,vector<int>& store)
{
    
    store[index]=a;
    if(a==b)
    {
        cout<<"YES"<<endl;
        cout<<index+1<<endl;
        for(int i=0;i<=index;i++)
        {
            cout<<store[i]<<" ";
        }
        return true;
    }
    if(a>b)
    {
        return false;
    }
    if(transformAtoB(a*2,b,index+1,store))
    {
        return true;
    }
    if(transformAtoB(a*10+1,b,index+1,store))
    {
        return true;
    }
    return false;
}

signed main()
{
    int a=2,b=162;
    cin>>a>>b;
    vector<int> store(100000);
    bool res = transformAtoB(a,b,0,store);
    if(!res)
    {
        cout<<"NO"<<endl;
    }
    return 0; 
}