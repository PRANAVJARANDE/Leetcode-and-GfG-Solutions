class Solution {
public:
    string chooseSwap(string &s) {
        int n = s.size();
        vector<vector<int>>lpos(n,vector<int>(26,-1));
        for(int i=n-1;i>=0;i--) 
        {
            if(i+1<n)lpos[i] = lpos[i + 1];
            lpos[i][s[i]-'a']=i;
        }
        vector<int>vis(26,0);
        char c1='0',c2='0';
        for(int i=0;i<n;i++) 
        {
            bool found=0;
            for(int j=0;j<s[i]-'a';j++) 
            {
                if(lpos[i][j]>i && vis[j]==0) 
                {
                    c1=s[i];
                    c2='a'+j;
                    found=true;
                    break;
                }
            }
            vis[s[i]-'a']=1;
            if(found)break;
        }
        if(c1=='0')return s;
        for(int i=0;i<n;i++) 
        {
            if(s[i]==c1)s[i]=c2;
            else if(s[i]==c2)s[i]=c1;
        }
        return s;
    }
};
