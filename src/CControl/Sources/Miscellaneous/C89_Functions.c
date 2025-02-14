/*
 * C89_Functions.c
 *
 *  Created on: 27 feb. 2023
 *      Author: Daniel Mårtensson
 */

#include "../../Headers/Functions.h"

float sqrtf(float x){
	return (float) sqrt(x);
}

float fabsf(float x){
	return (float) fabs(x);
}

float acosf(float x){
	return (float) acos(x);
}

float expf(float x){
	return (float) exp(x);
}

float powf(float base, float power){
	return (float) pow(base, power);
}

float logf(float x){
	return (float) log(x);
}

float sinf(float x){
	return (float) sin(x);
}
