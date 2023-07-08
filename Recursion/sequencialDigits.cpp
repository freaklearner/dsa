#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void generateSequenceDigit(int &low, int &high, int i,int &num, vector<int> &store)
{
    if(num>high ||i>9)
    {
        return;
    }
    num = num *10 + i;
    if(num>=low && num<=high)
    {
        
        store.push_back(num);
    }
    generateSequenceDigit(low,high,i+1,num,store);
}

int main()
{
    int low=1000, high=13000;
    vector<int> store;
    for(int i=1;i<9;i++)
    {
        int num = 0;
        generateSequenceDigit(low,high,i,num,store);
    }
    sort(store.begin(),store.end());
    for(int i=0;i<store.size();i++)
    {
        cout<<store[i]<<" ";
    }

    cin.get();
    return 0;
}