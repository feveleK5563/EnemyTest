#pragma once
#include "EnemyType.h"
#include "EnemyController.h"

//以下のincludeはGameObjectで代替する
#include "ImageManager.h"

class Enemy
{
public:
	//動作管理くん
	EnemyController* eController;

	//以下のメンバ変数はGameObjectやMoveクラスとかが持ってるものだと思う
	int				life;
	ML::Vec2		pos;
	ML::Vec2		moveVec;
	ImageManager*	imgManager;

	//コンストラクタ
	Enemy();
	//デストラクタ
	~Enemy();

	//敵情報を設定
	void SetEnemyType(EnemyType* cpyet, ML::Vec2 setPos);

	//更新
	void Update();

	//描画
	void Render();
};