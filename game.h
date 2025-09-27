#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <math.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>

using namespace sf;


/*
template <typename T>
std::string toString(const T& value)
{
	std::stringstream stream;
	stream << value;
	return stream.str();
}
*/

class Bullet
{
 public:
	CircleShape shape;
	Vector2f currVelocity;
	float maxSpeed;

	Bullet();
	Bullet(float radius);
        ~Bullet();
};

#endif 
