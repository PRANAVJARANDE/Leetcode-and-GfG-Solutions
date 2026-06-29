class Solution {
public:

    vector<int> getlps(string&s)
    {
        int n=s.size();
        vector<int>lps(n,-1);

        int in=-1;
        for(int i=1;i<n;i++)
        {
            while(in!=-1 && s[in+1]!=s[i])
            {
                in=lps[in];
            }
            if(s[in+1]==s[i])in++;
            lps[i]=in;
        }
        return lps;
    }

    bool search(string&s,string&t)
    {
        int m=t.size();
        vector<int>lps=getlps(t);
        int in=-1;
        for(auto c:s)
        {
            while(in!=-1 && t[in+1]!=c)
            {
                in=lps[in];
            }
            if(t[in+1]==c)in++;
            if(in==m-1)return 1;
        }
        return 0;
    }


    int numOfStrings(vector<string>& patterns, string word) 
    {
        int ans=0;
        for(auto t:patterns)
        {
            if(search(word,t))ans++;
        }
        return ans;
    }
};
