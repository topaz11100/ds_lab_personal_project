#include "Time.h"

atomic<bool> second_condition = false;

atomic<bool> alert = false;

atomic<bool> reminder = false;

vector<int> over_set;

mutex refri_mtx;
mutex over_set_mtx;

const int reminder_time = 5;

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
				lock_guard<mutex> lock1(refri_mtx);
				lock_guard<mutex> lock2(over_set_mtx);
				r.minus_expiry();

				if (r.get_length() != 0 && r[0].get_expiry() < reminder_time)
				{
					reminder.store(true);
				}

				r.over_expiry(over_set);
				if (over_set.size() > 0)
				{
					alert.store(true);
				}
			}
			
			second_condition.store(false);
		}
	}
}

void print_over_expiry_alert(refrigerator& r, int temp)
{
	cerr << "유통기한 지남!!!\n폐기한 음식\n";
	for (int i = 0; i < temp; i += 1)
	{
		cerr << r.pop(0) << "\n";
	}
	cerr << "위 음식 처리 완료" << endl;
}

void alert_work(refrigerator& r)
{
	while (true)
	{
		if (alert.load())
		{
			int temp;
			{
				lock_guard<mutex> lock(over_set_mtx);
				temp = over_set.size();
			}
			{
				lock_guard<mutex> lock(refri_mtx);
				print_over_expiry_alert(r, temp);
			}
		}
		alert.store(false);
	}
}

//한번만 알리고 끝내게 고치기

void print_expiry_reminder(refrigerator& r)
{
	cerr << "유통기한 임박\n음식 정보\n";
	cerr << r[0] << "\n";
	cerr << "레시피를 참조하여 좋은 음식을 만들어보세요\n";
}

void reminder_work(refrigerator& r)
{
	while (true)
	{
		if (reminder.load())
		{
			{
				lock_guard<mutex> lock(refri_mtx);
				print_expiry_reminder(r);
			}
		}
		reminder.store(false);
	}
}

