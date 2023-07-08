#include <iostream>
#include <vector>
using namespace std;

void balancePrt(int& n, int open, int close,string str,vector<string>& store)
    {
        if(open==n)
        {
            if(close==n)
            {
                store.push_back(str);
                return;
            }
            else{        
                balancePrt(n,open,close+1,str+")",store);
            }
        }
        if(open<n)
        {
            if(open==close)
            {
                balancePrt(n,open+1,close,str+"(",store);
                return;
            }
            else{
                balancePrt(n,open+1,close,str+"(",store);
                balancePrt(n,open,close+1,str+")",store);
            }
        }
    }
vector<string> generateParenthesis(int n) {
    vector<string> store;
    balancePrt(n,0,0,"",store);
    return store;
}

int main()
{
    int n=3;
    vector<string> store = generateParenthesis(n);
    for(int i=0;i<store.size();i++)
    {
        cout<<store[i]<<endl;
    }
    cin.get();
    return 0;
}