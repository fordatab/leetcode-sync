/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    set<pair<int, int>> vis;

    void bw(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();    
    }

    void bt(Robot& robot, int x, int y, int d) {
        vis.insert({x, y});
        robot.clean();
        for (int i = 0; i < 4; i++) {
            int newd = (d + i) % 4;
            int nx = dirs[newd][0] + x;
            int ny = dirs[newd][1] + y;
            if (vis.find({nx, ny}) == vis.end() and robot.move()) {
                bt(robot, nx, ny, newd);
                bw(robot);
            } 
            robot.turnLeft();
        }
    }
    void cleanRoom(Robot& robot) {
        bt(robot, 0, 0, 0);
    }
};