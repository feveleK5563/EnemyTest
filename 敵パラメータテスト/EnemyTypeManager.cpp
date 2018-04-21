#include "EnemyTypeManager.h"

//�R���X�g���N�^
EnemyTypeManager::EnemyTypeManager() {}

//�f�X�g���N�^
EnemyTypeManager::~EnemyTypeManager()
{
	for (auto it : eType)
		delete it;
}

//-----------------------------------------------------------------------------
//�t�@�C����ǂݍ���œG�̃f�[�^�����
//�����F�ǂݍ��ރt�@�C���ւ̃p�X(string)
void EnemyTypeManager::CreateEnemyData(string filePath)
{
	//�{���Ȃ炱���Ńt�@�C����ǂݍ���(���͉�)
	//1���̓���p�^�[�������G�f�[�^���쐬

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
//�w��ԍ��̓G�f�[�^�̃A�h���X�l��Ԃ�
//���� �����Ŏ擾�����f�[�^�����Ă͂����Ȃ�(����)
EnemyType* EnemyTypeManager::GetEnemyTypeData(int enemyNum)
{
	if (enemyNum < (int)eType.size())
	{
		return eType[enemyNum];
	}
	return nullptr;
}