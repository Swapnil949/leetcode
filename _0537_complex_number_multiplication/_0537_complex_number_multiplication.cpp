#include <chrono>
#include <iostream>

using std::string;

class Solution
{
  public:
    string complexNumberMultiply(string num1, string num2)
    {
        // Formula for complex multiplication
        // (x + yi)(u + vi) = (xu - yv) + (xv + yu)i
        int x = stoi(num1.substr(0, num1.find_first_of('+')));
        int u = stoi(num2.substr(0, num2.find_first_of('+')));

        int y = stoi(num1.substr(num1.find_first_of('+') + 1, num1.size() - 1));
        int v = stoi(num2.substr(num2.find_first_of('+') + 1, num2.size() - 1));

        return (std::to_string(x*u - y*v) + '+' + std::to_string(x*v + y*u) + 'i');
    }
};

int main()
{
    string num1 = "1+1i";
    string num2 = "1+1i";

    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();

    Solution solve;
    string ans = solve.complexNumberMultiply(num1, num2);

    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    std::cout << ans << std::endl;
    
    std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds." << std::endl;
    return 0;
}