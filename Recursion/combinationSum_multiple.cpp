#include<iostream>
#include<vector>
using namespace std;

void combinationSum_multiple(vector<int> &candidates, int target, int i, vector<int> ar, vector<vector<int>> &store)
{
    if(target==0)
    {
        store.push_back(ar);
        return;
    }
    if(i==candidates.size() || target<0)
    {
        return;
    }
    combinationSum_multiple(candidates,target,i+1,ar,store);
    ar.push_back(candidates[i]);
    combinationSum_multiple(candidates,target-candidates[i],i,ar,store);
}

int main()
{
    vector<int> ar= {2};
    int target = 1;
    vector<vector<int>> store;
    combinationSum_multiple(ar,target,0,{},store);
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