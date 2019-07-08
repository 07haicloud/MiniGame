#pragma once
#include"cocos2d.h"
#include"MyObject.h"
#include"ResourceManager.h"
using namespace cocos2d;
using namespace std;
class Rock :public MyObject
{
public:
	Rock(Scene* scene) ;
	~Rock();
	void Init();
	void Update(float deltaTime);
};

