/*
Copyright(c) 2018 Christopher Joseph Dean Schaefer

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

#include <atomic>
#include <thread>

#include "LogManager.h"
#include "Perf_RenderManager.h"
#include "WorkItemType.h"
#include "WorkItem.h"
#include "TinyQueue.h"

#include <vulkan/vk_sdk_platform.h>
#include <vulkan/vulkan.hpp>

#ifndef COMMANDSTREAMMANAGER_H
#define COMMANDSTREAMMANAGER_H

#ifndef _MSC_VER
// Used D3D9Ex constants, missing in MinGW

#define D3DPBLENDCAPS_SRCCOLOR2         0x00004000L
#define D3DPBLENDCAPS_INVSRCCOLOR2      0x00008000L

#endif

struct CommandStreamManager
{ 	
	std::thread mWorkerThread;
	RenderManager mRenderManager;

	TinyQueue<WorkItem> mWorkItems;
	TinyQueue<WorkItem> mUnusedWorkItems;

	std::atomic_bool IsRunning = 1;
	std::atomic_bool IsBusy = 0;

	std::atomic<vk::Result> mResult = vk::Result::eSuccess;
	std::atomic<uint32_t> mFrameBit = 1;

	std::map<std::string, std::string> mConfiguration; //should be static after load.

	CommandStreamManager();
	~CommandStreamManager();

	size_t RequestWork(WorkItem* workItem);
	size_t RequestWorkAndWait(WorkItem* workItem);
	WorkItem* GetWorkItem(IUnknown* caller);

private:
	void LoadConfiguration(std::string filename);
};

#endif // COMMANDSTREAMMANAGER_H
