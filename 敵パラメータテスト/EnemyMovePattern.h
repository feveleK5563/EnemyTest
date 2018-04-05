#pragma once
#include "EnemyMove.h"

//敵動作のパターンを作成するよ！
class EnemyMovePattern
{
public:
	int timeCnt;
	int movePatternNum;		//行う動作の数
	int nowMoveOrder;		//現在の動作順

	struct MoveType		//動作の種類、時間を内包したやつ
	{
		int moveTypeNum;	//動作の種類(番号)
		int moveTimeMax;	//動作終了までの時間
	};
	vector<MoveType> mt;

	EnemyMove* em;			//動作をこいつで行う


	//コンストラクタ
	EnemyMovePattern();

	//デストラクタ
	~EnemyMovePattern();

	//動作パターンを設定する(今回は面倒なので3種類まで適当に設定できるよ！)
	void SetMovePattern(int moveA, int moveB, int moveC,	//動作番号
						int timeA, int timeB, int timeC);	//動作の継続時間

	//動作を行う
	void Move(/*int& timeCnt,*/ ML::Vec2& pos);

	//次の動作に移行させる
	void MoveChange(int mTypeNum);
};