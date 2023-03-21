/*!
 * @file FootSwingTrajectory.h
 * @brief Utility to generate foot swing trajectories.
 *
 * Currently uses Bezier curves like Cheetah 3 does
 */

#ifndef CHEETAH_SOFTWARE_FOOTSWINGTRAJECTORY_H
#define CHEETAH_SOFTWARE_FOOTSWINGTRAJECTORY_H

#include "../common/cppTypes.h"
 //计算贝塞尔曲线,别看它写的花里胡哨的，其实还是很简单的公式
 //我只是为了模仿mit的整体结构，才用了它

template<typename T>
class FootSwingTrajectory {
public:
	//初始化，全设置成0
	FootSwingTrajectory() {
		_p0.setZero();//初始点
		_pf.setZero();//终点
		_pt.setZero();//最高点

		_p.setZero();
		_v.setZero();
		_a.setZero();

	}
	//设置足端轨迹的起点
	void setInitialPosition(Vec3<T> p0) {
		_p0 = p0;
	}

	//设置足端轨迹的终点
	void setFinalPosition(Vec3<T> pf) {
		_pf = pf;
	}
	//设置足端轨迹的最高点
	void setHeight(Vec3<T> pt) {
		_pt = pt;
	}
	//计算轨迹
	void computeSwingTrajectory(T phase, T swingTime);

	//获得足端位置
	Vec3<T> getPosition() {
		return _p;
	}

	//获得足端速度
	Vec3<T> getVelocity() {
		return _v;
	}

	//获得足端加速度
	Vec3<T> getAcceleration() {
		return _a;
	}

private:
	Vec3<T> _p0, _pf, _pt, _p, _v, _a;

};


#endif //CHEETAH_SOFTWARE_FOOTSWINGTRAJECTORY_H
