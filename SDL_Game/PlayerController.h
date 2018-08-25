#pragma once
#include "Component.h"

class PlayerController : public virtual Component
{
public:
	PlayerController(GameObject* game_object);
	~PlayerController();

	OwnMathFuncs::Vector2 velocity = { 0, 0 };
	double speed = 0.5;

	bool can_move = true;

	void update();
};

