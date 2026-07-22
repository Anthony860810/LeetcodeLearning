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

 bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> meeting_room;

        sort(intervals.begin(), intervals.end(), compare);

        for (const auto& interval : intervals) {
            if (!meeting_room.empty() && meeting_room.top() <= interval.start) {
                meeting_room.pop();
            }
            meeting_room.push(interval.end);
        }
        return meeting_room.size();
    }
};
