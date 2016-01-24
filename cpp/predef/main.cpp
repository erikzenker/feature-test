#include <boost/predef.h>
#include <iostream>

int main()
{
    // Architecture
#if BOOST_ARCH_ALPHA
    std::cout << "Arch: " << "DEC Alpha" << std::endl;
#elif BOOST_ARCH_ARM
    std::cout << "Arch: " << "ARM" << std::endl;
#elif BOOST_ARCH_BLACKFIN
    std::cout << "Arch: " << "Blackfin" << std::endl;    
#elif BOOST_ARCH_CONVEX
    std::cout << "Arch: " << "Convex" << std::endl;    
#elif BOOST_ARCH_IA64
    std::cout << "Arch: " << "Intel Itanium 64" << std::endl;    
#elif BOOST_ARCH_M68K
    std::cout << "Arch: " << "Motorola 68k" << std::endl;    
#elif BOOST_ARCH_MIPS
    std::cout << "Arch: " << "MIPS" << std::endl;    
#elif BOOST_ARCH_PARISK
    std::cout << "Arch: " << "HP/PA RISC" << std::endl;    
#elif BOOST_ARCH_PPC
    std::cout << "Arch: " << "PowerPC" << std::endl;    
#elif BOOST_ARCH_PYRAMID
    std::cout << "Arch: " << "Pyramid 9810" << std::endl;    
#elif BOOST_ARCH_RS6000
    std::cout << "Arch: " << "RS/6000" << std::endl;    
#elif BOOST_ARCH_SPARC
    std::cout << "Arch: " << "Sparc" << std::endl;    
#elif BOOST_ARCH_SH
    std::cout << "Arch: " << "SuperH" << std::endl;    
#elif BOOST_ARCH_SYS370
    std::cout << "Arch: " << "System/370" << std::endl;    
#elif BOOST_ARCH_SYS390
    std::cout << "Arch: " << "System/390" << std::endl;    
#elif BOOST_ARCH_X86
    std::cout << "Arch: " << "X86" << std::endl;
#elif BOOST_ARCH_Z
    std::cout << "Arch: " << "z/Architecture" << std::endl;
#elif BOOST_ARCH_X86_32
    std::cout << "Arch: " << "Intel x86" << std::endl;
#elif BOOST_ARCH_X86_64
    std::cout << "Arch: " << "Intel IA-64" << std::endl;
#else
    std::cout << "Arch: " << "unknown" << std::endl;    
#endif

    // Compiler
#if BOOST_COMP_CLANG
    std::cout << "Compiler: " << "Clang" << std::endl;
#elif BOOST_COMP_GNUC
    std::cout << "Compiler: " << "Gnu GCC C/C++" << std::endl;
#elif BOOST_COMP_IBM
    std::cout << "Compiler: " << "IBM XL C/C++" << std::endl;
#elif BOOST_COMP_MSVC
    std::cout << "Compiler: " << "Microsoft Visual C/C++" << std::endl;
#else
    std::cout << "Compiler: " << "unknown" << std::endl;
#endif

    
    // Operating System
#if BOOST_OS_LINUX
    std::cout << "OS: " << "Linux" << std::endl;
#elif BOOST_OS_WINDOWS
    std::cout << "OS: " << "Windows" << std::endl;
#else
    std::cout << "OS: " << "unknown" << std::endl;
#endif
    
    return 0;
}
