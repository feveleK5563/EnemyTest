#include "Enemy.h"

//コンストラクタ
Enemy::Enemy() {}

//デストラクタ
Enemy::~Enemy()
{
	delete eController;
	delete imgManager;
}

//-----------------------------------------------------------------------------
//敵情報を設定
void Enemy::SetEnemyType(EnemyType* cpyet, ML::Vec2 setPos)
{
	eController = new EnemyController(cpyet->emSet);
	life = cpyet->maxLife;
	pos = setPos;
	moveVec = { 0, 0 };
	imgManager = new ImageManager(cpyet->imageName, cpyet->emSet->animChip);
}

//-----------------------------------------------------------------------------
//更新
void Enemy::Update()
{
	moveVec = { 0, 0 };

	eController->Move(moveVec);
	imgManager->Animation();

	//この処理はコリジョンで行う
	pos += moveVec;
}

//-----------------------------------------------------------------------------
//描画
void Enemy::Render()
{
	imgManager->ImageRender(pos);
}