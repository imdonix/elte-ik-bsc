// Use cl::vector instead of STL version
#define __NO_STD_VECTOR
#define __CL_ENABLE_EXCEPTIONS

#include <CL/cl.hpp>
#include <utility>
#include <iostream>
#include <fstream>
#include <string>

/*TODO*/ // (At the end of the task, try oclCreateContextBy(...))
#include <oclutils.hpp>
//#include "utils.h"

using namespace cl;

int main() {

	// Create the two input vectors
	const int LIST_SIZE = 20000;
	int *A = new int[LIST_SIZE];
	int *B = new int[LIST_SIZE];
	for(int i = 0; i < LIST_SIZE; i++) {
		A[i] = i;
		B[i] = LIST_SIZE - i;
	}

	try {
		// Get available platforms
		vector<Platform> platforms;
		Platform::get(&platforms);

		vector<Device> devices; // !
		Context context; // !

		for (auto p : platforms) {

			try {
				std::cout << p.getInfo<CL_PLATFORM_NAME>() << std::endl;
				std::cout << p.getInfo<CL_PLATFORM_VERSION>() << std::endl;
			
				// Select the default platform and create a context using this platform and the GPU
				cl_context_properties cps[3] = {
					CL_CONTEXT_PLATFORM,
					(cl_context_properties)(p)(),
					0
				};

				context = Context(CL_DEVICE_TYPE_GPU, cps);

				// Get a list of devices on this platform
				devices = context.getInfo<CL_CONTEXT_DEVICES>();

			} catch (Error error) {
				oclPrintError(error);
				continue;
			}

			if (devices.size() > 0)
				break;
		}

		if(devices.size() == 0) {
			throw Error(CL_INVALID_CONTEXT, "Failed to create a valid context!");
		}

		// Create a command queue and use the first device
		CommandQueue queue = CommandQueue(context, devices[0]);

		// Read source file
		std::ifstream sourceFile("vector_add_kernel.cl");
		std::string sourceCode(
			std::istreambuf_iterator<char>(sourceFile),
			(std::istreambuf_iterator<char>()));
		Program::Sources source(1, std::make_pair(sourceCode.c_str(), sourceCode.length()+1));

		// Make program of the source code in the context
		Program program = Program(context, source);

		// Build program for these specific devices
		program.build(devices);

		// Make kernel
		Kernel kernel(program, "vector_add");

		// Create memory buffers
		// 2 × input buffer, 1 × output buffer
		Buffer buffer1 = Buffer(context, CL_MEM_READ_ONLY, sizeof(int) * LIST_SIZE);
		Buffer buffer2 = Buffer(context, CL_MEM_READ_ONLY, sizeof(int) * LIST_SIZE);
		Buffer buffer3 = Buffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * LIST_SIZE);

		// Copy lists A and B to the memory buffers
		/// Write data on input buffers!
		queue.enqueueWriteBuffer(buffer1, CL_TRUE, 0, sizeof(int) * LIST_SIZE, A);
		queue.enqueueWriteBuffer(buffer2, CL_TRUE, 0, sizeof(int) * LIST_SIZE, B);
		
		// Set arguments to kernel
		/// kernel.setArg
		kernel.setArg(0, buffer1);
		kernel.setArg(1, buffer2);
		kernel.setArg(2, buffer3);

		// Run the kernel on specific ND range
		NDRange _global_(LIST_SIZE); // Indextér
		queue.enqueueNDRangeKernel(kernel, cl::NullRange, _global_, cl::NullRange);

		// Read buffer C (the result) into a local piece of memory
		int *C = new int[LIST_SIZE];
		queue.enqueueReadBuffer(buffer3, CL_TRUE, 0, sizeof(int) * LIST_SIZE, C);

		// Check the results!
		for(int i = 0; i < LIST_SIZE; i ++)
			std::cout << A[i] << " + " << B[i] << " = " << C[i] << std::endl; 

	} catch(Error error) {
		oclPrintError(error);
	}

	std::cin.get();

	return 0;
}