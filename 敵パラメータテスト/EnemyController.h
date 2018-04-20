#pragma once
#include "EnemyMoveSet.h"

//敵の種類別に設定された動作アドレスを所有し、
//動作処理を呼び出すクラス
class EnemyController
{
public:
	EnemyMoveSet* ems;		//動作(delete禁止)

	int skillId;			//現在の敵から読み取れるスキル番号
	int nowMoveOrder;		//現在の動作順番
	int nowPatternOrder;	//現在の動作パターン順番
	int timeCnt;			//時間計測

	//コンストラクタ
	EnemyController(EnemyMoveSet* cpyems);
	//デストラクタ
	~EnemyController();

	//動作の実行
	void Move(ML::Vec2& moveVec);
};