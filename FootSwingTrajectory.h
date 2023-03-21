/*!
 * @file FootSwingTrajectory.h
 * @brief Utility to generate foot swing trajectories.
 *
 * Currently uses Bezier curves like Cheetah 3 does
 */

#ifndef CHEETAH_SOFTWARE_FOOTSWINGTRAJECTORY_H
#define CHEETAH_SOFTWARE_FOOTSWINGTRAJECTORY_H

#include "../common/cppTypes.h"
 //���㱴��������,����д�Ļ�����ڵģ���ʵ���Ǻܼ򵥵Ĺ�ʽ
 //��ֻ��Ϊ��ģ��mit������ṹ����������

template<typename T>
class FootSwingTrajectory {
public:
	//��ʼ����ȫ���ó�0
	FootSwingTrajectory() {
		_p0.setZero();//��ʼ��
		_pf.setZero();//�յ�
		_pt.setZero();//��ߵ�

		_p.setZero();
		_v.setZero();
		_a.setZero();

	}
	//������˹켣�����
	void setInitialPosition(Vec3<T> p0) {
		_p0 = p0;
	}

	//������˹켣���յ�
	void setFinalPosition(Vec3<T> pf) {
		_pf = pf;
	}
	//������˹켣����ߵ�
	void setHeight(Vec3<T> pt) {
		_pt = pt;
	}
	//����켣
	void computeSwingTrajectory(T phase, T swingTime);

	//������λ��
	Vec3<T> getPosition() {
		return _p;
	}

	//�������ٶ�
	Vec3<T> getVelocity() {
		return _v;
	}

	//�����˼��ٶ�
	Vec3<T> getAcceleration() {
		return _a;
	}

private:
	Vec3<T> _p0, _pf, _pt, _p, _v, _a;

};


#endif //CHEETAH_SOFTWARE_FOOTSWINGTRAJECTORY_H
