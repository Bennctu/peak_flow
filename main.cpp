#include "peak.h"

int main(int argc, char const *argv[])
{
    std::cout << "Standard: " << __cplusplus << std::endl;
    using namespace Solution;
    std::vector<int> nums{3, 17, 42, 1, 26, 8, 0, 63};
    peak(nums, 80);
    return 0;
}
