class Solution {
private:
    // Helper function to find the minimum finish time 
    // assuming we MUST take a ride from category 1 first, then category 2
    int solve(const vector<int>& start1, const vector<int>& dur1, 
              const vector<int>& start2, const vector<int>& dur2) {
        
        int n = start1.size();
        int m = start2.size();
        
        // Pair up start times and durations for the second category so we can sort them
        vector<pair<int, int>> cat2(m);
        for (int i = 0; i < m; ++i) {
            cat2[i] = {start2[i], dur2[i]};
        }
        
        // Step 1: Sort the second category based on start times
        sort(cat2.begin(), cat2.end());
        
        // Step 2: Precompute Prefix Minimums (for Group 1: starts <= finish1)
        // Stores the minimum duration seen so far from the left
        vector<int> prefMinDur(m);
        prefMinDur[0] = cat2[0].second;
        for (int i = 1; i < m; ++i) {
            prefMinDur[i] = min(prefMinDur[i - 1], cat2[i].second);
        }
        
        // Step 3: Precompute Suffix Minimums (for Group 2: starts > finish1)
        // Stores the minimum (startTime + duration) seen so far from the right
        vector<int> suffMinFinish(m);
        suffMinFinish[m - 1] = cat2[m - 1].first + cat2[m - 1].second;
        for (int i = m - 2; i >= 0; --i) {
            suffMinFinish[i] = min(suffMinFinish[i + 1], cat2[i].first + cat2[i].second);
        }
        
        int bestFinishTime = 2e9; // Start with a very large number
        
        // Step 4: Iterate through all rides in category 1
        for (int i = 0; i < n; ++i) {
            int finish1 = start1[i] + dur1[i];
            
            // Binary search to find the split point where cat2 starts strictly after finish1
            int left = 0, right = m - 1;
            int splitIdx = m; // Default to m if all rides start <= finish1
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (cat2[mid].first > finish1) {
                    splitIdx = mid;
                    right = mid - 1; // Try to find an earlier one
                } else {
                    left = mid + 1;
                }
            }
            
            int currentBest = 2e9;
            
            // Group 1: Second ride starts before or exactly when the first finishes
            // We just add the minimum duration from this group
            if (splitIdx > 0) {
                currentBest = min(currentBest, finish1 + prefMinDur[splitIdx - 1]);
            }
            
            // Group 2: Second ride starts after the first finishes
            // We must wait, so our total finish time is the second ride's (start + duration)
            if (splitIdx < m) {
                currentBest = min(currentBest, suffMinFinish[splitIdx]);
            }
            
            // Update the global best for this specific order
            bestFinishTime = min(bestFinishTime, currentBest);
        }
        
        return bestFinishTime;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                      vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        // Check Order 1: Land first, Water second
        int landFirst = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        
        // Check Order 2: Water first, Land second
        int waterFirst = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        
        // Return the minimum of the two valid paths
        return min(landFirst, waterFirst);
    }
};