#include "entry-point.hpp"

namespace night {
	auto main_thread() -> int {
		// ...

		while (true) {};
		return EXIT_SUCCESS;
	}
}

auto DllMain(HMODULE mod, uintptr_t reason, void**) -> int {
	if (reason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(mod);
		std::thread(night::main_thread).detach();
	}

	return 1;
}