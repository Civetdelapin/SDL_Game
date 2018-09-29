#include "StateDying.h"
#include "Game.h"


StateDying::StateDying(GameObject * game_object, std::string next_state) : State(next_state)
{
	animator = game_object->getComponent<Animator>();

	sprite_renderer = game_object->getComponent<SpriteRenderer>();
}


StateDying::~StateDying()
{
}

void StateDying::start(StateMachine * state_machine)
{
	time_passed = time_animation;

	animator->play("Dying");
}

void StateDying::operation(StateMachine * state_machine)
{
	if (is_alpha_phase) {
		float alpha_value = (time_passed / time_alpha_0) * SDL_ALPHA_OPAQUE;
		state_machine->getGameObject()->getComponent<SpriteRenderer>()->setAlpha(alpha_value);
	}

	time_passed -= Time::deltaTime;
	if (time_passed <= 0) {
		if (is_alpha_phase) {

			//Destroy game_object
			Game::instance()->destroyGameObject(state_machine->getGameObject()->getRootParent());
		}
		else {
			is_alpha_phase = true;

			time_passed = time_alpha_0;
		}
	}
}

void StateDying::exit(StateMachine * state_machine)
{
}