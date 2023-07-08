#include<iostream>
#include <vector>
using namespace std;

void sets(string s, int index, vector<string>& store)
{
    if(s[index]=='\0')
    {
        return;
    }
    int size = store.size();
    for(int i=0;i<size;i++)
    {
        store.push_back(store[i]+s[index]);
    }
    sets(s,index+1,store);
}

int main(){
    vector<string> store;
    store.push_back("");
    sets("abc",0, store);
    for(int i=0;i<store.size();i++)
    {
        cout<<store[i]<<endl;
    }
    cin.get();
    return 0;
}