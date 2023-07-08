#include <iostream>
#include <vector>
using namespace std;

void letterSubset(string& digits, int index,string final, vector<string>& digitMap, vector<string>& store)
{
    if(index==digits.length())
    {
        store.push_back(final);
        return;
    }
    for(int i=0;i<digitMap[digits[index]-'2'].length();i++)
    {
        letterSubset(digits,index+1,final+digitMap[digits[index]-'2'][i],digitMap,store);
    }
}

vector<string> letterCombinations(string digits) {
        vector<string> store;
        if(digits.length()==0)
        {
            return store;
        }
        vector<string> digitMap = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        letterSubset(digits,0,"",digitMap,store);
        return store;        
}


int main()
{
    string digits = "";
    vector<string> store = letterCombinations(digits);
    for(int i=0;i<store.size();i++)
    {
        cout<<store[i]<<" ";
    }
    cin.get();
    return 0;
}

