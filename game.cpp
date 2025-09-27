#include "game.h"


Bullet::Bullet()
{
    this->shape.setRadius(5.f);
    this->shape.setFillColor(sf::Color{ 55, 55, 55 });
    this->currVelocity.x=0.f;
    this->currVelocity.y=0.f;
    this->maxSpeed=15.f;
}

Bullet::Bullet(float radius)
{
    this->shape.setRadius(radius);
    this->shape.setFillColor(sf::Color{ 55, 55, 55 });
    this->currVelocity.x=0.f;
    this->currVelocity.y=0.f;
    this->maxSpeed=15.f;
}

Bullet::~Bullet()
{

}
