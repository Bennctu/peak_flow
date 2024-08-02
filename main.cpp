#include "peak.h"
#include "tictoc.hpp"

int main(int argc, char const* argv[]) {
    // std::cout << "Standard: " << __cplusplus << std::endl;
    if (argc < 3) {
        std::cerr << "Please input arguments: specific number and the location "
                     "of test.txt, ex:"
                  << std::endl
                  << "./peak 80 ../test.txt" << std::endl;
        return EXIT_FAILURE;
    }

    // Read arguments
    int target = std::stoi(argv[1]);
    std::string file_name(argv[2]);

    using namespace Solution;

    // Read file contents
    std::vector<int> nums;
    if (!parseArray(file_name, nums)) return EXIT_FAILURE;

    // Get the shortest continuous subsequences with the summation which is
    // equal or greater than target.
    std::vector<std::vector<int>> result;
    TicToc timer;
    peak(nums, target, result);
    int duration_time = timer.toc();

    // Show result
    printResult(result);
    std::cout << "duration: " << duration_time << " ns" << std::endl;

    return 0;
}
