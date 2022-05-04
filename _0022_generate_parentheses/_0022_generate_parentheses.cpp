#include <iostream>
#include <chrono>
#include <vector>

using std::vector;
using std::string;

class Solution
{
private:
	void backtracking(vector<string> &ans, string s, int n, int open, int close)
	{
		vector<string> answer;

		if (open == n && close == n)
		{
			ans.push_back(s);
			return;
		}
		if (open < n)
		{
			backtracking(ans, s.append("("), n, open + 1, close);
			// s.pop_back();
		}
		if (close < open)
		{
			backtracking(ans, s.append(")"), n, open, close + 1);
			// s.pop_back();
		}
	}

public:
	vector<string> generateParenthesis(int n)
	{

		vector<string> answer;
		backtracking(answer, "", n, 0, 0);
		return answer;
	}
};
int main()
{
	int n = 3;

	// Start measuring time
	auto begin = std::chrono::high_resolution_clock::now();
	Solution solve;

	vector<string> answer = solve.generateParenthesis(n);

	// Stop measuring time and calculate the elapsed time
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	for (auto i:answer)
    {
        std::cout << i << std::endl;
    }
	std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds." << std::endl
			  << std::endl;
	return 0;
}