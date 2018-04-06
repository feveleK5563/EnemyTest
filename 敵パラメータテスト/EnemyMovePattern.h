#pragma once
#include "EnemyMove.h"

//敵動作のパターンを作成するよ！
class EnemyMovePattern
{
public:
	int nowMoveOrder;		//現在の動作順

	struct MoveType		//動作の種類、時間を内包したやつ
	{
		int moveTypeNum;	//動作の種類(番号)
		int moveTimeMax;	//動作終了までの時間

		MoveType(int mtype, int mtime) :
			moveTypeNum(mtype),
			moveTimeMax(mtime){}
	};
	vector<MoveType*> mt;

	EnemyMove* em;			//動作をこいつで行う


	//コンストラクタ
	EnemyMovePattern();

	//デストラクタ
	~EnemyMovePattern();

	//動作パターンを設定する
	void SetMovePattern(int* moveNum,		//動作番号を入れた配列のアドレス値
						int* durationTime,	//動作の継続時間を入れた配列のアドレス値
						int  totalMoveNum);	//動作の総数

	//動作を行う
	void Move(int& timeCnt, ML::Vec2& pos);

	//動作順をリセットする
	void MoveReset();

	//次の動作に移行させる
	void MoveChange(int mTypeNum);
};