class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) 
    {
        set<int>s1;
        for(auto x:flowers)
        {
            s1.insert(x[0]);
            s1.insert(x[1]+1);
            s1.insert(x[0]-1);
            s1.insert(x[1]+2);
        }
        map<int,int>m;
        int in=0;
        for(auto x:s1)m[x]=in++;
        vector<int>v1(s1.begin(),s1.end());


        vector<int>dp(in,0);
        for(auto x:flowers)
        {
            dp[m[x[0]]]++;
            dp[m[x[1]+1]]--;
        }
        for(int i=1;i<in;i++)dp[i]+=dp[i-1];
        vector<int>ans;
        for(auto x:people)
        {
            auto in=upper_bound(v1.begin(),v1.end(),x)-v1.begin()-1;
            int res=0;
            if(in!=-1)res=dp[in];
            ans.push_back(res);
        }
        return ans;
    }
};
