#include "MyGameMain.h"
#include "EnemyMoveManager.h"

//ゲーム情報
struct EnemyData
{
	ML::Vec2 pos;			//座標
	EnemyMoveManager emm;	//動作の管理

	EnemyData():
		pos({0, 0}),
		emm(){}
} ed;

DI::VGamePad gp;

//-----------------------------------------------------------------------------
//初期化処理
//機能概要：プログラム起動時に１回実行される（素材などの準備を行う）
//-----------------------------------------------------------------------------
void  MyGameMain_Initalize( )
{
	DG::Image_Create("Enemy", "./data/image/Slime.png");

	//敵の情報をここで設定(実際はこんなことしない)
	ed.pos = { 0, 50 };

	{//動作パターン1 待機
		int moveNum[1] = { 0 };
		int durationTime[1] = { 60 };
		int totalMoveNum = 1;
		ed.emm.CreateMotionPattern(moveNum, durationTime, totalMoveNum);
	}
	{//動作パターン2 右30フレーム→上30フレーム→下60フレーム
		int moveNum[3] = { 1, 2, 3 };
		int durationTime[3] = { 30, 30, 60 };
		int totalMoveNum = 3;
		ed.emm.CreateMotionPattern(moveNum, durationTime, totalMoveNum);
	}
}
//-----------------------------------------------------------------------------
//解放処理
//機能概要：プログラム終了時に１回実行される（素材などの解放を行う）
//-----------------------------------------------------------------------------
void  MyGameMain_Finalize( )
{
	DG::Image_Erase("Enemy");
}
//-----------------------------------------------------------------------------
//更新処理
//機能概要：ゲームの１フレームに当たる処理
//-----------------------------------------------------------------------------
void  MyGameMain_UpDate( )
{
	gp = DI::GPad_GetState("P1");
	
	//敵の動作を更新
	ed.emm.Move(ed.pos, gp);
}
//-----------------------------------------------------------------------------
//描画処理
//機能概要：ゲームの１フレームに当たる表示処理 ２Ｄ
//-----------------------------------------------------------------------------
void  MyGameMain_Render2D( )
{
	{	//画像表示
		ML::Box2D draw(-16, -16, 32, 32);
		ML::Box2D src(0, 32, 32, 32);
		draw.Offset(ed.pos);
		DG::Image_Draw("Enemy", draw, src);
	}
}