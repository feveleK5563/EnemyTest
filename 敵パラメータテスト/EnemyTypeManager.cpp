#include "EnemyTypeManager.h"

//コンストラクタ
EnemyTypeManager::EnemyTypeManager() {}

//デストラクタ
EnemyTypeManager::~EnemyTypeManager()
{
	for (auto it : eType)
		delete it;
}

//-----------------------------------------------------------------------------
//ファイルを読み込んで敵のデータを作る
//引数：読み込むファイルへのパス(string)
void EnemyTypeManager::CreateEnemyData(string filePath)
{
	//本来ならここでファイルを読み込む(今は仮)
	//1個分の動作パターンを持つ敵データを作成

	eType.emplace_back(new EnemyType("Slime", 1, 1));

	int moveNum[3] = { 1, 2, 3 };
	int skillId[3] = { 0, 0, 0 };
	int durationTime[3] = { 30, 30, 60 };
	int totalMoveNum = 3;
	int transitionNum = 0;
	ML::Box2D src(0, 32, 32, 32);
	int sheet = 2;
	float animSpd = 30.f;
	bool ir = true;
	eType.back()->emSet->CreateMotionPattern(moveNum, skillId, durationTime, totalMoveNum, transitionNum,
											 src, sheet, animSpd, ir);
}

//-----------------------------------------------------------------------------
//指定番号の敵データのアドレス値を返す
//※注 ここで取得したデータをしてはいけない(戒め)
EnemyType* EnemyTypeManager::GetEnemyTypeData(int enemyNum)
{
	if (enemyNum < (int)eType.size())
	{
		return eType[enemyNum];
	}
	return nullptr;
}