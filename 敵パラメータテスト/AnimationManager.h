#pragma once
#include "CharaChip.h"

class AnimationManager
{
public:
	string				imageName;
	vector<CharaChip*>	charaChip;
	int					nowAnimNum;
	float				animCnt;

	//コンストラクタ
	AnimationManager(string imgName);

	//デストラクタ
	~AnimationManager();

	//----------------------------------------------
	//キャラチップの作成
	void CreateCharaChip(int startPosX, int startPosY, int chipWidth, int chipHeight, int sheet, float spd);

	//----------------------------------------------
	//アニメーションパターンの設定
	void SetAnimationPattern(int motionNum);

	//----------------------------------------------
	//アニメーション
	void Animation();

	//----------------------------------------------
	//描画
	void ImageRender(ML::Vec2 pos);
};