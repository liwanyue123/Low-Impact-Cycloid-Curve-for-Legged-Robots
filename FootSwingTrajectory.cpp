/*!
 * @file FootSwingTrajectory.cpp
 * @brief Utility to generate foot swing trajectories.
 *
 * Currently uses Bezier curves like Cheetah 3 does
 */


#include "FootSwingTrajectory.h"

 /*!
  * Compute foot swing trajectory with a bezier curve
  * @param phase : How far along we are in the swing (0 to 1)
  phase��һ����һ����ʱ���0��1��0���ǻ�û�ߣ�1���ǵ����յ�
  * @param swingTime : How long the swing should take (seconds)
  swingTime�����·�̵���ʵʱ�䣬����Ϊ��λ
  */
template <typename T>
void FootSwingTrajectory<T>::computeSwingTrajectory(T phase, T swingTime) {

	_p = (phase * phase - 2 * phase + 1)*_p0 + (-2 * phase * phase + 2 * phase)*_pt + (phase * phase)*_pf;
	_v = ((2 * phase - 2)*_p0 + (-4 * phase + 2)*_pt + (2 * phase)*_pf) / swingTime;
	_a = (2 * _p0 - 4 * _pt + 2 * _pf) / swingTime / swingTime;

}

template class FootSwingTrajectory<double>;
template class FootSwingTrajectory<float>;