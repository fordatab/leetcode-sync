class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i = 0; i < image.size(); i++) {
            reverse(image[i].begin(), image[i].end());

        }
        for (auto& r : image) {
            for (auto& c : r) {
                c = !c;
            }
        }
        return image;
    }
};