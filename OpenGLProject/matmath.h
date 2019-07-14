#pragma once

#include "mat4.h"
#include <corecrt_math_defines.h>

double deg2Rad = 2 * M_PI / 360;

// Generate a matrix that will apply a translation to any given vertex
template <typename T = float>
mat4<T> translate(T x, T y, T z) {
	return mat4<T>(1, 0, 0, x,
				   0, 1, 0, y,
				   0, 0, 1, z,
				   0, 0, 0, 1);
}

// Generate a matrix that will apply a scale to any given vertex
// Note that the vertex should first be translated to the origin before this operation (else it will be centered somewhere else), and then translated back afterwards
template <typename T = float>
mat4<T> scale(T x, T y, T z) {
	return mat4<T>(x, 0, 0, 0,
				   0, y, 0, 0,
				   0, 0, z, 0,
				   0, 0, 0, 1);
}

// TODO: implement rotation (decisions still to be made)
template <typename T = float>
mat4<T> rotate(T xDegrees, T yDegrees, T zDegrees, bool deg = true) {
	return mat4<T>(cos(xDegrees * deg2Rad), 3);
}

template <typename T = float>
mat4<T> rotateAboutZAxis(T degrees) {
	double val = degrees * deg2Rad;
	return mat4<T>(cos(val), -sin(val), 0, 0,
				   sin(val), cos(val), 0, 0,
				   0, 0, 1, 0,
				   0, 0, 0, 1);
}

// TODO: implement projection (will need some thinking)
template <typename T = float>
mat4<T> projection() {

}