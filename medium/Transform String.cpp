class Solution {
  public:
    int transform(string &s1, string &s2) 
    {
        if(s1.size()!=s2.size())return -1;
        int n=s1.size();
        
        unordered_map<char,int>cnt;
        for(int i=0;i<n;i++)
        {
            cnt[s1[i]]++;
            cnt[s2[i]]--;
        }
        for(auto x:cnt)if(x.second!=0)return -1;
        
        int ans=0;
        int i=n-1,j=n-1;
        while(i>=0 && j>=0)
        {
            while(i>=0 && s1[i]!=s2[j])
            {
                i--;
                ans++;
            }
            i--;
            j--;
            
        }
        return ans;
    }
};
