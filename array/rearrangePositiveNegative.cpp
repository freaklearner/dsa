#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
        int i=0,j=1;
        for(int t=0;t<nums.size();t++)
        {
            if(t%2==0 && nums[t]<0 || t%2==1 && nums[t]>0)
            {
                int element = nums[t];
                int index = element>0?i:j;
                while(index!=t)
                {
                    int temp = nums[index];
                    nums[index] = element;
                    if(element>0)
                    {
                        i+=2;
                    }
                    else{
                        j+=2;
                    }
                    element = temp;
                    index=element>0?i:j;
                }
                nums[index] = element;
                if(element>0)
                {
                    i+=2;
                }
                else{
                    j+=2;
                }
            }
            if(t==i)
            {
                i+=2;
            }
            if(t==j)
            {
                j+=2;
            }
            for(int x : nums)
            {
                cout<<x<<" ";
            }
            cout<<endl;

        }
        return nums;   
    }

int main()
{
    vector<int> nums = {3,1,-2,-5,2,-4};
    rearrangeArray(nums);
    return 0;
}