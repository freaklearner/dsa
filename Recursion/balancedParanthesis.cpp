#include <iostream>
using namespace std;

void balanceparanthesis(int n, int open,int close,char ar[])
{
    if(open==n)
    {
        if(close==n)
        {
            for(int i=0;i<2*n;i++)
            {
                cout<<ar[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            ar[open+close]=')';
            balanceparanthesis(n,open,close+1,ar);
        }
    }
    if(open<n)
    {
        if(open==close)
        {
            ar[open+close]='(';
            balanceparanthesis(n,open+1,close,ar);
            return;
        }
        else{
            ar[open+close]='(';
            balanceparanthesis(n,open+1,close,ar);
            ar[open+close]=')';
            balanceparanthesis(n,open,close+1,ar);
        }
        
    }
    
}

int main()
{
    int n=3;
    char ar[2*n];
    balanceparanthesis(n,0,0,ar);
    cin.get();
    return 0;
}