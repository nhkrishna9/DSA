
// User function template for C++

class Solution {
  public:
    void Helper(vector<string>& ans, vector<vector<int>>& maze, int n, int i, int j, string S){
        
        if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0){
            return;
        }
        
        if(i == n-1 && j == n-1){
            if(maze[i][j] == 1){
                ans.push_back(S);
                return;
            }
        }

        maze[i][j] = 0;
        Helper(ans, maze, n, i-1, j, S+'U');
        Helper(ans, maze, n, i+1, j, S+'D');
        Helper(ans, maze, n, i, j-1, S+'L');
        Helper(ans, maze, n, i, j+1, S+'R');
        maze[i][j] = 1;

    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        int n = maze.size(); // This is row size/ col size bcoz of square matrix
        Helper(ans, maze, n, 0, 0, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};
