#include <iostream>
#include <vector>

std::vector<int> findLargestSumSubarray(const std::vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    std::pair<int, int> maxRange;

    for (int start = 0; start < n; ++start) {
        for (int end = start; end < n; ++end) {
            int currentSum = 0;
            for (int i = start; i <= end; ++i) {
                currentSum += nums[i];
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxRange = std::make_pair(start, end);
            }
        }
    }

    std::vector<int> result;
    for (int i = maxRange.first; i <= maxRange.second; ++i) {
        result.push_back(nums[i]);
    }
    return result;
}

void printSubarray(const std::vector<int>& subarray) {
    for (size_t i = 0; i < subarray.size(); ++i) {
        std::cout << subarray[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> sampleInputs;
    sampleInputs.push_back(std::vector<int>({10, 2, -5, 1, 9, 0, -4, 2, -2}));
    sampleInputs.push_back(std::vector<int>({-7, 1, 8, 2, -3, 1}));
    sampleInputs.push_back(std::vector<int>({9, 7, 2, 16, -22, 11}));
    sampleInputs.push_back(std::vector<int>({6, 1, 9, -33, 7, 2, 9, 1, -3, 8, -2, 9, 12, -4}));

    for (size_t i = 0; i < sampleInputs.size(); ++i) {
        std::vector<int> result = findLargestSumSubarray(sampleInputs[i]);
        std::cout << "Input: ";
        printSubarray(sampleInputs[i]);
        std::cout << "Largest Sum Subarray: ";
        printSubarray(result);
        std::cout << std::endl;
    }

    return 0;
}


