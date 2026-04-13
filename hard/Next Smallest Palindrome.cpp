class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) 
    {
        int n=num.size();
        bool flag=1;
        for(auto x:num) 
        {
            if(x!=9) 
            {
                flag=0;
                break;
            }
        }

        if(flag) 
        {
            vector<int>ans(n+1,0);
            ans[0]=1;
            ans[n]=1;
            return ans;
        }
        vector<int>temp=num;
        for(int i=0;i<n/2;i++)temp[n-i-1]=temp[i];
        if(temp>num)return temp;

        for(int i=(n-1)/2;i>=0;i--)
        {
            if(temp[i]!=9) 
            {
                temp[i]++;
                temp[n-i-1]=temp[i];
                return temp;
            } 
            temp[i]=0;
            temp[n-i-1]=0;
        }
        return temp;
    }
};
