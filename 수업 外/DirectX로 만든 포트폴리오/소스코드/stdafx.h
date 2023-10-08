// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

// Update Note
// 1.0
// 1.1 : Torus 오브젝트 파일 ASE에서 dat으로 변경

#pragma once

#include "targetver.h"
using namespace std;

#define ENGINE_NAME "DirectX Portfolio 1.1"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// C++ RunTime Header Files
#include <fstream>

// STL Header Files
#include <vector>

// Server Header Files - Kim You Min
#include <winsock2.h>
#include "NetWork.h"
#include "Stream.h"
#include "PacketDefine.h"
#include "SendPacket.h"
#include "RecvPacket.h"


// TODO: reference additional headers your program requires here
#include <d3d9.h>
#include <d3dx9.h>
#include <mmsystem.h>