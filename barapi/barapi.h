#ifndef _BARAPI_H_INCLUDED_
#define _BARAPI_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

namespace bar {
extern int bar(int i) __attribute__((__visibility__("default")));
}

#ifdef __cplusplus
}
#endif
#endif /* _BARAPI_H_INCLUDED_ */
