#pragma once
#include <vector>

class Renderer;

class RendererManager
{
public:
	RendererManager();
	~RendererManager();

	static const int MAX_LAYER = 12;
	static const int TOP_DOWN_LAYER = 5;
	static const int MIN_LAYER = 0;

	void addRenderer(Renderer* renderer);
	void removeRenderer(Renderer* renderer);

	void modifyLayer(Renderer* renderer, int new_layer);

	void render();



private:
	std::vector<std::vector<Renderer*>> renderers_to_render;

	void reorderRenderers(int index);
};

