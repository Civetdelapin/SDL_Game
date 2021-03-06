#include "OwnMathFuncs.h"
#include <iostream>

void OwnMathFuncs::OwnMathFuncs::normalize(Vector2 & vec)
{
	double magnitude = OwnMathFuncs::magnitude(vec);

	if (magnitude != 0) {
		vec.x /= magnitude;
		vec.y /= magnitude;
	}

}

float OwnMathFuncs::OwnMathFuncs::magnitude(Vector2 &vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}

OwnMathFuncs::Vector2 OwnMathFuncs::OwnMathFuncs::getNormalize(Vector2 & vec)
{
	
	double magnitude = OwnMathFuncs::magnitude(vec);

	float x = 0;
	float y = 0;

	if (magnitude != 0) {
		x = vec.x /= magnitude;
		y = vec.y /= magnitude;
	}

	return Vector2(x,y);
}

float OwnMathFuncs::OwnMathFuncs::distanceBetweenVect(Vector2 vec, Vector2 vec2)
{
	return sqrt(pow(vec.x - vec2.x, 2) + pow(vec.y - vec2.y,2));
}

OwnMathFuncs::Vector2 OwnMathFuncs::OwnMathFuncs::Lerp(Vector2 start, Vector2 end, float perc)
{
	return (start + (end - start) * perc);
}

float OwnMathFuncs::OwnMathFuncs::Lerp(float start, float end, float perc)
{
	return 0.0f;
}

OwnMathFuncs::Vector2 OwnMathFuncs::OwnMathFuncs::getRandomPointInCircle(float radius)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(0.0, 1.0);

	float r = radius * std::sqrt(dis(gen));
	float theta = dis(gen) * 2 * M_PI;

	return { r * std::cos(theta) , r * std::sin(theta) };
}

OwnMathFuncs::Vector2 OwnMathFuncs::OwnMathFuncs::getRandomPointAroundCircle(float radius)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(0.0, 1.0);

	float theta = dis(gen) * 2 * M_PI;

	return { radius * std::cos(theta) , radius * std::sin(theta) };
}

bool OwnMathFuncs::OwnMathFuncs::AABB(SDL_Rect rectA, SDL_Rect rectB)
{
	if (
		rectA.x + rectA.w >= rectB.x &&
		rectB.x + rectB.w >= rectA.x &&
		rectA.y + rectA.h >= rectB.y &&
		rectB.y + rectB.h >= rectA.y)
	{
		return true;
	}

	return false;
}

std::string OwnMathFuncs::Vector2::toString()
{
	std::string str = "x : "+ std::to_string(x) + ", y : " + std::to_string(y);
	return str;
}
