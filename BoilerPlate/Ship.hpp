#pragma once
#ifndef SHIP_HPP_
#define SHIP_HPP_

//STL
#include <vector>

//Asteroids
#include "Vector2.hpp"
#include "Entity.hpp"
#include "Bullet.hpp"

namespace Asteroids
{
	class Ship : public Entity
	{
	public:
		//Functions
		Ship();
		void Update(float deltaTime, int width, int height);
		void Render();
		void ApplyImpulse(Engine::Vector2 impulse) override;
		void ApplyDrag();
		void MoveUp();
		void RotateRight(float deltaTime);
		void RotateLeft(float deltaTime);
		void ChangeShip();
		Asteroids::Bullet* Shoot();

	private:
		//Members
		std::vector<Engine::Vector2> m_points;
		float m_angle;
		float m_rotation;
		float m_currentSpeed;
		int m_currentShip;
	};
}

#endif // !SHIP_HPP_