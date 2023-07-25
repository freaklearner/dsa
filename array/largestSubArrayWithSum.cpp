#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayWithSumK(vector<int> &a, long long &k) {
    // Write your code here
    int n = a.size();
    long long sum=0;
    int maxCount=0, start=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        cout<<sum<<endl;
        while(sum>k)
        {
            sum-=a[start];
            start++;
        }
        if(sum==k)
        {
            cout<<"matched"<<endl;
            maxCount=max(maxCount,i-start+1);
        }
    }
    // while(sum>k && start<n)
    // {
    //     sum-=a[start];
    //     cout<<sum<<endl;
    //     if(sum==k)
    //     {
    //         maxCount=max(maxCount,n-start+1);
    //     }
    //     start++;
    // }
    return maxCount;

}

int main()
{
    vector<int> nums = {38289,33170,1859,23863,45658,24408,38353,21761,46411,41237,46956,33613,49349,26026,11031,19190,45358,32843,7054,14184,46050,19610,12625,14179,4066,6866,9996,34864,26222,1262,27512,40674,9793,14583,34325,23768,40373,10787,23397,2298,42342,26340,19552,1612,7014,44006,18885,14427,3821,41595,40575,26085,34594,49448,41457,37147,15003,18172,6585,29405,11315,29488,26525,40889,27485,31122,29281,8787,3008,41470,34402,9184,25736};
    long long k=526314;
    cout<<longestSubarrayWithSumK(nums, k);
    cin.get();
    return 0;
}