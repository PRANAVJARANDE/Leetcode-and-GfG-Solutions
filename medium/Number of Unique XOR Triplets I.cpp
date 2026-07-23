class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<=2)return n;

        int in=0;
        while(n)
        {
            n/=2;
            in++;
        }
        int ans=powl(2,in);
        return ans;
    }
};
