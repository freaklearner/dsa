#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void calculateForOne(int n, vector<int>& store)
{
    if(n<=1)
    {
        store.push_back(n);
        return;
    }
    calculateForOne(n/2,store);
    int size = store.size();
    store.push_back(n%2);
    for(int i=0;i<size;i++)
    {
        store.push_back(store[i]);
    }
    return;
}

int CodeForOne(int n, int start, int end, int l, int r)
{
    if(n<=1)
    {
        if(end>=l && end<=r)
        {
            return n;
        }
        else{
            return 0;
        }
    }
    int a1 = CodeForOne(n/2,start,start+(end-start)/2,l,r);
    int a2 = CodeForOne(n%2,start,end,l,r);
    int a3 = CodeForOne(n/2,end,end+(end-start)/2,l,r);
    return(a1+a2+a3);
}

int main()
{
    int n,l,r;
    cin>>n>>l>>r;
    int power = n/3;
    int totalChild = (3* pow(2,power-1)) + (pow(2,power-1)-1);
    // cout<<totalChild<<endl;
    cout<<CodeForOne(n,0,(totalChild/2)+1,l,r);
    cin.get();
    return 0;
}
