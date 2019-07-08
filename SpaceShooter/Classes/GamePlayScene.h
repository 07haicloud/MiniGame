
#ifndef __GAMEPLAY_SCENE_H__
#define __GAMEPLAY_SCENE_H__
#include "cocos2d.h"
#include "Rock.h"
#include "SpaceShooter.h"
#include "ResourceManager.h"
#include <cstdlib>
#include <ctime>
USING_NS_CC;
using namespace std;
class GamePlayScene : public cocos2d::Scene
{
public:
	vector <Rock*> m_rocks;
	SpaceShooter *m_spaceship;
    static cocos2d::Scene* createScene();

    virtual bool init();
	void update(float deltaTime);
	void GenerateRock();
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	bool onTouchEnded(Touch *touch, Event *unused_event);

    CREATE_FUNC(GamePlayScene);
};

#endif // __MAINMENU_SCENE_H__
