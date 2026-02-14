class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) 
    {
        map<pair<char,char>,int>m;
        for(auto x:mappings)m[{x[0],x[1]}]=1;

        int n=s.size();
        int sz=sub.size();

        for(int i=0;i<=n-sz;i++)
        {
            bool flag=1;
            int j=0;
            while(j<sz)
            {
                if(sub[j]!=s[i+j])
                {
                    if(m[{sub[j],s[i+j]}]==0)
                    {
                        flag=0;
                        break;
                    }
                }
                j++;
            }
            if(flag==1)return 1;
        }
        return 0;
    }
};
