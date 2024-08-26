#include <iostream>
#include <vector>

int compareElementsByIndex(std::vector<int> nums)
{

    if(nums.size()==1)
        return nums[0];
    else
    {
        int n=nums.size();        
        int sum=0;

        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        int t=0;
        
        for(int i=0;i<n;i++)
        {
            if(sum-(t+nums[i])==t)
                 return i;
            t+=nums[i];
        }
    return -1;
    }


}