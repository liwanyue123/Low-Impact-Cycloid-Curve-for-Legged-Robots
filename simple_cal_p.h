
#ifndef SIMPLE_CAL_P_H
#define SIMPLE_CAL_P_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "../common/cppTypes.h"

template <typename T>
Vec3<T> simple_cal_p(T initialPosition, T distance, T t, T t_whole, bool
	isForward, bool isHaftPeriod)
{
	T P_des;
	T Pd_des;
	T a_des;
	//T P_des_tmp;
	//T b_P_des_tmp;

	//t_whole = 1.0;
	t = t * t_whole;
	if (isHaftPeriod) {
		t_whole = t_whole * 0.5;
	}
	P_des = distance * t / t_whole - (distance / (2 * PI))*sin(2 * PI*t / t_whole);
	Pd_des = distance / t_whole * (1 - cos(2 * PI*t / t_whole));
	a_des = 2 * PI*distance *sin(2 * PI*t / t_whole) / (t_whole*t_whole);


	if (isForward) {
		P_des += initialPosition;
	}
	else {
		P_des = initialPosition - P_des;
		Pd_des = -Pd_des;
		a_des = -a_des;
	}

	Vec3<T> result;
	result << P_des, Pd_des, a_des;
	return result;
}

#endif
