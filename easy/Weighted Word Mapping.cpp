class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) 
    {
        string res;
        for(auto x:words)
        {
            int ans=0;
            for(auto c:x)ans+=weights[c-'a'];
            ans=ans%26;
            ans=25-ans;
            char ch=ans+'a';
            res.push_back(ch);
        }
        return res;
    }
};
