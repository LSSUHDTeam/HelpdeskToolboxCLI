#ifndef HDTB_OSINCLUDES
#define HDTB_OSINCLUDES


#ifdef _WIN32



#elif __APPLE__

    // HDD Information
    #include <sys/statvfs.h>
    #include <sys/sysctl.h>
#else



#endif


#endif // HDTB_OSINCLUDES

