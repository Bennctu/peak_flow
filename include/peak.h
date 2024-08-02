#ifndef __PEAK_H__
#define __PEAK_H__

#include <fstream>
#include <iostream>
#include <vector>

namespace Solution {
/// @brief Check whether s is a integer
/// @param s input string
/// @return true: is a integer
bool isNumber(std::string const& s);

/// @brief Parse the content of file into array
/// @param [in] file_name the location of reading file which stores integers
/// @param [out] nums integer array
/// @return true: parsing success
bool parseArray(std::string const& file_name, std::vector<int>& nums);

/// @brief Find the shortest subarray with summation which is is equal or
/// greater than specific number
/// @param [in] nums given integers
/// @param [in] target the specific number
/// @param [out] subarrays shortest subarrays
void peak(std::vector<int> const& nums, int target,
          std::vector<std::vector<int>>& subarrays);

/// @brief Generate subarrays via given start index and end index
/// @param [in] indexs start and end indexs
/// @param [in] nums given integers
/// @param [out] subarrays shortest subarrays
void indexsToArray(std::vector<std::pair<int, int>> const& indexs,
                   std::vector<int> const& nums,
                   std::vector<std::vector<int>>& subarrays);

/// @brief Print the array on screen
/// @param subarrays subarray
void printResult(std::vector<std::vector<int>>& subarrays);
}  // namespace Solution

#endif  //__PEAK_H__
