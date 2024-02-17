class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Number of rows in the grid
        int m = grid.size();  
        // Number of columns in the grid
        int n = grid[0].size();  
        
        // Build the initial set of rotten oranges
        // Queue for BFS traversal
        queue<pair<int, int>> q;  

        // Counter for fresh oranges
        int fresh = 0;  
        
        // Iterate through the grid to find fresh and rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    // Add initially rotten oranges to the queue
                    q.push({i, j});  
                } else if (grid[i][j] == 1) {
                    // Count the number of fresh oranges
                    fresh++;  
                }
            }
        }
        
        // Mark the start of a minute
        q.push({-1, -1});
        
        // Counter for minutes
        int result = -1;  
        
        // Start the rotting process via BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if (row == -1) {
                // Finish 1 minute of processing, mark next minute
                result++;
                if (!q.empty()) {
                    q.push({-1, -1});
                }
            } else {
                // Rotten orange, contaminate its neighbors
                for (int i = 0; i < dirs.size(); i++) {
                    int x = row + dirs[i][0];
                    int y = col + dirs[i][1];
                    
                    // Check if the neighboring position is in bounds
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    
                    if (grid[x][y] == 1) {
                        // Contaminate the fresh orange
                        grid[x][y] = 2;
                        fresh--;  // Decrement the count of fresh oranges
                        // This orange will now contaminate others, so add to the queue
                        q.push({x, y});
                    }
                }
            }
        }
        
        // Check if all oranges are rotten, return the time taken; otherwise, return -1
        if (fresh == 0) {
            return result;
        }
        return -1;
    }

private:
     // Define directions: up, down, left, right
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
};