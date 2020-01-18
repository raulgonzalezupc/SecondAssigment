#ifndef _MODULESCENE_H_
#define _MODULESCENE_H_


#include "Module.h"
#include "Globals.h"
#include "Components/Camera.h"
#include "GameObject.h"
#include <vector>

class ModuleScene : public Module
{
public:
	ModuleScene();
	virtual ~ModuleScene();
	bool Init();
public :
	GameObject* root;
	Camera* camScene;
	Camera* camGame;

	void LoadDefaultScene(const char * path);

	void DrawAllBoundingBoxes();

	GameObject* CreateGameObject(const char* name, const float3 & pos, const Quat & rot) const;

	GameObject * CreateGameObjectByName(const char * name) const;

private:
	GameObject* CreateGameObject(const char * name);
	GameObject * CreateGameObject(const std::string & name) const;
	std::vector<GameObject*> game_objects;

};

#endif