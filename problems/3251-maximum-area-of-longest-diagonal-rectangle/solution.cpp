class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& v) {
        int a = 0, b = 0;
        for(const auto &i: v){
            if(i[0]*i[0]+i[1]*i[1] > a){
                a = i[0]*i[0]+i[1]*i[1];
                b = i[0]*i[1];
            }else if(i[0]*i[0]+i[1]*i[1] == a){
                b = max(b,i[0]*i[1]);
            }
        }
        return b;
    }
};