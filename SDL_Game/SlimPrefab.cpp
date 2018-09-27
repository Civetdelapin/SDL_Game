#include "SlimPrefab.h"



SlimPrefab::SlimPrefab(std::string img_path, OwnMathFuncs::Vector2 sprite_size) : Enemy(img_path, sprite_size)
{

	getComponent<VelocityBody>()->setDrag({ 13, 13 });
	getComponent<EnemyBasicBehavior>()->setMaxHP(50);


	//Creation of child
	GameObject* game_object_child = new GameObject();

	BoxCollider* boxColliderHitBox = new BoxCollider(game_object_child);
	boxColliderHitBox->offset = { 0, 10 };
	boxColliderHitBox->size = { 12, 10 };
	boxColliderHitBox->setCollisionLayer(5);

	game_object_child->tag = "Enemy";
	addGameObject(game_object_child);

	
	Animator* animator = new Animator(this);
	
	// Creation of Animations
	Animation animIdle;
	animIdle.nb_sprites = 10;
	animIdle.speed = 0.1f;
	animIdle.y_index = 0;

	animator->addAnimation(std::pair <std::string, Animation>("Idle", animIdle));

	Animation animWalking;
	animWalking.nb_sprites = 10;
	animWalking.speed = 0.1f;
	animWalking.y_index = 2;

	animator->addAnimation(std::pair <std::string, Animation>("Walking", animWalking));
	animator->play("Idle");
	
}


SlimPrefab::~SlimPrefab()
{
}
