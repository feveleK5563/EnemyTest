#pragma once
#include "EnemyMove.h"

//敵動作の管理をするよ！！
class EnemyMoveManager
{
public:
	ML::Vec2* pos;		//敵の座標のアドレス値を格納

	int movePatternNum;		//行う動作の数
	int nowMoveOrder;		//現在の動作順
	int moveType[3];		//動作の種類(一応決め打ちで3種類まで)
	int moveTimeMax[3];		//動作終了までの時間(こちらも一応3種類まで)
	int timeCnt;			//時間を計測

	EnemyMove* em;			//動作をこいつで行う

	//コンストラクタ
	EnemyMoveManager(ML::Vec2* enemypos);

	//デストラクタ
	virtual ~EnemyMoveManager();

	//動作パターンを設定する(今回は面倒なので3種類まで適当に設定できるよ！)
	void SetMovePattern(int moveA, int moveB, int moveC,	//動作番号
						int timeA, int timeB, int timeC);	//動作の継続時間

	//動作を行う
	void Move();

	//引数の動作に移行させる
	//引数はテスト用なのでint型
	void MoveChange(int motionNum);
};