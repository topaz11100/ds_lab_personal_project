#include "Time.h"

mutex cv_mtx;
condition_variable cv;

bool second_condition = false;
bool alert = false;
bool reminder = false;

bool off = false;

void flow_clock()
{
	while (!off)
	{
		this_thread::sleep_for(chrono::seconds(1));
		second_condition = true;
		cv.notify_all();
	}
}

void second_work(refrigerator& r)
{
	while (true)
	{
		unique_lock<std::mutex> lock(cv_mtx);
		cv.wait(lock, [] { return second_condition; });

		if (off) return;

		r.minus_expiry();

		alert = !r.is_alert_empty();
		reminder = !r.is_remin_empty();

		second_condition = false;
		cv.notify_all();
	}
}

void print_over_expiry_alert(refrigerator& r)
{
	cerr << "\n\n유통기한 지남!!!\n폐기한 음식\n";
	cerr << r.pop_alert_set() << "\n";
	cerr << "위 음식 처리 완료" << endl;
}

void alert_work(refrigerator& r)
{
	while (true)
	{
		unique_lock<std::mutex> lock(cv_mtx);
		cv.wait(lock, [] { return alert; });

		if (off) return;

		print_over_expiry_alert(r);
		
		alert = false;
	}
}

void print_expiry_reminder(refrigerator& r)
{
	cerr << "\n\n유통기한 임박\n음식 정보\n";
	cerr << r.pop_remin_set() << "\n";
	cerr << "레시피를 참조하여 좋은 음식을 만들어보세요\n";
}

void reminder_work(refrigerator& r)
{
	while (true)
	{
		unique_lock<std::mutex> lock(cv_mtx);
		cv.wait(lock, [] { return reminder; });

		if (off) return;

		print_expiry_reminder(r);

		reminder = false;
	}
}

