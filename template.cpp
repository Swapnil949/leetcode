#include <iostream>
#include <chrono>

int main()
{

    
    

    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();


    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds." << std::endl;
    return 0;
}