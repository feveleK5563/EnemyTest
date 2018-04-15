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

	for (auto it : emtransition)
		delete it;
}

//-----------------------------------------------------------------------------
//動作パターン集合の生成
void EnemyMoveManager::CreateMotionPattern(int* moveNum,		//動作番号を入れた配列のアドレス値
										   int* durationTime,	//動作の継続時間を入れた配列のアドレス値
										   int  totalMoveNum,	//動作の総数
										   int	transitionNum,	//動作パターンの遷移方法の番号
										   int	transMaxTime)	//時間遷移選択時の遷移時間
{
	empattern.emplace_back(new EnemyMovePattern(moveNum, durationTime, totalMoveNum));
	SetTransition(transitionNum, transMaxTime);
}

//-----------------------------------------------------------------------------
//現在の動作パターンを実行する
void EnemyMoveManager::Move(ML::Vec2& pos)
{
	empattern[nowPatternOrder]->Move(timeCnt, pos);

	//パターンの遷移条件を満たしたら即パターン変更
	for (int i = 0; i < (int)emtransition.size(); ++i)
	{
		if (nowPatternOrder != i && 
			emtransition[i]->Transition())
		{
			PatternTransition(i);
			return;
		}
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

//-----------------------------------------------------------------------------
//動作パターンの遷移方法を設定する
void EnemyMoveManager::SetTransition(int transitionNum, int transMaxTime)
{
	switch (transitionNum)
	{
	case 0:	//遷移なし
		emtransition.emplace_back();
		emtransition.back() = new ETransition_Default();
		break;
	}
}