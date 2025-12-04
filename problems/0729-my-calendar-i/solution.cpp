class MyCalendar {
public:
    struct Interval {
        int start;
        int end;
    };
    vector<Interval> events;

    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        // Find first event that starts at or after startTime
        auto it = lower_bound(events.begin(), events.end(), startTime, 
            [](const Interval& a, int val) {
                return a.start < val;
            });
        
        // Check if new event overlaps with the next event
        if (it != events.end() && it->start < endTime) {
            return false;
        }
        
        // Check if new event overlaps with the previous event
        if (it != events.begin()) {
            auto prev = it - 1;
            if (prev->end > startTime) {
                return false;
            }
        }
        
        // No overlap, insert the event
        events.insert(it, {startTime, endTime});
        return true;
    }
};