class Solution {
  public:
    int longestKSubstr(string &s, int k) 
    {
        int ans=-1;
        int l=0;
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            while(m.size()>k)
            {
                m[s[l]]--;
                if(m[s[l]]==0)m.erase(s[l]);
                l++;
            }
            if(m.size()==k)ans=max(ans,i-l+1);
        }
        return ans;
    }
};
