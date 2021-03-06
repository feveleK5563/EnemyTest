#include "MyGameMain.h"
#include "ImageManager.h"
#include "EnemyTypeManager.h"
#include "Enemy.h"

//ゲーム情報
EnemyTypeManager etm;
Enemy enemy[2];

//-----------------------------------------------------------------------------
//初期化処理
//機能概要：プログラム起動時に１回実行される（素材などの準備を行う）
//-----------------------------------------------------------------------------
void  MyGameMain_Initalize()
{
	etm.CreateEnemyData("");
	enemy[0].SetEnemyType(etm.GetEnemyTypeData(0), ML::Vec2(0, 0));
	enemy[1].SetEnemyType(etm.GetEnemyTypeData(0), ML::Vec2(0, 32));
}
//-----------------------------------------------------------------------------
//解放処理
//機能概要：プログラム終了時に１回実行される（素材などの解放を行う）
//-----------------------------------------------------------------------------
void  MyGameMain_Finalize()
{

}
//-----------------------------------------------------------------------------
//更新処理
//機能概要：ゲームの１フレームに当たる処理
//-----------------------------------------------------------------------------
void  MyGameMain_UpDate()
{
	//敵の動作を更新
	enemy[0].Update();
	enemy[1].Update();
}
//-----------------------------------------------------------------------------
//描画処理
//機能概要：ゲームの１フレームに当たる表示処理 ２Ｄ
//-----------------------------------------------------------------------------
void  MyGameMain_Render2D()
{
	enemy[0].Render();
	enemy[1].Render();
}