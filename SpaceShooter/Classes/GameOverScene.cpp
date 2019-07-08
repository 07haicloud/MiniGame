
#include "GameOverScene.h"
#include "cocos\ui\CocosGUI.h"
#include "GamePlayScene.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
	return GameOverScene::create();;
}

bool GameOverScene::init()
{
	//ResourceManager::GetInstance()->GetButtonById('0');

	if (!Scene::init()) {
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();

	auto button = ResourceManager::GetInstance()->GetButtonById('1');

	button->addClickEventListener([&](Ref* event) {
		// Replace scene
		Director::getInstance()->replaceScene(GamePlayScene::createScene());
	});
	button->setAnchorPoint(Vec2(0.5, 0.5));
	button->setPosition(Vec2(screenSize.width / 2, screenSize.height / 2));
	addChild(button,10);


	auto background = ResourceManager::GetInstance()->GetSpriteById('0');
	background->setAnchorPoint(Vec2(0.5, 0.5));
	background->setPosition(screenSize/2);
	background->removeFromParent();
	addChild(background,-10);

	return true;
}





