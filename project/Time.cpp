#include "Time.h"

atomic<bool> second_condition = false;

vector<int> over_set;

mutex mtx;

void flow_clock()
{
	while (true)
	{
		this_thread::sleep_for(chrono::seconds(1));
		second_condition.store(true);
	}
}

void second_work(refrigerator& r)
{
	while (true)
	{
		if (second_condition.load())
		{
			{
				lock_guard<mutex> lock(mtx);
				r.minus_expiry();
				r.over_expiry(over_set);
			}
			
			
		}
	}
}

