#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void permutation(vector<int> num, int i,vector<vector<int>> &store)
{
    if(i==num.size())
    {
        store.push_back(num);
        return;
    }
    for(int j=i;j<num.size();j++)
    {
        swap(num[i],num[j]);
        permutation(num,i+1, store);
        swap(num[i],num[j]);
    }

}

int main()
{
    vector<int> num={1,2,3};
    vector<vector<int>> store;

    permutation(num,0,store);
    for(vector<int> num : store)
    {
        for(int i : num)
        {
            cout<<i<< " ";
        }
        cout<<endl;
    }
    cin.get();
    return 0;
}