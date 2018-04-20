#pragma once
#include "EnemyType.h"

class EnemyTypeManager
{
public:
	vector<EnemyType*> eType;

	//�R���X�g���N�^
	EnemyTypeManager();
	//�f�X�g���N�^
	~EnemyTypeManager();

	//�t�@�C����ǂݍ���œG�̃f�[�^�����
	//�����F�ǂݍ��ރt�@�C���ւ̃p�X(string)
	void CreateEnemyData(string filePath);

	//�w��ԍ��̓G�f�[�^�̃A�h���X�l��Ԃ�
	//���� �����Ŏ擾�����f�[�^��delete���Ă͂����Ȃ�(����)
	EnemyType* GetEnemyTypeData(int enemyNum);
};