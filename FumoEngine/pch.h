#pragma once
#ifndef PCH_H
#define PCH_H
#include <Windows.h>
#include "resource.h"
#include <d3d11.h>
#include <d2d1.h>
#include <d2d1helper.h>
#include <DirectXMath.h>
#include "../FumoUtils/Geometry.h"
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d2d1.lib")

#define MAX_NAME_LENGTH 256
#define WM_MY_MESSAGE (WM_USER + 1)
#define HInstance() GetModuleHandle(NULL)

#endif // !PCH_H