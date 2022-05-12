/*
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

*/



#include <iostream>
#include <chrono>
#include <vector>
#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // sort the candidates
        std::sort(candidates.begin(), candidates.end());

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
            backtrack(answer,current,candidates, remain - candidates[i], i);
            current.pop_back();
        }
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();
    Solution solve;
    vector<vector<int>> answer = solve.combinationSum(candidates, target);

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