#pragma once
#include "pch.h"
#include "FumoObject.h"

class FumoCircle : public FumoObject
{
	// Inherited via FumoObject
	void Draw() override;
	void Update(float deltaTime) override;
	void Destroy() override;
	void SetPosition(float x, float y) override;
	void SetScale(float x, float y) override;
	void SetRotation(float angle) override;
	void SetColor(float r, float g, float b, float a) override;
	void SetTexture(const char* path) override;
	void SetShader(const char* path) override;
	void SetMesh(const char* path) override;
	void SetMaterial(const char* path) override;
	void SetLight(const char* path) override;
	void SetCamera(const char* path) override;
	void SetSound(const char* path) override;
	void SetCollider(const char* path) override;
	void SetRigidBody(const char* path) override;
	void SetScript(const char* path) override;
	void SetParent(const char* path) override;
	void AddChild(const char* path) override;
	void RemoveChild(const char* path) override;
	void GetPosition() override;
	void GetScale() override;
	void GetRotation() override;
	void GetColor() override;
	void GetTexture() override;
	void GetShader() override;
	void GetMesh() override;
	void GetMaterial() override;
	void GetLight() override;
	void GetCamera() override;
	void GetSound() override;
	void GetCollider() override;
	void GetRigidBody() override;
	void GetScript() override;
	void GetParent() override;
	void GetChild() override;
	void GetSibling() override;
	void GetRoot() override;
	void GetScene() override;
	void GetEngine() override;
	void GetTime() override;
	void GetDeltaTime() override;
	void GetFrameRate() override;
	void GetInput() override;
	void GetOutput() override;
	void GetPhysics() override;
	void GetAudio() override;
};

