class Solution {
  public:
    bool pythagoreanTriplet(vector<int>&a) 
    {
        vector<int>freq(1001,0);
        for(auto x:a)freq[x]++;
        
        for(int i=0;i<1001;i++)
        {
            for(int j=i;j<1001;j++)
            {
                if(i==j)
                {
                    if(freq[i]>=2)
                    {
                        int cs=i*i+j*j;
                        int c=sqrt(cs);
                        if(c*c==cs && freq[c]>=1)return 1;
                    }
                }
                else
                {
                    if(freq[i]>=1 && freq[j]>=1)
                    {
                        int cs=i*i+j*j;
                        int c=sqrt(cs);
                        if(c*c==cs && freq[c]>=1)return 1;
                    }
                }
            }
        }
        return 0;
    }
};
