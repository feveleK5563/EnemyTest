#include "EnemyMoveManager.h"


//コンストラクタ
EnemyMoveManager::EnemyMoveManager() :
	movePatternNum(0),
	nowMoveOrder(0),
	timeCnt(0)
{
	for (int i = 0; i < 3; ++i)
	{
		moveType[i] = 0;
		moveTimeMax[i] = 0;
	}
	em = new EMove_NoMotion();
}

//デストラクタ
EnemyMoveManager::~EnemyMoveManager() { delete em; }

//-----------------------------------------------------------------------------
//動作パターンを設定する(今回は面倒なので3種類まで適当に設定できるよ！)
void EnemyMoveManager::SetMovePattern(int moveA, int moveB, int moveC,	//動作番号
									  int timeA, int timeB, int timeC)	//動作の継続時間
{
	moveType[0] = moveA;
	moveType[1] = moveB;
	moveType[2] = moveC;

	moveTimeMax[0] = timeA;
	moveTimeMax[1] = timeB;
	moveTimeMax[2] = timeC;

	movePatternNum = 3;

	MoveChange();
}

//-----------------------------------------------------------------------------
//動作を行う
void EnemyMoveManager::Move()
{
	em->Move();

	//timeCntがmoveTimeMax以上になったら、次の動作に移行する
	if (++timeCnt >= moveTimeMax[nowMoveOrder])
	{
		timeCnt = 0;
		delete em;
		nowMoveOrder = ++nowMoveOrder % movePatternNum;

		MoveChange();
	}
}

//-----------------------------------------------------------------------------
//次の動作に移行させる
void EnemyMoveManager::MoveChange()
{
	switch (moveType[nowMoveOrder])
	{
	case 0:		//何もしない
		em = new EMove_NoMotion();
		break;

	case 1:		//右方向に歩く
		em = new EMove_WalkRight();
		break;

	case 2:		//ジャンプする
		em = new EMove_Jump();
		break;
	}
}