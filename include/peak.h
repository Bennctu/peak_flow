#ifndef __PEAK_H__
#define __PEAK_H__

#include <fstream>
#include <iostream>
#include <vector>

namespace Solution {
bool parseArray(std::string const& file_name, std::vector<int>& nums);
void peak(std::vector<int> const& nums, int target,
          std::vector<std::vector<int>>& subarrays);
void indexsToArray(std::vector<std::pair<int, int>> const& indexs,
                   std::vector<int> const& nums,
                   std::vector<std::vector<int>>& subarrays);
void printResult(std::vector<std::vector<int>>& subarrays);
}  // namespace Solution

#endif  //__PEAK_H__
