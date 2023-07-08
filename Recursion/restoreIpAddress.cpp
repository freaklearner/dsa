#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool validIpPart(string s)
    {
        if(s[0]=='0')
        {
            if(s.length()==1)
            {
                return true;
            }
            else{
                return false;
            }
        }
        else{
            int total=0;
            for(int i=0;i<s.length();i++)
            {
                char ch = s[i];
                int val = ch-'0';
                total=(total*10)+ val;
            }
            if(total<=255)
            {
                return true;
            }
            else{
                false;
            }

        }
    }
    void checkForValidIp(string& s,int index, int part,string ip, vector<string>& store)
    {
        if(index==s.length()||part>=4)
        {
            if(index==s.length()&&part==4)
            {
                store.push_back(ip.substr(0,ip.length()-1));
            }
            return;
        }
        for(int j=index;j<s.length()&&j<(index+3);j++)
        {
            string temp = s.substr(index,j-index+1);
            //cout<<temp<<endl;
            if(validIpPart(temp))
            {
                checkForValidIp(s,index+(j-index)+1,part+1,ip+temp+".",store);
            }

        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> store;
        checkForValidIp(s,0,0,"",store);
        return store;
    }

int main()
{
    string s="25525511135";
    vector<string> store = restoreIpAddresses(s);
    for(int i=0;i<store.size();i++)
    {
        cout<<store[i]<<endl;
    }
    return 0;
}