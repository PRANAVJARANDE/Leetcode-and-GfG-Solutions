class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int ans=0;
        int pcnt=0;
        int n=s.size();
        for(int i=0;i<n;)
        {
            char c=s[i];
            int cnt=0;
            while(i<n && s[i]==c)
            {
                i++;
                cnt++;
                if(cnt<=pcnt)ans++;
            }
            pcnt=cnt;
        }
        return ans;
    }
};
