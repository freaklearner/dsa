#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    unordered_map<int,int> hash;
    int sum=0,len=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        if(sum==k)
        {
            len = max(len,i+1);
        }
        if(hash.find(sum-k)!=hash.end())
        {
            len = max(len,i=hash[sum-k]);
        }
        if(hash.find(sum)==hash.end())
        {
            hash[sum]=i;
        }
    }
    return len;
}

int main()
{
    vector<int> nums = {100000,-999812,-218};
    int k = 0;
    cout<< getLongestSubarray(nums,k);
    return 0;
}
