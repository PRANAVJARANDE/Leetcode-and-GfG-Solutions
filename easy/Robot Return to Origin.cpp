class Solution {
public:
    bool judgeCircle(string moves) 
    {
        int c1=0,c2=0;
        for(auto x:moves)
        {
            if(x=='L')c1++;
            else if(x=='R')c1--;
            else if(x=='U')c2++;
            else c2--;
        }
        return c1==0 && c2==0;
    }
};
