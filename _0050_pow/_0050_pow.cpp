#include <iostream>
#include <chrono>
#include <vector>

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1; 

        for (int i = 0; i < n; i++)
            ans = ans*x; 

        return ans;
    }
};



int main()
{

    double x = 2.000;
    int n = 10;

    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();
    Solution solve;

    double ans = solve.myPow(x, n);



    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Answer is : " << ans << "\n\r";

    std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds.\n";
}