#pragma once
#include "EnemyMovePattern.h"
#include "AnimationCharaChip.h"

//EnemyMovePatternをまとめたやつ
class EnemyMoveSet
{
public:
	vector<EnemyMovePattern*>		empattern;		//動作パターン
	vector<AnimationCharaChip*>		animChip;		//アニメーションパターン

	EnemyMoveSet();
	~EnemyMoveSet();

	//動作パターン集合の生成
	void CreateMotionPattern(	int* moveNum,			//動作番号を入れた配列のアドレス値
								int* skillId,			//動作中に取得可能なスキル番号
								int* durationTime,		//動作の継続時間を入れた配列のアドレス値
								int  totalMoveNum,		//動作の総数
								int  transitionNum,		//動作パターンの遷移条件の番号
								ML::Box2D&	src,		//アニメーション画像の最初の位置
								int			sheet,		//アニメーション枚数
								float		spd,		//アニメーション速度
								bool		ir);		//ループするか否か

	//現在の動作パターンを実行する
	void Move(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, ML::Vec2& moveVec);

	//動作パターンを指定番号に遷移させる
	void PatternTransition(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, int patternNum);
};