#include "EnemyController.h"

//コンストラクタ
EnemyController::EnemyController(EnemyMoveSet* cpyems) :
	ems(cpyems),
	skillId(0),
	nowMoveOrder(0),
	nowPatternOrder(0),
	timeCnt(0) {}

//デストラクタ
EnemyController::~EnemyController(){}

//-----------------------------------------------------------------------------
//動作の実行
void EnemyController::Move(ML::Vec2& moveVec)
{
	ems->Move(nowMoveOrder, nowPatternOrder, timeCnt, moveVec);
}