#pragma once
#include "AnimationCharaChip.h"

class ImageManager
{
private:
	bool	isDelete;

public:
	string						imageName;
	vector<AnimationCharaChip*>	charaChip;
	int							nowAnimNum;
	float						animCnt;

	//コンストラクタ
	ImageManager(string imgName);
	ImageManager(string imgName, vector<AnimationCharaChip*> acc);

	//デストラクタ
	~ImageManager();

	//----------------------------------------------
	//キャラチップの作成
	void CreateCharaChip(const ML::Box2D& src, int sheet, float spd, bool isroop);

	//----------------------------------------------
	//アニメーションパターンの変更
	void ChangeAnimationPattern(int motionNum);

	//----------------------------------------------
	//アニメーション
	void Animation();

	//----------------------------------------------
	//描画
	void ImageRender(const ML::Vec2& pos);
};