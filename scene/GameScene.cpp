#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	#pragma region プレイヤーの画像データ
	//後ろ
	playerBack_[0] = TextureManager::Load("Resources/Player/Back/Back0.png");
	playerBack_[1] = TextureManager::Load("Resources/Player/Back/Back1.png");

	//前
	playerFront_[0]=TextureManager::Load("Resources/Player/Front/Front0.png");
	playerFront_[1]=TextureManager::Load("Resources/Player/Front/Front1.png");
	
	//右
	playerRight_[0] = TextureManager::Load("Resources/Player/Right/Right0.png");
	playerRight_[1] = TextureManager::Load("Resources/Player/Right/Right1.png");
	
	//左
	playerLeft_[0] = TextureManager::Load("Resources/Player/Left/Left0.png ");
	playerLeft_[1] = TextureManager::Load("Resources/Player/Left/Left1.png ");

	#pragma endregion

}

void GameScene::Update() {}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
