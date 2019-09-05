#ifndef _SETPATHAPI_H_INCLUDED_
#define _SETPATHAPI_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

namespace setpath {
extern int setpath(int, char **, char **) __attribute__((__visibility__("default")));
}

#ifdef __cplusplus
}
#endif
#endif /* _SETPATHAPI_H_INCLUDED_ */
