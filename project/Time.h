#pragma once
#include "base.h"
#include "refrigerator.h"

void second_work(refrigerator& r)
{
	while (true)
	{
		this_thread::sleep_for(chrono::seconds(1));
		r.minus_expiry();
	}
}