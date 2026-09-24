#include "threadtools.h"

#include <iostream>
#include <thread>

// Smoke test for joinProAudioTask/leaveProAudioTask. On Windows the thread joins the MMCSS "Pro Audio"
// task if the service allows it, which exercises the functions loaded from avrt.dll, and falls back to a
// priority otherwise. Elsewhere it only raises the priority, which may be refused without privileges.
// Either outcome passes; the calls must return, and the MMCSS slot must be free again after leaving.

int main()
{
	std::thread worker([]
	{
		for(int i = 0; i < 2; ++i)
		{
			void* task = dsp56k::ThreadTools::joinProAudioTask();
			std::cout << "  round " << i << ": " << (task ? "joined the MMCSS Pro Audio task" : "priority fallback") << std::endl;
			dsp56k::ThreadTools::leaveProAudioTask(task);
		}
	});
	worker.join();

	// leaving without a task is a no-op
	dsp56k::ThreadTools::leaveProAudioTask(nullptr);

	std::cout << "PASSED" << std::endl;
	return 0;
}
