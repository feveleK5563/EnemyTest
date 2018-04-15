#include "MyGameMain.h"
#include "EnemyData.h"
#include "AnimationManager.h"

//�Q�[�����
EnemyData			ed;
AnimationManager	am("Slime");

//-----------------------------------------------------------------------------
//����������
//�@�\�T�v�F�v���O�����N�����ɂP����s�����i�f�ނȂǂ̏������s���j
//-----------------------------------------------------------------------------
void  MyGameMain_Initalize()
{
	DG::Image_Create("Slime", "./data/image/Slime.png");

	//�G�̏��������Őݒ�(���ۂ͂���Ȃ��Ƃ��Ȃ�)
	ed.pos = { 0, 50 };

	{// �E30�t���[������30�t���[������60�t���[��
		int moveNum[3] = { 1, 2, 3 };
		int durationTime[3] = { 30, 30, 60 };
		int totalMoveNum = 3;
		ed.emm.CreateMotionPattern(moveNum, durationTime, totalMoveNum, 0, 120);
	}

	am.CreateCharaChip(0, 32, 32, 32, 2, 0.2f);
}
//-----------------------------------------------------------------------------
//�������
//�@�\�T�v�F�v���O�����I�����ɂP����s�����i�f�ނȂǂ̉�����s���j
//-----------------------------------------------------------------------------
void  MyGameMain_Finalize()
{
	DG::Image_Erase("Slime");
}
//-----------------------------------------------------------------------------
//�X�V����
//�@�\�T�v�F�Q�[���̂P�t���[���ɓ����鏈��
//-----------------------------------------------------------------------------
void  MyGameMain_UpDate()
{
	//�G�̓�����X�V
	ed.emm.Move(ed.pos);

	am.Animation();
}
//-----------------------------------------------------------------------------
//�`�揈��
//�@�\�T�v�F�Q�[���̂P�t���[���ɓ�����\������ �Q�c
//-----------------------------------------------------------------------------
void  MyGameMain_Render2D()
{
	//{	//�摜�\��
	//	ML::Box2D draw(-16, -16, 32, 32);
	//	ML::Box2D src(0, 32, 32, 32);
	//	draw.Offset(ed.pos);
	//	DG::Image_Draw("Enemy", draw, src);
	//}
	am.ImageRender(ed.pos);
}