/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

 bool compInterval(const Interval &a, const Interval &b) {
    return a.end < b.end;
}

bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<priority_queue<Interval, vector<Interval>, bool(*)(const Interval&, const Interval&)>> schedule;

        sort(intervals.begin(), intervals.end(), compare);

        for (auto interval: intervals) {
            int idx = 0;
            bool flag = false;
            
            for (; idx < schedule.size(); idx++) {
                if (schedule[idx].top().end <= interval.start) {
                    
                    schedule[idx].push(interval);
                    flag = true;
                    break;
                }   
            }
            
            if (!flag) {
                priority_queue<Interval, vector<Interval>, bool(*)(const Interval&, const Interval&)> new_schedule(compInterval);
                new_schedule.push(interval);
                schedule.push_back(new_schedule);
            }  
        }

        return schedule.size();
    }
};
