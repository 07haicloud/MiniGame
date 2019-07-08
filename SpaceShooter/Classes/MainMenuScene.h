
#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__
#include "ResourceManager.h"
#include "cocos2d.h"

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();


    CREATE_FUNC(MainMenuScene);
};

#endif // __MAINMENU_SCENE_H__
