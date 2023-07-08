#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void parenthesis(int& n,int& m, int po, int pc, int qo, int qc, char seq[], int idx)
{
    
    if(po==n && po==pc && qo==m && qo==qc)
    {
        for(int i=0;i<idx;i++)
        {
            cout<<seq[i];
        }
        cout<<endl;
        return;
    }
    if(po==pc && qo==qc)
    {
        if(po==n)
        {
            seq[idx]='{';
            parenthesis(n,m,po,pc,qo+1,qc,seq,idx+1);
            
        }
        else if(qo==m)
        {
            seq[idx]='(';
            parenthesis(n,m,po+1,pc,qo,qc,seq,idx+1);
            
        }
        else{
            seq[idx]='{';
            parenthesis(n,m,po,pc,qo+1,qc,seq,idx+1);
            seq[idx]='(';
            parenthesis(n,m,po+1,pc,qo,qc,seq,idx+1);
        }
    }
    if(po==pc && qo>qc)
    {
        if(qo==m)
        {
            seq[idx]='}';
            parenthesis(n,m,po,pc,qo,qc+1,seq,idx+1);
            
        }
        else{
            seq[idx]='{';
            parenthesis(n,m,po,pc,qo+1,qc,seq,idx+1);
            seq[idx]='}';
            parenthesis(n,m,po,pc,qo,qc+1,seq,idx+1);
            
        }
        if(po<n)
        {
            seq[idx]='(';
            parenthesis(n,m,po+1,pc,qo,qc,seq,idx+1);
        }
    }
    if(po>pc && qo==qc)
    {
        if(po==n)
        {
            seq[idx]=')';
            parenthesis(n,m,po,pc+1,qo,qc,seq,idx+1);
            
        }
        else{
            seq[idx]='(';
            parenthesis(n,m,po+1,pc,qo,qc,seq,idx+1);
            seq[idx]=')';
            parenthesis(n,m,po,pc+1,qo,qc,seq,idx+1);
            
        }
        if(qo<m)
        {
            seq[idx]='{';
            parenthesis(n,m,po,pc,qo+1,qc,seq,idx+1);
        }
    }
    if(po>pc && qo>qc)
    {
        int OP=0,CP=0,OQ=0,CQ=0;
        for(int i=idx-1;i>=0;i--)
        {
            if(OP>CP || OQ>CQ)
            {
                break;
            }
            if(seq[i]=='(')
            {
                OP++;
            }
            else if(seq[i]==')')
            {
                CP++;
            }
            else if(seq[i]=='{')
            {
                OQ++;
            }
            else if(seq[i]=='}')
            {
                CQ++;
            }
        }
        if(OP>CP)
        {
            seq[idx]=')';
            parenthesis(n,m,po,pc+1,qo,qc,seq,idx+1);
        }
        if(OQ>CQ)
        {
            seq[idx]='}';
            parenthesis(n,m,po,pc,qo,qc+1,seq,idx+1);
        }
        if(po<n)
        {
            seq[idx]='(';
            parenthesis(n,m,po+1,pc,qo,qc,seq,idx+1);
        }
        if(qo<m)
        {
            seq[idx]='{';
            parenthesis(n,m,po,pc,qo+1,qc,seq,idx+1);
        }

    }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,m;
    cin>>n;
    cin>>m;
    char seq[n*2+m*2];
    parenthesis(n,m, 0, 0, 0, 0,seq,0);
    return 0;
}
