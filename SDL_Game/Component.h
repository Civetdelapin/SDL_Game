#pragma once

#include "GameObject.h"

class Component
{
public:
	explicit Component(GameObject* game_object);
	~Component();

	virtual void update();
	virtual void render(float camera_pos_x, float camera_pos_y);
	virtual void clean();

protected:

	GameObject* game_object;

};

