#include "EnemyController.h"

//�R���X�g���N�^
EnemyController::EnemyController(EnemyMoveSet* cpyems) :
	ems(cpyems),
	skillId(0),
	nowMoveOrder(0),
	nowPatternOrder(0),
	timeCnt(0) {}

//�f�X�g���N�^
EnemyController::~EnemyController(){}

//-----------------------------------------------------------------------------
//����̎��s
void EnemyController::Move(ML::Vec2& moveVec)
{
	ems->Move(nowMoveOrder, nowPatternOrder, timeCnt, moveVec);
}