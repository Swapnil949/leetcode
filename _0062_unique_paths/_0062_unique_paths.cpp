#include <chrono>
#include <iostream>

class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        if (m < 1 || n < 1)
            return 1;

        uint32_t array[m][n];

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (i > 0 && j > 0)
                {
                    array[i][j] = array[i-1][j] + array[i][j-1];
                }
                else if (i > 0 || j > 0)
                {
                    array[i][j] = 1;
                }
            }
        }

        return array[m - 1][n - 1];
    }
};

int main()
{
    int m = 3, n = 7;

    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();

    Solution solve;
    int ans = solve.uniquePaths(m, n);

    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    std::cout << "Answer = " << ans << std::endl;
    std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds." << std::endl;
    return 0;
}