#ifndef __PEAK_H__
#define __PEAK_H__

#include <vector>
#include <iostream>

namespace Solution {
void peak(std::vector<int> const& nums, int target);
void printResult(std::vector<int> const& nums,
                     std::vector<std::pair<int, int>> const& subarray_idx);
}  // namespace Solution

#endif  //__PEAK_H__
