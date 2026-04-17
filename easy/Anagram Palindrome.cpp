class Solution {
  public:
    bool canFormPalindrome(string &s) {
        map<int,int>m;
        for(auto x:s)m[x]=1-m[x];
        int cnt=0;
        for(auto x:m)if(x.second%2)cnt++;
        if(cnt>=2)return 0;
        return 1;
    }
};
