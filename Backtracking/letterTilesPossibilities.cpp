#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void tilesCount(string &str, int i, int &count)
{
    if(i==str.length()-1)
    {
        count++;
        return;
    }
    int frq[26]={0};
    for(int j=i;j<str.length();j++)
    {
        if(frq[str[j]-'A']==0)
        {
            count++;
            swap(str[i],str[j]);
            tilesCount(str,i+1,count);
            swap(str[i],str[j]);
            frq[str[j]-'A']=1;
        }
    }
}

int main()
{
    string str="V";
    int count=0;
    tilesCount(str,0,count);
    cout<<count;
    cin.get();
    return 0;
}