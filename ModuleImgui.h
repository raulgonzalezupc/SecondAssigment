#ifndef _MODULEIMGUI_H_
#define _MODULEIMGUI_H_
#include "Module.h"
#include "Globals.h"
#include "Application.h"
#include "SDL.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"
#include <vector>
using namespace std;


class ModuleImgui : public Module
{
public:
	ModuleImgui();
	~ModuleImgui();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	void ShowMainMenu();

public: 
	SDL_GLContext imguiglcontext;
	bool menuButton = false;
	bool consoleButton = false;
	bool aboutButton = false;
	bool fpsButton = false;
	bool windowButton = false;
	vector<float> fps;
	vector<float> fpsms;
};

#endif