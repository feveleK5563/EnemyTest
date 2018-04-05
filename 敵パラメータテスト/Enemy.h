#pragma once
#include "MyPG.h"
#include "TimeCnt.h"
#include "Move.h"

//-----------------------------------------
//敵のクラス
//-----------------------------------------
class Enemy
{
public:
	Enemy();
	~Enemy();

	//基本処理
	void	Initialize();
	void	Finalize();
	void	UpDate();
	void	Render();


private:
	//その他のパラメータ
	const int	Frame = 60;	//60フレーム

	float	jumpPow = -9.0f;
	float	fallSpeed = 0.0f;
	float	oneFlag = false;

private:
	int	  life;				//ライフ
	int	  attackPoint;		//攻撃力
	ML::Vec2  pos;			//位置座標
	ML::Vec2  dir;			//方向(向き)
	int	  movePatternNum;	//動作パターンの数
	ML::Box2D hitBox;		//当たり判定(今は当たり判定の情報はいらない)
	int	  texNum;			//画像の番号
	int	  animSpeed;		//アニメーション速度
	int	  animNum;			//アニメーション数

	Move*	  move;			//移動させるクラス
	FrameMeasurement*  frameCnt;	//時間計測
};

