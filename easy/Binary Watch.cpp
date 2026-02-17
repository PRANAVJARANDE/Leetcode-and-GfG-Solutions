class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        if(turnedOn>8)return ans;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<60;j++)
            {
                if(__builtin_popcount(i) + __builtin_popcount(j)==turnedOn){
                    string h=to_string(i);
                    string m=to_string(j);
                    if(j<10)m="0"+m;
                    ans.push_back(h+":"+m);
                }
            }
        }
        return ans;
    }
};
