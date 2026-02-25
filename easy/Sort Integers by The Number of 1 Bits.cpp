class Solution {
public:

    static bool cmp(int&a,int&b)
    {
        int n1=a,n2=b;
        int c1=0,c2=0;
        while(n1)
        {
            if(n1%2)c1++;
            n1/=2;
        }
        while(n2)
        {
            if(n2%2)c2++;
            n2/=2;
        }
        if(c1==c2)return a<b;
        else if(c1<c2)return 1;
        else return 0;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};
