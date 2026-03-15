#include <iostream>
#include <windows.h>

// Define a function pointer type that matches the Go export
typedef void (__stdcall *ProcessStringFunc)(const char*);

int main() {
    // 1. Load the DLL
    HINSTANCE hGetProcIDLL = LoadLibrary("infinity.dll");

    if (!hGetProcIDLL) {
        std::cerr << "Could not load infinity.dll" << std::endl;
        return EXIT_FAILURE;
    }

    // 2. Resolve the function address
    ProcessStringFunc ProcessString = (ProcessStringFunc)GetProcAddress(hGetProcIDLL, "ProcessString");

    if (!ProcessString) {
        std::cerr << "Could not locate the function ProcessString" << std::endl;
        FreeLibrary(hGetProcIDLL);
        return EXIT_FAILURE;
    }

    // 3. Call the function
    const char* myData = "Apple, Banana, Cherry, Dragonfruit";
    std::cout << "[C++] Calling Go DLL with: " << myData << std::endl;

    ProcessString(myData);

    // 4. Cleanup
    FreeLibrary(hGetProcIDLL);
    return EXIT_SUCCESS;
}