#include<iostream>
#include<vector>
using namespace std;

bool checkPalindrom(string s,int i, int j)
{
    
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void palindromSubstring(string &s,int i,vector<string> &subs, vector<vector<string>> &store)
{
    if(i==s.length())
    {
        store.push_back(subs);
        return;
    }
    for(int j=i;j<s.length();j++)
    {
        if(checkPalindrom(s,i,j))
        {
            subs.push_back(s.substr(i,(j-i)+1));
            palindromSubstring(s,j+1,subs,store);
            subs.pop_back();
        }
    }
}

int main()
{
    string s = "efe";
    vector<string> subs;
    vector<vector<string>> store;
    palindromSubstring(s,0,subs,store);
    for(vector<string> temp: store){
        for(string str : temp)
        {
            cout<<str<<" ";
        }
        cout<<endl;
    }
    cin.get();
    return 0;
}