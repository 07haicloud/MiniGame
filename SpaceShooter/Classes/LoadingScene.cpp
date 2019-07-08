
#include "LoadingScene.h"
#include "cocos\ui\CocosGUI.h"
#include "ResourceManager.h"
#include "MainMenuScene.h"
USING_NS_CC;

Scene* LoadingScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LoadingScene::create();
	scene->addChild(layer);
	return scene;
}

bool LoadingScene::init()
{
	if (!Layer::init()) {
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();
	//auto background = Sprite::create("res/Sprites/background2.png");
	auto background = ResourceManager::GetInstance()->GetSpriteById('0');
	background->setAnchorPoint(Vec2(0.5,0.5));
	//background->removeFromParent();
	background->setPosition(screenSize.width/2, screenSize.height / 2);
	addChild(background, -10);
	
	update(180);
	//scheduleUpdate();

	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(MainMenuScene::createScene());
	});

	auto seq = Sequence::create(DelayTime::create(3), gotoNext, nullptr);
	runAction(seq);
	return true;
}

void LoadingScene::update(float deltaTime)
{
	auto screenSize = Director::getInstance()->getVisibleSize();
	//Loading bar
	
	auto loadingBarGB = Sprite::create("res/Sprites/loading.png");
	loadingBarGB->setPosition(Vec2(screenSize.width / 2, screenSize.height/2));
	loadingBarGB->setScale((0.666*screenSize.width)/loadingBarGB->getContentSize().width);
	loadingBarGB->setAnchorPoint(Vec2(0.5, 0.5));
	addChild(loadingBarGB);

//	ResourceManager::GetSpriteById('5');
	static auto loadingbar = ui::LoadingBar::create("res/Sprites/progress.png");
	loadingbar->setPercent(0);
	loadingbar->setDirection(ui::LoadingBar::Direction::LEFT);
	loadingbar->setPosition(loadingBarGB->getPosition());
	loadingbar->setAnchorPoint(Vec2(0.5, 0.5));
	loadingbar->setScale((0.666*screenSize.width) / loadingbar->getContentSize().width);
	addChild(loadingbar);
	//update Loading Bar
	auto updateLoadingBar = CallFunc::create([]() {
		if (loadingbar->getPercent() < 100)
		{
			loadingbar->setPercent(loadingbar->getPercent() + 1);
		}
	});
	auto sequenceRunUpdateLoadingBar =
		Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.01*180/100));
	auto repeat = Repeat::create(sequenceRunUpdateLoadingBar, deltaTime);
	loadingbar->runAction(repeat);
}



