# NoKernel32 - Basic

This repository contains a C++ library that uses Microsoft Detours to hook `GetModuleHandleA` and `LoadLibraryA` functions. The library does nothing if the loaded module name contains "RAT".

## Prerequisites

- Microsoft Windows (Tested on Windows 11 Professional Workstation)
- Microsoft Visual Studio (Tested with Visual Studio 2019)
- Microsoft Detours Library

## Installation

1. Clone this repository.
2. Download and build the Microsoft Detours library.
3. Link against `detours.lib` when compiling your code.

## Usage

Include the library in your project and use it to hook `GetModuleHandleA` and `LoadLibraryA` functions.

## Disclaimer

Please note that this is a basic example and may need to be adapted to your specific needs. Also, be aware that using Detours and function hooking can be complex and can potentially cause issues if not done correctly. Always thoroughly test your code in a safe and controlled environment before deploying it.

Also, please make sure you have the necessary permissions and legal rights to perform such operations, as they can be seen as intrusive and potentially harmful. Always respect user privacy and legal guidelines.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details
