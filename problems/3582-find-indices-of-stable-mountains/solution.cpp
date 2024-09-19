class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> out;
        for (int x = 1; x < height.size(); x++) {
            if (height[x-1] > threshold) {
                out.push_back(x);
            }
        }
        return out;
    }
};