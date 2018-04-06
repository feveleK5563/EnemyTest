#include "MyGameMain.h"
#include "EnemyMoveManager.h"

//�Q�[�����
struct EnemyData
{
	ML::Vec2 pos;			//���W
	EnemyMoveManager emm;	//����̊Ǘ�

	EnemyData():
		pos({0, 0}),
		emm(){}
} ed;

DI::VGamePad gp;

//-----------------------------------------------------------------------------
//����������
//�@�\�T�v�F�v���O�����N�����ɂP����s�����i�f�ނȂǂ̏������s���j
//-----------------------------------------------------------------------------
void  MyGameMain_Initalize( )
{
	DG::Image_Create("Enemy", "./data/image/Slime.png");

	//�G�̏��������Őݒ�(���ۂ͂���Ȃ��Ƃ��Ȃ�)
	ed.pos = { 0, 50 };

	{//����p�^�[��1 �ҋ@
		int moveNum[1] = { 0 };
		int durationTime[1] = { 60 };
		int totalMoveNum = 1;
		ed.emm.CreateMotionPattern(moveNum, durationTime, totalMoveNum);
	}
	{//����p�^�[��2 �E30�t���[������30�t���[������60�t���[��
		int moveNum[3] = { 1, 2, 3 };
		int durationTime[3] = { 30, 30, 60 };
		int totalMoveNum = 3;
		ed.emm.CreateMotionPattern(moveNum, durationTime, totalMoveNum);
	}
}
//-----------------------------------------------------------------------------
//�������
//�@�\�T�v�F�v���O�����I�����ɂP����s�����i�f�ނȂǂ̉�����s���j
//-----------------------------------------------------------------------------
void  MyGameMain_Finalize( )
{
	DG::Image_Erase("Enemy");
}
//-----------------------------------------------------------------------------
//�X�V����
//�@�\�T�v�F�Q�[���̂P�t���[���ɓ����鏈��
//-----------------------------------------------------------------------------
void  MyGameMain_UpDate( )
{
	gp = DI::GPad_GetState("P1");
	
	//�G�̓�����X�V
	ed.emm.Move(ed.pos, gp);
}
//-----------------------------------------------------------------------------
//�`�揈��
//�@�\�T�v�F�Q�[���̂P�t���[���ɓ�����\������ �Q�c
//-----------------------------------------------------------------------------
void  MyGameMain_Render2D( )
{
	{	//�摜�\��
		ML::Box2D draw(-16, -16, 32, 32);
		ML::Box2D src(0, 32, 32, 32);
		draw.Offset(ed.pos);
		DG::Image_Draw("Enemy", draw, src);
	}
}