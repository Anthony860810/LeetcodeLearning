bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {   
public:

bool canAttendMeetings(vector<Interval>& intervals) {
    if (!intervals.size())
        return true;

    sort(intervals.begin(), intervals.end(), compare);

    for (int idx = 0; idx < intervals.size() - 1; idx++) {
        if (intervals[idx].end > intervals[idx+1].start)
            return false;  
    }

    return true;
}
};