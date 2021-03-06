/*
Copyright(c) 2016 - 2018 Christopher Joseph Dean Schaefer
Copyright(c) 2018 Max Maisel

This software is provided 'as-is', without any express or implied
warranty.In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions :

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software.If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#pragma warning(disable: 4005)

#pragma once

#ifndef NOMINMAX
#define NOMINMAX
#endif

// C++ headers
#include <algorithm>
#include <atomic>
#include <cassert>
#include <condition_variable>
#include <type_traits>
#include <cerrno>
#include <chrono>
#include <cstdint>
#include <cstdlib>		// For malloc/free/abort & size_t
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <limits>
#include <math.h>
#include <memory>
#include <mutex>
#include <new>
#include <queue>
#include <stack>
#include <stdexcept>
#include <thread>
#include <type_traits>
#include <utility>
#include <vector>
#include <unordered_map>
#include <map>

// C headers
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Eigen headers
#include <Eigen/Dense>

// Windows headers
//#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <winuser.h>
#ifdef _MSC_VER
#include "winres.h"
#endif
#include "wtypes.h"

// DirectX headers
#include <d3d9.h> // Base class: IDirect3D9
#include <d3d9types.h>
#include <d3d11shader.h>

// Vulkan headers
#include <vulkan/vulkan.h>
#include <vulkan/vk_sdk_platform.h>
#include <vulkan/vulkan.hpp>
#include <spirv.hpp>
#include <GLSL.std.450.h>
