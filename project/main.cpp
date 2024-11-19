#include "base.h"
#include "food.h"
#include "refrigerator.h"
#include "file_manage.h"
#include "Time.h"

int main() {
	
	refrigerator r;

	thread clock_t{ flow_clock };
	thread second_work_t{ second_work, ref(r) };
	thread reminder_work_t{ reminder_work, ref(r) };
	thread alert_work_t{ alert_work, ref(r) };

	vector<string> f;
	while (true)
	{
		input_to_vector(cin, f);
		r.push(get_food(f[0]));
		r.print();
	}

	clock_t.join();
	second_work_t.join();
	reminder_work_t.join();
	alert_work_t.join();

	return 0;
}

