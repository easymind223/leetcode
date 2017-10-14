#pragma once
#include <vector> 
#include "test.h"
#include <windows.h>

#include <string>

using namespace std;

class LongestPalindromicSubstring : public Test
{
public:
	string solution(string s) {
		int begin = 0;
		int end = 0;
		for (int i = 0; i < s.size(); i++) {
			int oddLength = rangeByCenter(s, i, i);
			int evenLength = rangeByCenter(s, i, i + 1);
			int maxLength = max(oddLength, evenLength);
			if (maxLength > end - begin ) {
				begin = i - (maxLength - 1) / 2;
				end = i + maxLength / 2;
			}
		}
		return s.substr(begin, end - begin + 1);
	}

	void test() {
		cout << solution("adabba") << endl;
	}
private:
	int rangeByCenter(string s, int begin, int end) {
		while (begin >= 0 && end < s.size() && s.at(begin) == s.at(end)) {
			begin--;
			end++;
		}
		return end - begin - 1;
	}
};
