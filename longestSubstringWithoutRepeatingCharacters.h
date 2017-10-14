#pragma once
#include <vector> 
#include <map>
#include <iostream>
#include "test.h"
using std::string;

/* 3
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class LongestSubstringWithoutRepeatingCharacters : public Test
{
public:
	int lengthOfLongestSubstring(string s) {
		int maxLength = 0;
		string t;
		for (int i = 0; i < s.size(); i++) {
			int pos = t.find(s[i]);
			if (pos != string::npos) {
				if (t.size() > maxLength) maxLength = t.size();
				t = t.substr(pos + 1);
			}
			t = t.append(&s.at(i), 1);
		}
		if (t.size() > maxLength) maxLength = t.size();
		return maxLength;
	}

	virtual void test() {
		std::cout << lengthOfLongestSubstring("cbabcde") << std::endl;
	}
};
