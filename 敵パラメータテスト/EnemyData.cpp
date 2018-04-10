#include "EnemyData.h"

//コンストラクタ
EnemyData::EnemyData() :
	pos({ 0, 0 }),
	hitBase({0, 0, 0, 0}),
	atkBase({0, 0, 0, 0}),
	eyesightBase({0, 0, 0, 0}),
	angle(Left){}

//デストラクタ
EnemyData::~EnemyData(){}