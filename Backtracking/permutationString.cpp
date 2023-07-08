#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void permutation(string str, int i)
{
    if(i==str.length())
    {
        cout<<str<<endl;
        return;
    }
    for(int j=i;j<str.length();j++)
    {
        swap(str[i],str[j]);
        permutation(str,i+1);
        swap(str[i],str[j]);
    }

}

int main()
{
    string str= "ABC";
    permutation(str,0);
    cin.get();
    return 0;
}