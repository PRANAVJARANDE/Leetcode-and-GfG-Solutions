class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        vector<int>cnt(26,0);
        for(auto x:text)cnt[x-'a']++;
        string s="ban";
        int mini=INT_MAX;
        for(auto x:s)mini=min(mini,cnt[x-'a']);
        mini=min(mini,cnt['l'-'a']/2);
        mini=min(mini,cnt['o'-'a']/2);
        return mini;
    }
};
