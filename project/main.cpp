#include "base.h"
#include "food.h"
#include "refrigerator.h"
#include "file_manage.h"
#include "Time.h"

int main() {
	
	refrigerator r;

	thread clock{ flow_clock };
	thread refri_s_work{ second_work , ref(r) };
	thread alert_t{ alert_work , ref(r) };
	thread reminder_t{ reminder_work , ref(r) };

	vector<string> f;

	while (true)
	{
		input_to_vector(cin, f);
		r.push(get_food(f[0]));
		r.print();
	}

	alert_t.join();
	reminder_t.join();
	refri_s_work.join();
	clock.join();

	return 0;
}

