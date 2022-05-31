#include <chrono>
#include <iostream>
#include <algorithm>
using std::string;

class Solution
{
public:
  string addBinary(string a, string b)
  {
    string sum;

    size_t aLen = a.length();
    size_t bLen = b.length();

    bool aBool, bBool, carry;

    while (aLen > 0 || bLen > 0) {

      if (aLen > 0) {
        aBool = (a[aLen - 1] - '0') > 0;
        aLen--;
      } else
        aBool = false;

      if (bLen > 0) {
        bBool = (b[bLen - 1] - '0') > 0;
        bLen--;
      } else
        bBool = false;

      sum.push_back((aBool ^ bBool ^ carry) + '0');
      carry = (aBool & bBool) | (aBool & carry) | (bBool & carry);
    }

    if (carry)
        sum.push_back('1');

    std::reverse(sum.begin(), sum.end());
    return sum;
  }
};

int
main()
{
  string a = "11";
  string b = "1";
  // Start measuring time
  auto begin = std::chrono::high_resolution_clock::now();

  Solution solve;
  string sum = solve.addBinary(a, b);

  // Stop measuring time and calculate the elapsed time
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

  std::cout << sum << std::endl;
  std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds."
            << std::endl;
  return 0;
}