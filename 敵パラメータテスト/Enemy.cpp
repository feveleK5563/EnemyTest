#include "Enemy.h"

//----------------------------------
//�R���X�g���N�^
//----------------------------------
Enemy::Enemy() : life(0), attackPoint(0), movePatternNum(0), texNum(0),
animSpeed(0), animNum(0), pos(ML::Vec2(0, 0)), dir(ML::Vec2(0, 0)), hitBox(ML::Box2D(0, 0, 0, 0)),
move(nullptr), frameCnt(nullptr)
{

}

//----------------------------------
//�f�X�g���N�^
//----------------------------------
Enemy::~Enemy()
{
	delete move;
	delete frameCnt;
}


//---------------------------------------------------
//����������
//---------------------------------------------------
void	Enemy::Initialize()
{
	DG::Image_Create("Enemy", "./data/image/Slime.png");
	DG::Font_Create("FontA", "MS �S�V�b�N", 12, 12);

	move = new Move();
	frameCnt = new FrameMeasurement();

	pos = ML::Vec2(180, 200);
	dir = ML::Vec2(1, 0);
	move->SetParam(1.0f, 2.0f, jumpPow, fallSpeed); //�����E����E�W�����v�́E�����鑬�x
}

//---------------------------------------------------
//�������
//---------------------------------------------------
void	Enemy::Finalize()
{
	DG::Image_Erase("Enemy");
	DG::Font_Erase("FontA");
}

//---------------------------------------------------
//�X�V����
//---------------------------------------------------
void	Enemy::UpDate()
{
	frameCnt->MeasureTime();	//�J�E���g����
	
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
		//���Z�b�g
		pos = ML::Vec2(180, 200);
		dir = ML::Vec2(1, 0);
		fallSpeed = 0.0f;
		oneFlag = false;
		frameCnt->SetTime(0);	
	}
}

//---------------------------------------------------
//�`�揈��
//---------------------------------------------------
void	Enemy::Render()
{
	ML::Box2D draw(-16, -16, 32, 32);
	ML::Box2D src(0, 32, 32, 32);
	draw.Offset(pos);
	DG::Image_Draw("Enemy", draw, src);

	string text = "�ʒu:(" + to_string((int)pos.x) + "," + to_string((int)pos.y) + ")";
	ML::Box2D	textBox(0, 0, 480, 50);
	DG::Font_Draw("FontA", textBox, text,ML::Color(1,0,0.2f,1));
}