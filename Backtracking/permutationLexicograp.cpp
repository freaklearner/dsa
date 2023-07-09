#include<iostream>
using namespace std;

void rightShift(string &str, int target, int start)
{
    char ch = str[target];
    for(int i=target;i>start;i--)
    {
        str[i]=str[i-1];
    }
    str[start]=ch;
}

void leftShift(string &str, int target, int start)
{
    char ch=str[target];
    for(int i=target;i<start;i++)
    {
        str[i]=str[i+1];
    }
    str[start]=ch;
}

void permutation(int &k, int i, string &input, string &store)
{
    if(k==0)
    {
        return;
    }
    if(i==input.length())
    {
        k--;
        if(k==0)
        {
            store=input;
        }
            
        return;
    }
    for(int j=i;j<input.length();j++)
    {
        rightShift(input,j,i);
        permutation(k,i+1,input,store);
        leftShift(input,i,j);
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    string str(n,'0');
    for(int i=1;i<=n;i++)
    {
        str[i-1]='0'+i;
    }
    string store;
    permutation(k,0,str,store);
    cout<<store<<endl;
    cin.get();
    return 0;

}