class Solution {
public:
int reachNumber(int target) {
    target = abs(target);
    int k = 0;
    int sum = 0;
    
    // Find smallest k where sum >= target
    while (sum < target) {
        k++;
        sum += k;
    }
    
    // If difference is even, we're done
    if ((sum - target) % 2 == 0) return k;
    
    // Try k+1
    if ((sum + k + 1 - target) % 2 == 0) return k + 1;
    
    // Otherwise k+2
    return k + 2;
}
};