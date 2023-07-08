#include<iostream>
#include<array>
#include<climits>
#include<vector>
#define int long long signed
using namespace std;

long long signed opResult(int a, int b, char ch)
{
    // cout<<a<<" "<<b<<" "
    if(ch=='+')
    {
        return a+b;
    }
    else{
        return (long long signed)a*(long long signed)b;
    }
}

int getSmallest(vector<int> ar,char op[], int idx)
{
    if(idx==2)
    {
        return opResult(ar[0],ar[1],op[idx]);
    }
    int minimum=INT_MAX;
    for(int i=0;i<ar.size()-1;i++)
    {
        for(int j=i+1;j<ar.size();j++)
        {
            vector<int> temp;
            for(int k=0;k<ar.size();k++)
            {
                if(k==i || k==j)
                {
                    continue;
                }
                temp.push_back(ar[k]);
            }
            long long signed res = (long long signed)opResult(ar[i],ar[j],op[idx]);
            // cout<<" res: "<<res<<endl;
            temp.push_back(res);
            minimum = min(minimum,getSmallest(temp,op,idx+1));
        }
    }
    return minimum;
}

signed main()
{
    vector<int> ar;
    for(int i=0;i<4;i++)
    {
        int temp;
        cin>>temp;
        ar.push_back(temp);
    }
    char op[3];
    for(int i=0;i<3;i++)
    {
        cin>>op[i];
    }
    cout<<getSmallest(ar,op,0);
    cin.get();
    return 0;
}