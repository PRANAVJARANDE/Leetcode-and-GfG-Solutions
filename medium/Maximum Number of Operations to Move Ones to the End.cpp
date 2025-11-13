class Solution {
public:
    int maxOperations(string s) 
    {
        int n=s.size();
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')cnt++;
            else
            {
                ans+=cnt;
                while(i<n && s[i]=='0')
                {
                    i++;
                }
                i--;
            }
        }
        return ans;
    }
};
