#include "Enemy.h"

//�R���X�g���N�^
Enemy::Enemy() {}

//�f�X�g���N�^
Enemy::~Enemy()
{
	delete eController;
	delete imgManager;
}

//-----------------------------------------------------------------------------
//�G����ݒ�
void Enemy::SetEnemyType(EnemyType* cpyet, ML::Vec2 setPos)
{
	eController = new EnemyController(cpyet->emSet);
	life = cpyet->maxLife;
	pos = setPos;
	moveVec = { 0, 0 };
	imgManager = new ImageManager(cpyet->imageName, cpyet->emSet->animChip);
}

//-----------------------------------------------------------------------------
//�X�V
void Enemy::Update()
{
	moveVec = { 0, 0 };

	eController->Move(moveVec);
	imgManager->Animation();

	//���̏����̓R���W�����ōs��
	pos += moveVec;
}

//-----------------------------------------------------------------------------
//�`��
void Enemy::Render()
{
	imgManager->ImageRender(pos);
}