#include <chrono>
#include <iostream>

class Solution
{
  public:
    bool isUgly(int n)
    {
        if (n == 0)
            return false;
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
                continue;
            }
            if (n % 3 == 0)
            {
                n = n / 3;
                continue;
            }
            if (n % 5 == 0)
            {
                n = n / 5;
                continue;
            }
            return false;
        }
        return true;
    }
};

int main()
{
    int n = 15;
    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();
    Solution solve;

    bool isUgly = solve.isUgly(n);

    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout <<"Is " << n << " ugly number? " << isUgly << std::endl;

    std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds." << std::endl;
    return 0;
}