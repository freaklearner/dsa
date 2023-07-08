#include<iostream>
#include<vector>
using namespace std;

void subSetSum(vector<int> &ar, int i, int sum, vector<int> &store)
{
    if(i==ar.size())
    {
        store.push_back(sum);
        return;
    }
    subSetSum(ar,i+1,sum+ar[i],store);
    subSetSum(ar,i+1,sum,store);
}

int main()
{
    vector<int> ar={2,3};
    vector<int> store;
    subSetSum(ar,0,0,store);
    for(int i=0;i<store.size();i++)
    {
        cout<<store[i]<<" ";
    }
    cin.get();
    return 0;
}

