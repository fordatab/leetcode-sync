class Solution {
public:
    long long dividePlayers(vector<int>& v) {
        long long ans = 0;
        int n = v.size();
        unordered_map<int,int> mp;


        long long tar = 0;
        for(auto x:v){
            tar+=x;
            mp[x]++;
        }
        if(tar%(n/2)!=0) return -1;
        tar = (tar/(n/2));
        cout<<tar<<endl;
        for(auto [x,freq]:mp){
            int rem = tar - x;
            if(mp.find(rem)==mp.end() or freq != mp[rem]) return -1;

            ans += 1LL*x*rem*freq;
        }
        return ans/2;
    }
};