#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());

        do
        {
            #if 0
            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i] << " ";
            }
            cout << "\n\r";
            #endif
            ans.push_back(nums);

        } while (std::next_permutation(nums.begin(), nums.end()));

        return ans;
    }
};

void printVectorArray2d(vector<vector<int>> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[i].size(); j++)
        {
            cout << array[i][j];
        }
                    cout << "\n\r";

    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;

    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();
    Solution solve;
    ans = solve.permute(nums);
    

    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Answer is : \n\r\t";
    printVectorArray2d(ans);
    std::cout << "\n\r";

    std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds.\n";
}