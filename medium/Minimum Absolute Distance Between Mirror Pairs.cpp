class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=INT_MAX;
        map<int,int>rev1;
        for(int i=0;i<n;i++)
        {
            if(rev1.find(nums[i])!=rev1.end())ans=min(ans,abs(i-rev1[nums[i]]));
            int r=0;
            int tp=nums[i];
            while(tp)
            {
                r*=10;
                r+=tp%10;
                tp/=10;
            }
            rev1[r]=i;
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
