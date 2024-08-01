#include "peak.h"

namespace Solution {
void peak(std::vector<int> const& nums, int target) {
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

    printResult(nums, min_ids_list);
}
void printResult(std::vector<int> const& nums,
                     std::vector<std::pair<int, int>> const& subarray_idx) {
	for (auto& ids : subarray_idx) {
		std::vector<int> elements;
		for (int i = ids.first; i <= ids.second; i++) {
			std::cout << nums[i] << " ";
		}
		std::cout << std::endl;
	}
}
}  // namespace Solution
