class Solution {
  public:
  
    int helper(string&s,int k)
    {
        int ans=0;
        int l=0;
        vector<int>m(26,0);
        int dis=0;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]-'a']++;
            if(m[s[i]-'a']==1)dis++;
            while(dis>k)
            {
                m[s[l]-'a']--;
                if(m[s[l]-'a']==0)dis--;
                l++;
            }
            ans+=i-l+1;
        }
        return ans;
    }
    
    int countSubstr(string& s, int k) {
        return helper(s,k)-helper(s,k-1);
    }
};
