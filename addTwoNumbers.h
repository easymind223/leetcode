#pragma once
#include "stdafx.h"
#include <vector> 
using std::vector;


/*	2
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class AddTwoNumbers : public Test {
public:

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *result = new ListNode(0);
		ListNode *p3 = result;
		int flag = 0;

		while (p1 != NULL || p2 != NULL) {
			int val = (p1 != NULL ? p1->val : 0) + (p2 != NULL ? p2->val : 0) + flag;
			flag = 0;
			if (val >= 10) {
				val -= 10;
				flag = 1;
			}
			ListNode *node = new ListNode(val);

			p3->next = node;
			p3 = p3->next;

			if (p1 != NULL) p1 = p1->next;
			if (p2 != NULL) p2 = p2->next;
		}
		if (flag == 1) {
			p3->next = new ListNode(1);
		}
		p3 = result->next;
		delete result;
		return p3;
	}

	ListNode* serialArray(vector<int> xs) {
		ListNode* head = new ListNode(0);
		ListNode* p = head;

		for (int i = 0; i < xs.size(); i++) {
			ListNode *node = new ListNode(xs.at(i));
			p->next = node;
			p = p->next;
		}
		p = head->next;
		delete head;
		return p;
	}

	virtual void test() {
		ListNode* l1 = serialArray({ 2,4,3 });
		ListNode* l2 = serialArray({ 5,6,4 });
		ListNode* result = addTwoNumbers(l1, l2);
		while (result != NULL) {
			std::cout << result->val << std::endl;
			result = result->next;
		}
	}
};



