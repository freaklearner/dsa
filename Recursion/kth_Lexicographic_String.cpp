#include<iostream>
#include<vector>
using namespace std;

void kthLexographicString(char input[],int &inputSize, int &n, int &k,vector<char> &ar, char &ch,int &count, string &result)
{
    if(count==k)
    {
        return;
    }
    if(ar.size()==n)
    {
        count++;
        if(count==k)
        {
            result=string(ar.begin(),ar.end());
        }
        return;
    }
    for(int i=0;i<inputSize;i++)
    {
        if(input[i]==ch)
        {
            continue;
        }
        ar.push_back(input[i]);
        kthLexographicString(input,inputSize,n,k,ar,input[i],count,result);
        ar.pop_back();
    }
    return;
}

int main()
{
    char input[]={'a','b','c'};
    int size=3,n=1,k=3,count=0;
    string result="";
    vector<char> ar;
    char initial = ' ';
    kthLexographicString(input,size,n,k,ar,initial,count,result);
    cout<<result;
    cin.get();
    return 0;
}
