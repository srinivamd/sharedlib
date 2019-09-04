#ifndef _FOOAPI_H_INCLUDED_
#define _FOOAPI_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

namespace foo {
extern int foo(int i) __attribute__((__visibility__("default")));
}

#ifdef __cplusplus
}
#endif
#endif /* _FOOAPI_H_INCLUDED_ */
