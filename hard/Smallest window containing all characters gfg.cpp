class Solution {
  public:
  
    bool canform(vector<int>&a,vector<int>&b)
    {
        for(int i=0;i<26;i++)if(a[i]<b[i])return 0;   
        return 1;
    }
    
    bool check(int mid,string&s,vector<int>&req)
    {
        vector<int>pr(26,0);
        for(int i=0;i<mid;i++)pr[s[i]-'a']++;
        if(canform(pr,req))return 1;
        for(int i=mid;i<s.size();i++)
        {
            pr[s[i-mid]-'a']--;
            pr[s[i]-'a']++;
            if(canform(pr,req))return 1;
        }
        return 0;
    }
  
    string minWindow(string &s, string &p) 
    {
        vector<int>req(26,0);
        for(auto x:p)req[x-'a']++;
        
        int n=s.size();
        int l=0,r=n;
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,s,req))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        if(ans==-1)return "";
        
        vector<int>pr(26,0);
        for(int i=0;i<ans;i++)pr[s[i]-'a']++;
        if(canform(pr,req))return s.substr(0,ans);
        for(int i=ans;i<s.size();i++)
        {
            pr[s[i-ans]-'a']--;
            pr[s[i]-'a']++;
            if(canform(pr,req))
            {
                return s.substr(i-ans+1,ans);
            }
        }
        return "";
    }
};
