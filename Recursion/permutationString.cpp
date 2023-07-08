#include<iostream>
using namespace std;

void permutationString(char str[],int idx)
{   
    if(str[idx]=='\0')
    {
        cout<<str<<endl;
        return;
    }
    for(int i=idx;str[i]!='\0';i++)
    {
        swap(str[idx],str[i]);
        permutationString(str,idx+1);
        swap(str[idx],str[i]);
    }
    
}
int main()
{
    char str[]="abc";
    permutationString(str,0);
    cin.get();
    return 0;
}
