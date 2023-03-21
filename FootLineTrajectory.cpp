
// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "FootLineTrajectory.h"

template <typename T>
void FootLineTrajectory<T>::footLine(T t_mod, T t_swing) //这里t_mod是0-1
{
	Vec3<T> Pdata_des_x;
	Vec3<T> Pdata_des_y;
	Vec3<T> Pdata_des_z;
	// x
	// &P_des_x, &P_des_z,&a_des_x
	Pdata_des_x = simple_cal_p(_p0(0), _pf(0) - _p0(0), t_mod, t_swing, true, false);

	// calculate curve for x orientation
	// y
	// &P_des_y, &P_des_z,&a_des_x
	Pdata_des_y = simple_cal_p(_p0(1), _pf(1) - _p0(1), t_mod, t_swing, true, false);

	// z
	if (t_mod < 0.5)
	{
		Pdata_des_z = simple_cal_p(_p0(2), _pt(2) - _p0(2), t_mod, t_swing, true, true);
	}
	else
	{

		Pdata_des_z = simple_cal_p(_pt(2), _pt(2) - _pf(2), (t_mod - (T)0.5), t_swing, false, true);
	}

	_p(0) = Pdata_des_x(0);
	_v(0) = Pdata_des_x(1);
	_a(0) = Pdata_des_x(2);

	_p(1) = Pdata_des_y(0);
	_v(1) = Pdata_des_y(1);
	_a(1) = Pdata_des_y(2);

	_p(2) = Pdata_des_z(0);
	_v(2) = Pdata_des_z(1);
	_a(2) = Pdata_des_z(2);
}

/*!
 * Compute foot swing trajectory with a bezier curve
 * @param t_mod : How far along we are in the swing (0 to 1)
 t_mod是一个归一化的时间从0到1，0就是还没走，1就是到达终点
 * @param swingTime : How long the swing should take (seconds)
 swingTime是这段路程的真实时间，以秒为单位
 */
template <typename T>
void FootLineTrajectory<T>::computeSwingTrajectory(T t_mod, T swingTime)
{
	footLine(t_mod, swingTime);
}

template class FootLineTrajectory<double>;
// template class FootLineTrajectory<float>;