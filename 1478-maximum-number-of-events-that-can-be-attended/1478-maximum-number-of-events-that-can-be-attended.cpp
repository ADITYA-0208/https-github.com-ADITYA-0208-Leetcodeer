class Solution {
public:
    static bool customComparator(const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1])
            return a[1] < b[1];  
        return a[0] < b[0];      
    }

    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), customComparator);
        set<int> availableDays;
        // Insert all possible days up to max end day
        for (int i = 1; i <= 1e5; i++) availableDays.insert(i);

        int count = 0;
        for (auto& event : events) {
            auto it = availableDays.lower_bound(event[0]); // first available day ≥ start
            if (it != availableDays.end() && *it <= event[1]) {
                count++;
                availableDays.erase(it); // assign this day
            }
        }
        return count;
    }
};
