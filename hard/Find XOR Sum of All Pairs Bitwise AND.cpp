class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) 
    {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            long long c1=0,c2=0;
            for(auto x:arr1)if(x & (1<<i))c1++;
            for(auto x:arr2)if(x & (1<<i))c2++;
            long long cnt=(c1*c2)%2;
            if(cnt)ans=ans | (1<<i);
        }
        return ans;
    }
};
