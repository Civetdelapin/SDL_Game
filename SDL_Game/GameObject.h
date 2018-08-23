#pragma once
#include "SDL.h"
#include <SDL_image.h>
#include "OwnMathFuncs.h"
#include <string>


#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


// Base class for all the objects of the game
class GameObject
{

public:
	
	OwnMathFuncs::Vector2 position = {0, 0};
	OwnMathFuncs::Vector2 img_size = { 30, 30 };

	explicit GameObject(SDL_Renderer* renderer);
	~GameObject();

	virtual void handleEvents();
	virtual void update();
	virtual void render();
	void clean();

	void setTexture(SDL_Texture* texture);

private:
	SDL_Texture * texture;

	SDL_Rect srcrect;
	SDL_Rect dstrect;

	SDL_Renderer* renderer;
};

#endif
