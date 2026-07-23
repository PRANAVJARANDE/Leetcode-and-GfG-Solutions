class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>v1(2049,0);
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int xs=nums[i]^nums[j];
                v1[xs]=1;
            }
        }

        vector<int>present(1501,0);
        for(auto x:nums)
        {
            present[x]=1;
        }

        int ans=0;
        for(int op=0;op<2049;op++)
        {
            for(int i=0;i<2049;i++)
            {
                if(v1[i]==1)
                {
                    int xs=i^op;
                    if(xs<=1500 && present[xs])
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
