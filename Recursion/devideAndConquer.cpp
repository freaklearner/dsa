#include <iostream>

using namespace std;

int calculateExponentional(int n, int k)
{
    if(k==0)
    {
        return 1;
    }
    int val = calculateExponentional(n,k/2);
    if(k%2==0)
    {
        return val*val;
    }
    else
    {
        return val*val*n;
    }
}

int main(){
    int n=2,k=5;
    // cin>>n>>k;
    cout<<calculateExponentional(n,k)<<endl;
    return 0;
}
