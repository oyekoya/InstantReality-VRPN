#ifndef _PASSIVEDEF_H_
#define _PASSIVEDEF_H_
#ifdef HAS_PRAGMA_ONCE
#pragma once
#endif

# if defined(COMPILE_WITH_DLL) && defined(WIN32)
#  if defined(AVALONVIEWPASSIVE_DLL)
#   define AVALON_PASSIVE_DLLMAPPING __declspec(dllexport)
#  else
#   define AVALON_PASSIVE_DLLMAPPING __declspec(dllimport)
#  endif
# else
#   define AVALON_PASSIVE_DLLMAPPING
# endif

#endif // _PASSIVEDEF_H_
