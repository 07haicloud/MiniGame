
#include "MainMenuScene.h"
#include "cocos\ui\CocosGUI.h"
#include "GamePlayScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
	return MainMenuScene::create();;
}

bool MainMenuScene::init()
{
	//ResourceManager::GetInstance()->GetButtonById('0');

	if (!Scene::init()) {
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();

	auto button = ResourceManager::GetInstance()->GetButtonById('0');

	button->addClickEventListener([&](Ref* event) {
		// Replace scene
		Director::getInstance()->replaceScene(GamePlayScene::createScene());
	});
	button->setAnchorPoint(Vec2(0.5, 0.5));
	button->setPosition(Vec2(screenSize.width / 2, screenSize.height / 3));
	button->setScale(0.6);
	addChild(button,10);


	auto background = ResourceManager::GetInstance()->GetSpriteById('0');
	background->setAnchorPoint(Vec2(0.5, 0.5));
	background->setPosition(screenSize/2);
	background->removeFromParent();
	addChild(background,-10);

	auto logo = ResourceManager::GetInstance()->GetSpriteById('1');
	logo->setAnchorPoint(Vec2(0.5, 0.5));
	logo->setPosition(Vec2(screenSize.width/2, screenSize.height/2 + 70));
	//logo->setScale((screenSize.width*0.666) / logo->getContentSize().width);
	addChild(logo, 5);

	return true;
}





