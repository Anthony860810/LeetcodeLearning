class MyCalendar {
    public:
        vector<pair<int, int>> calendar;
        MyCalendar() {
            
        }
        
        bool book(int startTime, int endTime) {
            for (int idx = 0; idx < calendar.size(); idx++) {
                if ((calendar[idx].first < startTime && startTime < calendar[idx].second) ||
                    (calendar[idx].first < endTime && endTime < calendar[idx].second))
                    return false;
                if (startTime <= calendar[idx].first && calendar[idx].second <= endTime)
                    return false;
            }
            calendar.push_back({startTime, endTime});
            return true;
        }
    };
    
    /**
     * Your MyCalendar object will be instantiated and called as such:
     * MyCalendar* obj = new MyCalendar();
     * bool param_1 = obj->book(startTime,endTime);
     */