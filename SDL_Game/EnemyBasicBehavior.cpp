#include "EnemyBasicBehavior.h"
#include "Game.h"

EnemyBasicBehavior::EnemyBasicBehavior(GameObject* game_object) : Component(game_object)
{
	cur_hp = max_hp;
}


EnemyBasicBehavior::~EnemyBasicBehavior()
{
}

void EnemyBasicBehavior::update()
{
	if (cur_hp > max_hp) {
		cur_hp = max_hp;
	}
	else if (cur_hp <= 0) {
		Game::instance()->destroyGameObject(game_object->getRootParent());
	}

	time_stunned -= Time::deltaTime;
	if (time_stunned <= 0) {
		is_stunned = false;
	}
}

void EnemyBasicBehavior::addForce(OwnMathFuncs::Vector2 direction, float power)
{
	if (!is_stunned) {
		OwnMathFuncs::OwnMathFuncs::normalize(direction);

		VelocityBody* velocity_body = game_object->getComponent<VelocityBody>();
		if (velocity_body != nullptr) {
			velocity_body->velocity.x += direction.x * power * Time::deltaTime;
			velocity_body->velocity.y += direction.y * power * Time::deltaTime;

			//Manage the X scale according to the velocity
			if (velocity_body->velocity.x < 0 && game_object->getWorldScale().x > 0) {
				game_object->local_scale.x *= -1;
			}
			else if (velocity_body->velocity.x > 0 && game_object->getWorldScale().x < 0) {
				game_object->local_scale.x *= -1;
			}
		}

		velocity_body = NULL;
	}
}

void EnemyBasicBehavior::takeDamage(OwnMathFuncs::Vector2 direction, float power_knock_back, float damage, float time_stunned)
{
	VelocityBody* velocity_body = game_object->getComponent<VelocityBody>();
	if (velocity_body != nullptr) {
		velocity_body->velocity.x += direction.x * power_knock_back * Time::deltaTime;
		velocity_body->velocity.y += direction.y * power_knock_back * Time::deltaTime;
	}
	velocity_body = NULL;

	this->time_stunned = time_stunned;

	cur_hp -= damage;

	is_stunned = true;
}
