#pragma once
#include "MyPG.h"

//�摜�̕������(�L�����`�b�v)��ێ�������
class CharaChip
{
public:
	vector<ML::Box2D*>	chip;
	int					chipSheetNum;
	float				animSpd;

	//�R���X�g���N�^
	CharaChip();

	//�f�X�g���N�^
	~CharaChip();

	//----------------------------------------------
	//�A�j���[�V�����p�`�b�v���쐬
	//�����F����̍��W(int, int), �`�b�v�̉���(int), �`�b�v�̏c��(int), �A�j���[�V��������(int)
	void CreateChip(int startPosX, int startPosY, int chipWidth, int chipHeight, int sheet, float spd);
};