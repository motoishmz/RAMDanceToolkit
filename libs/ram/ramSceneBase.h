#pragma once
#include "ofMain.h"
#include "ofxAutoControlPanel.h"

class ramSceneBase
{
public:
	ramSceneBase() : bEnabled(false), key_enabled("Show") {}
	virtual ~ramSceneBase(){}
	
	inline ramActorManager& getActorManager() { return ramActorManager::instance(); }
	inline ramActor& getActor(string name) { return ramActorManager::instance().getActor(name); }
	inline ramRigidBody& getRigidBody(string name) { return ramActorManager::instance().getRigidBody(name); }
	
	virtual void refreshControlPanel(ofxAutoControlPanel& gui) {};
	
	virtual void setup() {}
	virtual void update() {}
	virtual void draw() {}
	virtual void drawActor(ramActor &actor) {}
	virtual void drawRigid(ramRigidBody &rigid) {}
	virtual void drawFloor() {}
	
	inline void enable(){ bEnabled = true; }
	inline void disable() { bEnabled = false; }
	inline void toggle() { bEnabled ^= true; }
	inline void setEnabled(bool b) { bEnabled = b; }
	
	inline string getSceneKey() { return key_enabled; }
	inline string getSceneName() { return scene_name.empty() ? "no name" : scene_name; }
	
	ramSceneBase* getPtr() { return this; }
	
protected:
	
	ofxAutoControlPanel *guiPtr;
	string scene_name, key_enabled;
	bool bEnabled;
	
	void setSceneName(string name)
	{
		scene_name = name;
		key_enabled = "Show: " + scene_name;
	}
};