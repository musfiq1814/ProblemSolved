

#include<iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> topK;
        

        int count[nums.size()],temp;
        
        
        int i,j;
        
        for(i=0;i<nums.size();i++)
        {
            count[i] = 0;
            temp = nums[i];

            for(j=0;j<nums.size();j++)
            {
                if(nums[j]==temp)
                {
                    count[i]++;
                }
            }
        }
        for(i=0;i<nums.size();i++)
        {
            
        }



        
        return topK;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution S =  Solution();
    
    vector<int> num {1,1,1,3,2,2};

    int k = 2;

    S.topKFrequent(num,k);


}

