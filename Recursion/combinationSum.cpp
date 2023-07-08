#include<iostream>
#include<vector>

using namespace std;

void combinationSum(int sum,int k,int i,vector<int> &ar, vector<vector<int>> &store)
{
    if(k==0 && sum==0)
    {
        store.push_back(ar);
        return;
    }
    if(i>9 || sum<0 || k==0)
    {
        return;
    }
    combinationSum(sum,k,i+1,ar,store);
    ar[k-1]=i;
    combinationSum(sum-i,k-1,i+1,ar,store);
}

int main()
{
    int k,n;
    cin>>k>>n;
    vector<vector<int>> store;
    vector<int> ar(k);
    combinationSum(n,k,1,ar,store);
    for(int i=0;i<store.size();i++)
    {
        for(int j=0;j<store[i].size();j++)
        {
            cout<<store[i][j]<<" ";
        }
        cout<<endl;
    }
    cin.get();
    return 0;
}