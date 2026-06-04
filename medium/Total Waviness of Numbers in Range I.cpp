class Solution {
public:
    int totalWaviness(int num1, int num2) 
    {
        int ans=0;
        for(int i=num1;i<=num2;i++)
        {
            string s=to_string(i);
            for(int i=1;i<s.size()-1;i++)
            {
                if(s[i-1]<s[i] && s[i]>s[i+1])ans++;
                if(s[i-1]>s[i] && s[i]<s[i+1])ans++;
            }
        }
        return ans;
    }
};
