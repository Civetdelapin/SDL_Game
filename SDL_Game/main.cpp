#include "Game.h"
#include "Player.h"
#include "TextureManager.h"

int main(int argc, char* args[]) {

	Game *main_game = new Game("My game");

	//Add the player in the game
	Player *player = new Player(main_game->getRenderer());


	main_game->game_objects.push_back(player);

	while (main_game->getIsRunning()) {

		main_game->handleEvents();
		main_game->update();
		main_game->render();

	}

	main_game->clean();
	return 0;
}