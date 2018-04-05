#include "Enemy.h"

//----------------------------------
//コンストラクタ
//----------------------------------
Enemy::Enemy() : life(0), attackPoint(0), movePatternNum(0), texNum(0),
animSpeed(0), animNum(0), pos(ML::Vec2(0, 0)), dir(ML::Vec2(0, 0)), hitBox(ML::Box2D(0, 0, 0, 0)),
move(nullptr), frameCnt(nullptr)
{

}

//----------------------------------
//デストラクタ
//----------------------------------
Enemy::~Enemy()
{
	delete move;
	delete frameCnt;
}


//---------------------------------------------------
//初期化処理
//---------------------------------------------------
void	Enemy::Initialize()
{
	DG::Image_Create("Enemy", "./data/image/Slime.png");
	DG::Font_Create("FontA", "MS ゴシック", 12, 12);

	move = new Move();
	frameCnt = new FrameMeasurement();

	pos = ML::Vec2(180, 200);
	dir = ML::Vec2(1, 0);
	move->SetParam(1.0f, 2.0f, jumpPow, fallSpeed); //歩く・走る・ジャンプ力・落ちる速度
}

//---------------------------------------------------
//解放処理
//---------------------------------------------------
void	Enemy::Finalize()
{
	DG::Image_Erase("Enemy");
	DG::Font_Erase("FontA");
}

//---------------------------------------------------
//更新処理
//---------------------------------------------------
void	Enemy::UpDate()
{
	frameCnt->MeasureTime();	//カウントする
	
	if(!frameCnt->CheckTimeElaped(Frame * 3))
	{ 
		dir = ML::Vec2(1, 0);
		move->Walk(pos, dir);
	}
	else if (frameCnt->CheckTimeReach(Frame * 5))
	{
		dir = ML::Vec2(-1, 0);
		move->Run(pos, dir);
	}
	else if (frameCnt->CheckTimeReach(Frame * 8))
	{
		if (!oneFlag)
		{ 
			fallSpeed = jumpPow;
			oneFlag = true;
		}
		move->SetFallSpeed(fallSpeed);
		fallSpeed += 0.2f;
		dir = ML::Vec2(0, 0);
		move->Jump(pos);
	}
	else if (!frameCnt->CheckTimeElaped(Frame * 9))
	{
		//リセット
		pos = ML::Vec2(180, 200);
		dir = ML::Vec2(1, 0);
		fallSpeed = 0.0f;
		oneFlag = false;
		frameCnt->SetTime(0);	
	}
}

//---------------------------------------------------
//描画処理
//---------------------------------------------------
void	Enemy::Render()
{
	ML::Box2D draw(-16, -16, 32, 32);
	ML::Box2D src(0, 32, 32, 32);
	draw.Offset(pos);
	DG::Image_Draw("Enemy", draw, src);

	string text = "位置:(" + to_string((int)pos.x) + "," + to_string((int)pos.y) + ")";
	ML::Box2D	textBox(0, 0, 480, 50);
	DG::Font_Draw("FontA", textBox, text,ML::Color(1,0,0.2f,1));
}