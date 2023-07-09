#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void permUnique(vector<int> &nums,int i,vector<vector<int>> &store)
{
    if(i==nums.size())
    {
        //cout<<string(nums.begin(),nums.end())<<" ";
        store.push_back(nums);
        return;
    }
    int freq[21] = {0};
    for(int j=i;j<nums.size();j++)
    {
        if(freq[10+nums[j]]==0)
        {
            swap(nums[i],nums[j]);
            permUnique(nums,i+1,store);
            swap(nums[i],nums[j]);
            freq[10+nums[j]]=1;

        }
    }

}
int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> store;
    permUnique(nums,0,store);
    for(vector<int> nums: store)
    {
        for(int num: nums)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    cin.get();
    return 0;
}


