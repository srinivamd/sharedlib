#include <iostream>
#include <string>
#include "fooimpl.h"
#include "fooapi.h"

#ifdef __cplusplus
extern "C" {
#endif

namespace foo {

// public API
int foo(int i)
{
	std::cout << fooimpl::doimpl(i) << " version 2 foo " << std::endl;	
	return 1;
}
}

#ifdef __cplusplus
}
#endif

namespace fooimpl {
// private impl
std::string doimpl(int i)
{
	return std::string("foo 2 doimpl ") + std::to_string(i);
}
}


