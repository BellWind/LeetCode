class Solution {
    class cmp{
    public:
        inline bool operator()(const Interval& a, const Interval& b) const {
            return (a.start == b.start) ? (a.end < b.end) : (a.start < b.start);
        }
    };
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        ans.clear();
        if(intervals.size() == 0)
            return ans;
        sort(intervals.begin(), intervals.end(), cmp());
        int k = 0;
        while(k < intervals.size()) {
            Interval tmp;
            int st = intervals[k].start, ed = intervals[k].end;
            while(k + 1 < intervals.size() && ed >= intervals[k + 1].start)
                ed = max(ed, intervals[++k].end);
            tmp.start = st, tmp.end = ed;
            ans.push_back(tmp);
            k++;
        }
        return ans;
    }
private:
    vector<Interval> ans;
};
