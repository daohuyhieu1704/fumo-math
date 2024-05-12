#pragma once
#include "pch.h"
class FumoObject abstract
{
protected:
	Geometry::Point3d Position;
	Geometry::Velocity3d Velocity;
public:
	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Destroy() = 0;
	virtual void SetPosition(float x, float y) = 0;
	virtual void SetScale(float x, float y) = 0;
	virtual void SetRotation(float angle) = 0;
	virtual void SetColor(float r, float g, float b, float a) = 0;
	virtual void SetTexture(const char* path) = 0;
	virtual void SetShader(const char* path) = 0;
	virtual void SetMesh(const char* path) = 0;
	virtual void SetMaterial(const char* path) = 0;
	virtual void SetLight(const char* path) = 0;
	virtual void SetCamera(const char* path) = 0;
	virtual void SetSound(const char* path) = 0;
	virtual void SetCollider(const char* path) = 0;
	virtual void SetRigidBody(const char* path) = 0;
	virtual void SetScript(const char* path) = 0;
	virtual void SetParent(const char* path) = 0;
	virtual void AddChild(const char* path) = 0;
	virtual void RemoveChild(const char* path) = 0;
	virtual void GetPosition() = 0;
	virtual void GetScale() = 0;
	virtual void GetRotation() = 0;
	virtual void GetColor() = 0;
	virtual void GetTexture() = 0;
	virtual void GetShader() = 0;
	virtual void GetMesh() = 0;
	virtual void GetMaterial() = 0;
	virtual void GetLight() = 0;
	virtual void GetCamera() = 0;
	virtual void GetSound() = 0;
	virtual void GetCollider() = 0;
	virtual void GetRigidBody() = 0;
	virtual void GetScript() = 0;
	virtual void GetParent() = 0;
	virtual void GetChild() = 0;
	virtual void GetSibling() = 0;
	virtual void GetRoot() = 0;
	virtual void GetScene() = 0;
	virtual void GetEngine() = 0;
	virtual void GetTime() = 0;
	virtual void GetDeltaTime() = 0;
	virtual void GetFrameRate() = 0;
	virtual void GetInput() = 0;
	virtual void GetOutput() = 0;
	virtual void GetPhysics() = 0;
	virtual void GetAudio() = 0;
};

