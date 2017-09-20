#pragma once
#include "Module.h"
#include "Globals.h"

#define GRAVITY_X 0.0f
#define GRAVITY_Y -7.0f

#define PIXELS_PER_METER 50.0f// if touched change METER_TO_PIXELS too
#define METER_PER_PIXEL 0.02f// this is 1 / PEXELS_PER_METER !

#define METERS_TO_PIXELS(m) ((int) floor(PIXELS_PER_METER * m))
#define PIXEL_PER_METER(p) ((float) METER_TO_PIXELS  *p)

class b2World; //instead of including box2d.h
class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

private:
	b2World* world;
	bool debug;
};