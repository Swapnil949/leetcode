#include <chrono>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
  vector<string> letterCombinations(string digits)
  {
    vector<string> ans;
    int len = digits.length();
    if (len == 0)
        return ans;

    backtracking(digits, "", ans, 0, len);
    return ans;
  }

private:
  vector<string> map = { "",    "",    "abc",  "def", "ghi",
                         "jkl", "mon", "pqrs", "tuv", "wxyz" };

  void backtracking(string digits,
                    string str,
                    vector<string>& ans,
                    int start,
                    int len)
  {
    if (start == len)
      ans.push_back(str);
    else {
      string letters = map[digits[start] - '0'];

      for (auto i : letters) {
        backtracking(digits, str+i, ans, start+1, len);
      }
    }
  }
};

int
main()
{
  string input = "";
  // Start measuring time
  auto begin = std::chrono::high_resolution_clock::now();
  Solution solve;
  vector<string> ans = solve.letterCombinations(input);

  // Stop measuring time and calculate the elapsed time
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

  for (auto i : ans)
    std::cout << i << std::endl;

  std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds."
            << std::endl;
  return 0;
}