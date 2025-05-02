#if defined(__CYGWIN__)
#include "ares_config-msys.h"
#elif defined(__MINGW32__)
#include "ares_config-mingw.h"
#elif defined(_WIN32)
#include "ares_config-win32.h"
#endif
