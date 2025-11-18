class Solution {
public:
    bool isOneBitCharacter(vector<int>& a) 
    {
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                if(i==n-1)return 1;
            }
            else
            {
                i++;
            }
        }
        return 0;
    }
};
