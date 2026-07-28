class Solution {
public:
    string smallestPalindrome(string s) 
    {
        int n=s.size();
        int mid=n/2;

        vector<char>v1;
        for(int i=0;i<mid;i++)v1.push_back(s[i]);
        sort(v1.begin(),v1.end());

        for(int i=0;i<mid;i++)s[i]=v1[i];

        int in=v1.size()-1;
        for(int i=(n+1)/2;i<n;i++)
        {
            s[i]=v1[in--];
        }

        
        return s;
    }
};
