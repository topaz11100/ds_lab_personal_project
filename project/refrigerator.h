#pragma once
#include "base.h"
#include "food.h"

class refrigerator {
public:
	refrigerator(int length) : length(length) {}
	void push(const food& f) {
		expiry_queue.push(f);
	}
	food pop() {
		food f = expiry_queue.top();
		expiry_queue.pop();
		return f;
	}
	int size() {
		return expiry_queue.size();
	}
	bool empty() {
		return expiry_queue.empty();
	}
private:
	priority_queue<food> expiry_queue;
	int length;
};
