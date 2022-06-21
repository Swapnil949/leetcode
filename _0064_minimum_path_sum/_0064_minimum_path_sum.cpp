#include <chrono>
#include <iostream>
#include <vector>

using std::vector;

class Solution
{
  public:
    int minPathSum(vector<vector<int>> &grid)
    {

        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {

                if (i > 0 && j > 0)
                    grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
                else if (i > 0)
                    grid[i][0] += grid[i - 1][0];
                else if (j > 0)
                    grid[0][j] += grid[0][j - 1];
            }
        }

        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j <grid[0].size(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();

    Solution solve; 
    int ans = solve.minPathSum(grid);

    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end -   begin);

    std::cout << "answer = " << ans << std::endl;

    std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds." << std::endl;
    
    return 0;
}