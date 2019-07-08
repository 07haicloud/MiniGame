
#ifndef __LOADING_SCENE_H__
#define __LOADDING_SCENE_H__

#include "cocos2d.h"

class LoadingScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void update(float deltaTime);

    CREATE_FUNC(LoadingScene);
};

#endif // __LOADDING_SCENE_H__
