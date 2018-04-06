#include "conio.h"
#include "EnemyMoveManager.h"

//コンストラクタ
EnemyMoveManager::EnemyMoveManager() :
	timeCnt(0),
	nowPatternOrder(0) {}

//デストラクタ
EnemyMoveManager::~EnemyMoveManager()
{
	for (auto it : empattern)
		delete it;
}

//-----------------------------------------------------------------------------
//動作パターン集合の生成
void EnemyMoveManager::CreateMotionPattern(int moveA, int moveB, int moveC,	//動作番号
										   int timeA, int timeB, int timeC) //動作の継続時間
{
	empattern.emplace_back(new EnemyMovePattern());
	empattern.back()->SetMovePattern(moveA, moveB, moveC, timeA, timeB, timeC);
}

//-----------------------------------------------------------------------------
//現在の動作パターンを行う
void EnemyMoveManager::Move(ML::Vec2& pos, const DI::VGamePad& gp)
{
	empattern[nowPatternOrder]->Move(timeCnt, pos);

	if (gp.B1.down)
	{
		PatternTransition(1);
	}
	else if (gp.B1.up)
	{
		PatternTransition(0);
	}
}

//-----------------------------------------------------------------------------
//動作パターンを指定番号に遷移させる
void EnemyMoveManager::PatternTransition(int patternNum)
{
	if (patternNum >= (int)empattern.size())
		return;

	empattern[nowPatternOrder]->MoveReset();
	nowPatternOrder = patternNum;
	timeCnt = 0;
}