// leetcode_practice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "twoSum.h"
#include "addTwoNumbers.h"
#include "longestSubstringWithoutRepeatingCharacters.h"
#include "longestPalindromicSubstring.h"
#include <vector> 
using std::vector;






int main()
{

	Test *test = new LongestPalindromicSubstring();
	test->test();
	delete test;
	
	system("pause");
    return 0;
}


