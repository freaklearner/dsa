#include<iostream>
#include<vector>
#include<map>
using namespace std;

int mostFrequent(vector<int> &nums, int k)
{
    map<int,int> frq;

    for(int n : nums)
    {
        frq[n]+=1;
    }
    int maxCount = 1;
    for(auto key =  frq.begin();key!=frq.end()&&k>=0 &&maxCount<nums.size();++key)
    {
        cout<<key->first<<" --  "<<key->second<<"  ------k: "<<k<<endl;
        for(int i=1;i<=k;i++)
        {

            if(frq.find(key->first+i)!=frq.end())
            {
                cout<<"i: "<<i<<endl;
                if(i*key->second<=k)
                {
                    frq[key->first+i]+=key->second;
                    k-=i*key->second;
                }
                else{
                    cout<<"init-----------------------------------------------------------------"<<endl;
                    frq[key->first+i]+=k/i;
                    k=k%i;
                }
                maxCount = max(maxCount,frq[key->first+i]);
                break;
            }
        }
    }
    return maxCount;
}

int main()
{
    vector<int> nums = {9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966};
    cout<<mostFrequent(nums,3056);
    cin.get();
    return 0;
}