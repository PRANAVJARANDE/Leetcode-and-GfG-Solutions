class MajorityChecker {
public:

    vector<vector<int>>m;
    vector<int>arr;
    MajorityChecker(vector<int>& a) 
    {
        arr=a;
        m.resize(20004);
        for(int i=0;i<(int)arr.size();i++)m[arr[i]].push_back(i);
    }

    int check(int val,int l,int r)
    {
        auto j=upper_bound(m[val].begin(),m[val].end(),r)-m[val].begin();
        auto i=lower_bound(m[val].begin(),m[val].end(),l)-m[val].begin();
        return j-i;
    } 
    
    int query(int left, int right, int threshold) 
    {
        int sz=right-left+1;
        int mx=100;
        while(mx--)
        {
            int in=left+(rand()%sz);
            if(check(arr[in],left,right)>=threshold)return arr[in];
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
