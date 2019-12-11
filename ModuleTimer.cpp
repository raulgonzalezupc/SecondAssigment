#include "ModuleTimer.h"
#include "ModuleImgui.h"
#include "SDL.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"

ModuleTimer::ModuleTimer()
{
	gameTime = 0;
	mPausedTicks = 0;

	mPaused = false;
	mStarted = false;
}

ModuleTimer::~ModuleTimer()
{

}

bool ModuleTimer::Init()
{

	App->imgui->AddLog("\n------- Module Timer Init --------\n");
	

	App->imgui->AddLog("------- Module Timer Init --------");

	return true;
}

update_status ModuleTimer::PreUpdate()
{
	return UPDATE_CONTINUE;
}

update_status ModuleTimer::Update()
{
	return UPDATE_CONTINUE;
}

update_status ModuleTimer::PostUpdate()
{
	return UPDATE_CONTINUE;
}

bool ModuleTimer::CleanUp()
{
	return true;
}

void ModuleTimer::StartRealTimeClock()
{
	realTime=SDL_GetTicks();

}
void ModuleTimer::StartGameTimeClock()
{
	//Start the timer
	mStarted = true;

	//Unpause the timer
	mPaused = false;

	//Get the current clock time
	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

float ModuleTimer::Read() 
{
	Uint32 time = 0;

	//If the timer is running
	if (mStarted)
	{
		//If the timer is paused
		if (mPaused)
		{
			//Return the number of ticks when the timer was paused
			time = mPausedTicks;
		}
		else
		{
			//Return the current time minus the start time
			time = SDL_GetTicks() - mStartTicks;
		}
	}

	return time;
}



void ModuleTimer::Pause()
{
	//If the timer is running and isn't already paused
	if (mStarted && !mPaused)
	{
		//Pause the timer
		mPaused = true;

		//Calculate the paused ticks
		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}

}
void ModuleTimer::Unpause()
{
	//If the timer is running and paused
	if (mStarted && mPaused)
	{
		//Unpause the timer
		mPaused = false;

		//Reset the starting ticks
		mStartTicks = SDL_GetTicks() - mPausedTicks;

		//Reset the paused ticks
		mPausedTicks = 0;
	}
}
void ModuleTimer::Stop()
{
	//Stop the timer
	mStarted = false;

	//Unpause the timer
	mPaused = false;

	//Clear tick variables
	mStartTicks = 0;
	mPausedTicks = 0;
}
bool ModuleTimer::isStarted()
{
	//Timer is running and paused or unpaused
	return mStarted;
}

bool ModuleTimer::isPaused()
{
	//Timer is running and paused
	return mPaused && mStarted;
}

	return realTime;
}
float ModuleTimer::StartGameTimeClock()
{
	gameTime = SDL_GetTicks();
	return gameTime;
}

float ModuleTimer::Read() const
{
	float current_time;

	if (running)
	{
		if (paused)
		{
			current_time = (pause_start_ticks - gameTime) - timePassedWhilePaused;
		}
		else
		{
			current_time = (SDL_GetTicks() - gameTime) - timePassedWhilePaused;
		}

	}
	else
	{
		current_time = end_time;
	}

	return current_time;
}

void ModuleTimer::Resume()
{
	if (paused)
	{
		timePassedWhilePaused += SDL_GetTicks() - pause_start_ticks;
		paused = false;
	}
}

float ModuleTimer::Pause()
{
	if (!paused)
	{
		pause_start_ticks = SDL_GetTicks();
		paused = true;
	}
	else {
		paused = false;
	}
	return pause_start_ticks - gameTime - timePassedWhilePaused;
}

float ModuleTimer::Stop()
{
	end_time = SDL_GetTicks() - gameTime - timePassedWhilePaused;
	running = false;

	return end_time;
}

void ModuleTimer::ShowTimerUI()
{
	StartRealTimeClock();
	ImGui::Begin("Clock");

	if (ImGui::Button("Start"))
	{
		if (!isStarted()) {
			StartGameTimeClock();
			App->imgui->AddLog("Start\n");
		}
	} ImGui::SameLine();
	if (ImGui::Button("Pause"))
	{
		if (isPaused())
		{
			Unpause();
			App->imgui->AddLog("Unpause\n");
		}
		else
		{
			Pause();
			App->imgui->AddLog("Pause\n");

		}
	} ImGui::SameLine();
	if (ImGui::Button("Stop"))
	{
		if (isStarted())
		{
			Stop();
			App->imgui->AddLog("Stop\n");
		}
	} ImGui::SameLine();
	
	if (ImGui::Button("Advance")) {

	}
	gameTime=Read();
	
	ImGui::Text("Real time:  %d:%d:%d", (realTime / (1000 * 60 * 60)) % 24, (realTime / (1000 * 60)) % 60, (realTime / 1000) % 60);
	ImGui::SameLine();
	ImGui::Text("Game time:  %d:%d:%d", (gameTime / (1000 * 60 * 60)) % 24, (gameTime / (1000 * 60)) % 60, (gameTime / 1000) % 60); 

	//TODO->Put fps rate in configuration fps window
	ImGui::SliderFloat("Fps Rate ", &fpsrate, 10.0f, 60.0F, "%.2f", 1.0f);
	SDL_Delay(1000/fpsrate - (SDL_GetTicks() - realTime)); // 500 should make 2 frames per second.
	
	
	
	ImGui::End();
}

	if (!paused)
	{
		StartGameTimeClock(); 
		gameTime -= timePaused;
	}
	if (ImGui::Button("Pause"))
	{
		Pause();
		timePaused = Stop();
	}

	if (ImGui::Button("Stop"))
	{
		gameTime = 0;
		stop = true;
	}
	if (ImGui::Button("Advance")) {

	}
	
	ImGui::Text("Real time:  %d:%d:%d", (realTime / (1000 * 60 * 60)) % 24, (realTime / (1000 * 60)) % 60, (realTime / 1000) % 60);
	ImGui::Text("Game time:  %d:%d:%d", (gameTime / (1000 * 60 * 60)) % 24, (gameTime / (1000 * 60)) % 60, (gameTime / 1000) % 60);
	

	
	ImGui::End();
}