#ifndef _MODULECAMERA_H_
#define _MODULECAMERA_H_

#include "Module.h"
#include "Globals.h"
#include "MathGeoLib/include/Math/float4x4.h"
#include "MathGeoLib/include/Math/float3x3.h"
#include "MathGeoLib/include/Geometry/Frustum.h"

typedef unsigned __int8 Uint8;


class ModuleCamera : public Module
{
public:
	ModuleCamera();
	virtual ~ModuleCamera();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();


	void SetNearPlaneDistance(const float nearDist);
	void SetFarPlaneDistance(const float farDist);

public:
	void SetAspectRatio(const float aspect_ratio);
	void setFOV(const float fov);
	void Position(const float3 position);
	void Rotate(char axis, float movement);
	void MoveUp();
	void MoveDown();
	void MoveForward();
	void MoveBackwards();
	void MoveLeft();
	void MoveRight();
	void multSpeed();

	void generateMatrices();

	void LookAt(const float3 focus);
	void LookAt(const float x, const float y, const float z);
	void SetOrientation(const float3 orientation);
	void focusCameraToNewPoint(const float3 &newPos);
	void Orbit(char axis, float movement);

public:



	bool is_orbiting = false;
	float3x3 rotation_matrix;



	Frustum frustum;
	float rot_speed = 0.1f;
	float aspect;
	float4x4 proj;
	float4x4 view;
	float4x4 model;
	float yaw = -90.0f;
	float pitch = 0;
	const Uint8 *keyboard = NULL;

public:
	float3 new_camera_pos;
	const float distance = 0.25f * 1.0F;
	float speed = 1.0f;

};

#endif