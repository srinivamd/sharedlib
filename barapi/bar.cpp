#include <iostream>
#include <string>
#include "barimpl.h"
#include "barapi.h"

// bar depends on fooapi
#include "fooapi.h"

#ifdef __cplusplus
extern "C" {
#endif

namespace bar {

// public API
int bar(int i)
{
    // call foo
    foo::foo(i);
	std::cout << barimpl::doimpl(i) << " version 1 bar " << std::endl;	
	return 1;
}
}

#ifdef __cplusplus
}
#endif

namespace barimpl {
// private impl
std::string doimpl(int i)
{
	return std::string("bar doimpl ") + std::to_string(i);
}
}


