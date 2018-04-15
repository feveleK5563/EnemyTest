#pragma once
#include "EnemyMovePattern.h"
#include "EnemyMoveTransition.h"

class EnemyMoveManager
{
public:
	int timeCnt;				//時間計測
	int nowPatternOrder;		//現在の動作パターン番号
	
	vector<EnemyMovePattern*>		empattern;		//動作パターン
	vector<EnemyMoveTransition*>	emtransition;	//パターン遷移方法

	EnemyMoveManager();
	~EnemyMoveManager();

	//動作パターン集合の生成
	void CreateMotionPattern(int* moveNum,				//動作番号を入れた配列のアドレス値
							 int* durationTime,			//動作の継続時間を入れた配列のアドレス値
							 int  totalMoveNum,			//動作の総数
							 int  transitionNum,		//動作パターンの遷移方法の番号
							 int  transMaxTime = 0);	//時間遷移選択時の遷移時間

	//現在の動作パターンを実行する
	void Move(ML::Vec2& pos);

	//動作パターンを指定番号に遷移させる
	void PatternTransition(int patternNum);

	//動作パターンの遷移方法を設定する
	void SetTransition(int transitionNum, int transMaxTime);
};