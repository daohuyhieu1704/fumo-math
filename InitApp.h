#pragma once
#ifndef INITAPP_H
#define INITAPP_H

#include "pch.h"
#include "exports.h"

VOID			InitialVariables();
ATOM			CreateWindowClass(HWND, HINSTANCE);
HWND			InitWindow(HWND, HINSTANCE);
VOID			MsgLoop();

#endif // INITAPP_H