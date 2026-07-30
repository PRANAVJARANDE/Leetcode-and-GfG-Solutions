class Solution {
public:
    int minimumPushes(string word) 
    {
        vector<int>v1(26,0);
        for(auto x:word)v1[x-'a']++;

        vector<int>freq;
        for(auto x:v1)if(x!=0)freq.push_back(x);

        sort(freq.begin(),freq.end(),greater<int>());

        int ans=0;
        for(int i=0;i<freq.size();i++)
        {
            ans+=freq[i]*((i/8)+1);
        }   
        return ans;
    }
};
