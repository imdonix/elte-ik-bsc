// Use cl::vector instead of STL version
#define __NO_STD_VECTOR
#define __CL_ENABLE_EXCEPTIONS

#include <CL/cl.hpp>
#include <iostream>
#include <string>
#include "utils.h"

using namespace cl;

int main() {

	try {
		// Get available platforms
		vector<Platform> platforms;
		Platform::get(&platforms);

		vector<Device> devices;
		Context context;

		for (auto p : platforms) {

			try {
				std::cout << p.getInfo<CL_PLATFORM_NAME>() << std::endl;
				std::cout << p.getInfo<CL_PLATFORM_VERSION>() << std::endl;

				// Select the default platform and create a context using this platform and the GPU
				// These are key-value pairs.
				cl_context_properties cps[3] = {
					CL_CONTEXT_PLATFORM,
					(cl_context_properties)(p)(),
					0
				};

				context = Context(CL_DEVICE_TYPE_GPU, cps);

				// Get a list of devices on this platform
				devices = context.getInfo<CL_CONTEXT_DEVICES>();

				for (const auto& d : devices)
				{
					std::cout << d.getInfo<CL_DEVICE_NAME>() << std::endl;
					std::cout << d.getInfo<CL_DEVICE_MAX_CLOCK_FREQUENCY>() << std::endl;
					std::cout << (d.getInfo<CL_DEVICE_GLOBAL_MEM_SIZE>() / 1024) / 1024 << std::endl;
				}

			} catch (Error error) {
				oclPrintError(error);
				continue;
			}

		}

		if(devices.size() == 0) {
			throw Error(CL_INVALID_CONTEXT, "Failed to create a valid context!");
		}

	} catch(Error error) {
		oclPrintError(error);
	}

	std::cin.get();

	return 0;
}