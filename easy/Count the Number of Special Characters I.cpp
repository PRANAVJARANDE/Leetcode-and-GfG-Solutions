class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        vector<int>m1(26,0),m2(26,0);
        for(auto x:word)
        {
            if('a'<=x && x<='z')m1[x-'a']++;
            else m2[x-'A']++;
        }
        int ans=0;
        for(int i=0;i<26;i++)if(m1[i]>0 && m2[i]>0)ans++;
        return ans;
    }
};
