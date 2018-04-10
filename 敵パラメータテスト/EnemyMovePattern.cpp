#include "EnemyMovePattern.h"


//コンストラクタ
EnemyMovePattern::EnemyMovePattern(
	int* moveNum,			//動作番号を入れた配列のアドレス値
	int* durationTime,		//動作の継続時間を入れた配列のアドレス値
	int  totalMoveNum) :	//動作の総数
	nowMoveOrder(0)
{
	for (int i = 0; i < totalMoveNum; ++i)
	{
		mt.emplace_back(new MoveType(*(moveNum + i), *(durationTime + i)));
	}

	MoveChange(mt[0]->moveTypeNum);
}

//デストラクタ
EnemyMovePattern::~EnemyMovePattern()
{ 
	for (auto it : mt)
		delete it;

	delete em;
}

//-----------------------------------------------------------------------------
//動作を行う
void EnemyMovePattern::Move(int& timeCnt, ML::Vec2& pos)
{
	em->Move(pos);

	++timeCnt;
	//timeCntがmoveTimeMaxを超えたら、次の動作に移行する
	if (timeCnt >= mt[nowMoveOrder]->moveTimeMax)
	{
		timeCnt = 0;
		delete em;

		++nowMoveOrder;
		if (nowMoveOrder >= (int)mt.size())
			nowMoveOrder = 0;

		MoveChange(mt[nowMoveOrder]->moveTypeNum);
	}
}

//-----------------------------------------------------------------------------
//動作順をリセットする
void EnemyMovePattern::MoveReset()
{
	nowMoveOrder = 0;
	MoveChange(mt[nowMoveOrder]->moveTypeNum);
}

//-----------------------------------------------------------------------------
//次の動作に移行させる
void EnemyMovePattern::MoveChange(int mTypeNum)
{
	switch (mTypeNum)
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