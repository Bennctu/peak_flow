#include "peak.h"

namespace Solution {
bool parseArray(std::string const& file_name, std::vector<int>& nums) {
    std::fstream fs(file_name);
    if (!fs.is_open()) return false;

    int cur_num;
    while (fs >> cur_num) {
        nums.push_back(cur_num);
    }

    return true;
}
void peak(std::vector<int> const& nums, int target,
          std::vector<std::vector<int>>& subarrays) {
    int nums_size = nums.size();

    int prefix_sum = 0, right = 0, left = 0;
    int min_size = nums_size + 1;
    std::vector<std::pair<int, int>> min_ids_list = {{0, nums_size}};
    while (right < nums_size) {
        // step1: find the right bound
        while (prefix_sum < target && right < nums_size) {
            prefix_sum += nums[right++];
        }

        // step2: find the left bound
        while (prefix_sum >= target) {
            /* real right index = right - 1
               current length = ((right - 1) - left) + 1*/
            int cur_len = right - left;
            if (cur_len < min_size) {
                min_size = cur_len;
                min_ids_list = std::move(
                    std::vector<std::pair<int, int>>({{left, right - 1}}));
            } else if (cur_len == min_size) {
                min_ids_list.push_back({left, right - 1});
            }

            prefix_sum -= nums[left++];
        }
    }

    indexsToArray(min_ids_list, nums, subarrays);
}
void indexsToArray(std::vector<std::pair<int, int>> const& indexs,
                   std::vector<int> const& nums,
                   std::vector<std::vector<int>>& subarrays) {
    for (auto& ids : indexs) {
        std::vector<int> arr(ids.second - ids.first + 1);
        std::copy(nums.begin() + ids.first, nums.begin() + ids.second + 1, arr.begin());
        subarrays.push_back(arr);
    }
}
void printResult(std::vector<std::vector<int>>& subarrays) {
    for (auto& arr : subarrays) {
        for (auto& it : arr) {
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }
}
}  // namespace Solution
