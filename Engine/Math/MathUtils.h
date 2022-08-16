#pragma once

namespace math
{
	const float Pi = 3.14159265359f; //180
	const float TwoPi = 6.28318530718f; ///360
	const float halfPi = 1.57079632679f; //180

	constexpr float DegToRad(float degrees)
	{
		return degrees * (Pi / 180);
	}
	constexpr float RadToDeg(float radians)
	{
		return radians * (180 / Pi);
	}
	
	int sqr(int v);
	inline int half(int v) { return v / 2; }
}
