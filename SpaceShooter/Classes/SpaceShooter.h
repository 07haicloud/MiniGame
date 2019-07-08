#pragma once
#include"cocos2d.h"
#include"MyObject.h"
#include"Rock.h"
#include"Bullet.h"
#include"GameOverScene.h"
USING_NS_CC;
using namespace cocos2d;
using namespace std;
class SpaceShooter :public MyObject
{
public:
	std::list<MyObject*> m_bullets;
	SpaceShooter(Scene * scene);
	~SpaceShooter();
	void Init();
	void Update(float deltaTime);
	void Shoot();
	void Collision(vector<Rock*>);
};

