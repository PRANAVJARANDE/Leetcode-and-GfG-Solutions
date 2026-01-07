class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    set<int>s1;
    map<int,int>end;
    void addNum(int value) 
    {
        auto tir=s1.upper_bound(value);
        if(tir!=s1.begin())
        {
            tir--;
            int st=*tir;
            int en=end[st];
            if(st<=value && value<=en)return;
        }

        auto itr=s1.upper_bound(value);
        if(itr!=s1.end())
        {
            int st=*itr;
            if(st==value+1)
            {
                end[value]=end[st];
                end.erase(st);
                s1.erase(st);
                s1.insert(value);
            }
            else
            {
                end[value]=value;
                s1.insert(value);
            }
        }
        else
        {
            end[value]=value;
            s1.insert(value);
        }
        itr=s1.lower_bound(value);
        if(itr!=s1.begin())
        {
            itr--;
            int st=*itr;
            int en=end[st];
            if(en+1==value)
            {
                end[st]=end[value];
                s1.erase(value);
                end.erase(value);
            }
            else if(st<=value && value<=en)
            {
                s1.erase(value);
                end.erase(value);
            }
        }
    }
    
    vector<vector<int>> getIntervals() 
    {
        vector<vector<int>>ans;
        for(auto x:s1)
        {
            ans.push_back({x,end[x]});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
