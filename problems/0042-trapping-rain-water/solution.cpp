class Solution {
public:
    int trap(vector<int>& height) {
        // Initialize two pointers: left starts at beginning, right starts at end
        int l = 0, r = height.size()-1;
        
        // level tracks the current water level (maximum height seen so far from both sides)
        // water accumulates the total trapped water
        int level = 0, water = 0;
        
        // Continue until pointers meet
        while (l < r) {
            // Determine which side has the lower height
            // If left is lower, use height[l] and move left pointer right (l++)
            // If right is lower or equal, use height[r] and move right pointer left (r--)
            // The ternary operator elegantly combines comparison, selection, and pointer movement
            int lower = height[height[l] < height[r] ? l++ : r--];
            
            // Update the water level to be at least as high as the current bar
            // This represents the maximum height of water that can be held at this position
            level = max(level, lower);
            
            // Add trapped water at this position
            // Water trapped = current level - height of current bar
            // If the bar is at or above water level, this adds 0 (no water trapped)
            water += level - lower;
        }
        
        // Return total trapped water
        return water;
    }
};

/*
ALGORITHM EXPLANATION:
The key insight is that water trapped at any position depends on the minimum of:
- The maximum height to its left
- The maximum height to its right

The two-pointer approach works by:
1. Always processing the side with the lower boundary first
2. The lower boundary guarantees that water can be trapped up to 'level'
3. Moving inward from both ends until pointers meet

TIME COMPLEXITY: O(n) - single pass through the array
SPACE COMPLEXITY: O(1) - only uses a few variables

EXAMPLE with height = [0,1,0,2,1,0,1,3,2,1,2,1]:
- Start: l=0, r=11, level=0, water=0
- Compare height[0]=0 vs height[11]=1, move l (lower is 0)
- level=max(0,0)=0, water+=0-0=0
- Compare height[1]=1 vs height[11]=1, move l (equal, moves l)
- level=max(0,1)=1, water+=1-1=0
- Compare height[2]=0 vs height[11]=1, move l (lower is 0)
- level=max(1,0)=1, water+=1-0=1 (trap 1 unit!)
- ... continues until l meets r
- Final result: water = 6
*/