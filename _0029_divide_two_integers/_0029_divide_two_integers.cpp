#include <chrono>
#include <iostream>

class Solution
{
public:
  int divide(int dividend, int divisor)
  {

    int ans = 0;
    bool isNeg = false;

    if (dividend == INT32_MIN && divisor ==  - 1)
      return INT32_MAX;
      
    if (dividend == INT32_MIN && divisor == 1)
      return INT32_MIN;


    // if 31st bit is set, then -ve
    isNeg = (dividend >> 31 ^ divisor >> 31);

    uint32_t a = abs(dividend);
    uint32_t b = abs(divisor);

    // 31st bit is for the sign.
    for (int i = 31; i >= 0; i--) {
      if (a >> i >= b)
      {
        ans += 1 << i;
        a -= b << i;
      }
    }

    return (isNeg) ? -1 * ans : ans;
  }
};

int
main()
{
  // Start measuring time
  auto begin = std::chrono::high_resolution_clock::now();

  Solution solve;

  int answer = solve.divide(10, 3);

  // Stop measuring time and calculate the elapsed time
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

  std::cout << answer << std::endl;
  std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds."
            << std::endl;
  return 0;
}