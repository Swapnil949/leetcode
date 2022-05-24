#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // sort the candidates
        std::sort(candidates.begin(), candidates.end());
        vector<bool> candidatesUsed;
      //  std::unique(candidates.begin(), candidates.end());

        vector<vector<int>> answer;
        vector<int> current;
        
        backtrack(answer, current, candidates, target, 0);

        return answer;
    }

private:
    void backtrack(vector<vector<int>> &answer, vector<int> &current,
                   vector<int> &candidates, int remain, int start)
    {
        if(remain < 0)
            return;
        
        if (remain == 0)
        {
            answer.push_back(current);
            return;
        }
        
        for(int i = start; i < candidates.size(); i++)
        {
            current.push_back(candidates[i]);

            int temp = current.back();
            backtrack(answer,current,candidates, remain - candidates[i], i+1);
            current.pop_back();
        }
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();
    Solution solve;
    vector<vector<int>> answer = solve.combinationSum2(candidates, target);

    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            std::cout << answer[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds." << std::endl
              << std::endl;
    return 0;
}