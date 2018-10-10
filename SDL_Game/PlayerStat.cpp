#include "PlayerStat.h"
#include "Game.h"


PlayerStat::PlayerStat(GameObject* game_object) : Component(game_object)
{
}


PlayerStat::~PlayerStat()
{
}

float PlayerStat::getCurHP()
{
	return cur_hp;
}


void PlayerStat::update()
{	
	if (is_invicible) {

		time_passed -= Time::deltaTime;

		if (time_passed <= 0) {
			is_invicible = false;
		}
	}

}

void PlayerStat::setInvicible(float time)
{
	is_invicible = true;
	time_passed = time;
}

bool PlayerStat::addDamage(float dmg)
{
	if (!is_invicible) {
		Game::instance()->getCamera()->startShake(25, 20, 0.75f);

		cur_hp -= dmg;
		
		setInvicible(time_invicible);

		return true;
	}

	return false;
}

int PlayerStat::getScore()
{
	return score;
}

void PlayerStat::addScore(int value)
{
	score += value;
}
