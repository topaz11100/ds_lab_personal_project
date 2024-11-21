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
	cerr << "\n\n������� ����!!!\n����� ����\n";
	cerr << r.pop_alert_set() << "\n";
	cerr << "�� ���� ó�� �Ϸ�" << endl;
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
	cerr << "\n\n������� �ӹ�\n���� ����\n";
	cerr << r.pop_remin_set() << "\n";
	cerr << "�����Ǹ� �����Ͽ� ���� ������ ��������\n";
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

