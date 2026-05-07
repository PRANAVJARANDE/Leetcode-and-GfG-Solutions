class Solution {
public:
    int rotatedDigits(int n) 
    {
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            int num=i;
            bool flag=1;
            bool diff=0;
            while(num)
            {
                int rem=num%10;
                if(rem==3 || rem==4 || rem==7)
                {
                    flag=0;
                    break;
                }
                if(rem==2 || rem== 5 || rem==6 || rem==9)diff=1;
                num/=10;
            }
            if(flag && diff)ans++;
        }
        return ans;
    }
};
