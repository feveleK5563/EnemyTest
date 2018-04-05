#include "EnemyMovePattern.h"


//コンストラクタ
EnemyMovePattern::EnemyMovePattern() :
	movePatternNum(0),
	nowMoveOrder(0)
{
	em = new EMove_NoMotion();
}

//デストラクタ
EnemyMovePattern::~EnemyMovePattern() { delete em; }

//-----------------------------------------------------------------------------
//動作パターンを設定する(今回は面倒なので3種類まで適当に設定できるよ！)
void EnemyMovePattern::SetMovePattern(int moveA, int moveB, int moveC,	//動作番号
									  int timeA, int timeB, int timeC)	//動作の継続時間
{
	for (int i = 0; i < 3; ++i)
	{
		mt.emplace_back();
		mt.back() = { moveA, timeA };
	}
	moveType[0] = moveA;
	moveType[1] = moveB;
	moveType[2] = moveC;

	moveTimeMax[0] = timeA;
	moveTimeMax[1] = timeB;
	moveTimeMax[2] = timeC;

	movePatternNum = (int)mt.size();

	MoveChange();
}

//-----------------------------------------------------------------------------
//動作を行う
void EnemyMovePattern::Move(int& timeCnt, ML::Vec2& pos)
{
	em->Move(pos);

	++timeCnt;
	//timeCntがmoveTimeMax以上になったら、次の動作に移行する
	if (timeCnt >= moveTimeMax[nowMoveOrder])
	{
		timeCnt = 0;
		delete em;

		++nowMoveOrder;
		if (nowMoveOrder > movePatternNum)
			nowMoveOrder = 0;

		MoveChange();
	}
}

//-----------------------------------------------------------------------------
//次の動作に移行させる
void EnemyMovePattern::MoveChange()
{
	switch (moveType[nowMoveOrder])
	{
	case 0:		//何もしない
		em = new EMove_NoMotion();
		break;

	case 1:		//右方向に歩く
		em = new EMove_WalkRight();
		break;

	case 2:		//上に移動する
		em = new EMove_Up();
		break;

	case 3:		//下に移動する
		em = new EMove_Down();
		break;
	}
}