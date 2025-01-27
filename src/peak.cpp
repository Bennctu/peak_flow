#include "peak.h"

namespace Solution {
bool isNumber(std::string const& s) {
    for (auto& it : s) {
        if (!std::isdigit(it)) return false;
    }

    return true;
}
bool parseArray(std::string const& file_name, std::vector<int>& nums) {
    std::fstream fs(file_name);
    if (!fs.is_open()) {
        std::cerr << "[Solution::parseArray]:" << file_name << " can't found"
                  << std::endl;
        return false;
    }

    std::string line;
    int kth_line = 1;
    while (std::getline(fs, line)) {
        if (!isNumber(line)) {
            std::cerr << "[Solution::parseArray]:" << kth_line
                      << "th line isn't a non-negative integer number in "
                      << file_name << std::endl;
            return false;
        }

        nums.push_back(std::stoi(line));
        kth_line++;
    }

    if (nums.empty()) {
        std::cerr << "[Solution::parseArray]:Please give a non-negative number "
                     "in text file"
                  << std::endl;
        return false;
    }

    return true;
}
void peak(std::vector<int> const& nums, int target,
          std::vector<std::vector<int>>& subarrays) {
    int nums_size = nums.size();
    std::vector<std::pair<int, int>> min_ids_list;

    auto min_iter = std::min_element(nums.begin(), nums.end());
    if (target <= *min_iter) {
        for (int i = 0; i < nums_size; i++) {
            min_ids_list.push_back({i, i});
        }
        indexsToArray(min_ids_list, nums, subarrays);
        return;
    }

    int prefix_sum = 0, right = 0, left = 0;
    int min_size = nums_size + 1;
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

    if (min_ids_list.empty())
        std::cout << "Not found subarray" << std::endl;
    else
        indexsToArray(min_ids_list, nums, subarrays);
}
void indexsToArray(std::vector<std::pair<int, int>> const& indexs,
                   std::vector<int> const& nums,
                   std::vector<std::vector<int>>& subarrays) {
    for (auto& ids : indexs) {
        std::vector<int> arr(ids.second - ids.first + 1);
        std::copy(nums.begin() + ids.first, nums.begin() + ids.second + 1,
                  arr.begin());
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
