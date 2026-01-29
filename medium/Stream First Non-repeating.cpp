class Solution {
  public:
    string firstNonRepeating(string &s) 
    {
        int n=s.size();
        vector<int>freq(26,0);
        vector<int>first_occ(26,-1);
        string ans(n,'#');
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
            if(first_occ[s[i]-'a']==-1)first_occ[s[i]-'a']=i;
            int in=n;
            for(int j=0;j<26;j++)
            {
                if(freq[j]==1)
                {
                    in=min(in,first_occ[j]);
                }
            }
            if(in!=n)ans[i]=s[in];
        }
        return ans;
    }
};
