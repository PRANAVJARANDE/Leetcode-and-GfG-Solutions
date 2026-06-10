#define ll long long
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) 
    {
        int n=nums.size();
        vector<ll>d(n,0);
        for(int i=0;i<n;i++)d[i]=target[i]-nums[i];

        vector<vector<ll>>dpos,dneg;
        for(int i=0;i<n;)
        {
            if(d[i]==0)
            {
                i++;
                continue;
            }   
            int in=i;
            vector<ll>temp;
            while(in<n && d[i]*d[in]>0)
            {
                temp.push_back(abs(d[in]));
                in++;
            }
            dpos.push_back(temp);
            i=in;
        }

        ll ans=0;
        for(auto v1:dpos)
        {
            ans+=v1[0];
            for(int i=1;i<v1.size();i++)ans+=max(0LL,v1[i]-v1[i-1]);
        }
        return ans;
    }
};
