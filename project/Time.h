#pragma once

#include "base.h"
#include "refrigerator.h"

extern mutex cv_mtx;
extern condition_variable cv;

extern bool second_condition;
extern bool alert;
extern bool reminder;

extern bool off;

void flow_clock();

void second_work(refrigerator& r);

void alert_work(refrigerator& r);

void reminder_work(refrigerator& r);