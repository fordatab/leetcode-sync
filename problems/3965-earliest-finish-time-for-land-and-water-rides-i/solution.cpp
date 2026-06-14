class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int out = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                // int landEnd = landStartTime[i] + landDuration[i];
                // int waterEnd = waterStartTime[j] + waterDuration[j];
                // if (landEnd <= waterStartTime[j]) {
                //     out = min(out, waterEnd);
                // } 
                // if (waterEnd <= landStartTime[i]) {
                //     out = min(out, landEnd);
                // }
                if (landStartTime[i] + landDuration[i] >= waterStartTime[j]) {
                    out = min(out, landStartTime[i] + landDuration[i] + waterDuration[j]); 
                }
                if (waterStartTime[j] + waterDuration[j] >= landStartTime[i]) {
                    out = min(out, waterStartTime[j] + waterDuration[j] + landDuration[i]); 
                }
                if (waterStartTime[j] + waterDuration[j] < landStartTime[i]) {
                    out = min(out, landStartTime[i] + landDuration[i]);
                }
                if (landStartTime[i] + landDuration[i] < waterStartTime[j]) {
                    out = min(out, waterStartTime[j] + waterDuration[j]);
                }
                // int out = min(out, min(landStartTime[i] + landDuration[i]))
            }
        }
        return out;
    }
};