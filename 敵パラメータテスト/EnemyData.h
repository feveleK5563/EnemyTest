#pragma once
#include "EnemyMoveManager.h"

class EnemyData
{
public:
	ML::Vec2			pos;			//座標
	EnemyMoveManager	emm;			//動作の管理
	ML::Box2D			hitBase;		//被ダメージ当たり判定
	ML::Box2D			atkBase;		//与ダメージ当たり判定
	ML::Box2D			eyesightBase;	//視界用当たり判定

	enum Angle { Left, Right };			//向き遷移
	Angle angle;

	EnemyData();
	~EnemyData();
};