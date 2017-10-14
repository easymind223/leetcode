#pragma once
#include <vector> 
#include <map>
#include <iostream>
#include "test.h"
using std::vector;

/*	1
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class TwoSum : public Test{
public:
	vector<int> solution(vector<int>& nums, int target) {
		std::map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			int rest = target - nums.at(i);
			if (m.find(rest) != m.end() && m.at(rest) != i) {
				return{ m.at(rest), i };
			}
			else {
				m[nums.at(i)] = i;
			}
		}
		throw new std::string("no such pairs");
	}

	virtual void test() {
		vector<int> nums = { 3,3,2,4 };
		vector<int> indices = solution(nums, 6);
		for (int i = 0; i < indices.size(); i++) {
			std::cout << indices.at(i) << std::endl;
		}
	}
};
