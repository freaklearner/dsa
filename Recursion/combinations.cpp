#include<iostream>
#include <vector>

using namespace std;

void combinations(int &n, int &k,int i, int j, vector<int> &ar, vector<vector<int>> &store)
{
    cout<<n<<" "<<k<<" "<<i<<" "<<j<<" "<<endl;
    if(j==k)
    {
        store.push_back(ar);
        return;
    }
    if(i>n)
    {
        cout<<"inside if "<<n<<" "<<i<<" "<<(i>n);
        return;
    }
    combinations(n,k,i+1,j,ar,store);
    ar[j]=i;
    combinations(n,k,i+1,j+1,ar,store);
    return;   
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> ar(k);
    vector<vector<int>> store;
    combinations(n,k,1,0,ar,store);
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
