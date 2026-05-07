class Solution {
  public:
    bool isBinaryPalindrome(int n) 
    {
        string s;
        while(n)
        {
            int rem=n%2;
            s=s+to_string(rem);
            n/=2;
        }
        
        n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])return 0;
        }
        return 1;
    }
};
