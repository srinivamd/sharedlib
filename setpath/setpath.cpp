#include <iostream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "setpathimpl.h"
#include "setpathapi.h"

#ifdef __cplusplus
extern "C" {
#endif

    namespace setpath {

        std::string  *hcc_prefix;
        std::string  *rocm_root;

        // public API
        int setpath(int nentries, char **keys, char **values)
        {
            std::cout << " version 1 setpath " << std::endl;	
            for (int i = 0; i < nentries; ++i) {
                switch(keys[i][0]) {
                    case 'r':
                    case 'R': // assume ROCM_ROOT key
                        rocm_root = new std::string(values[i]);
                        break;
                    case 'h':
                    case 'H': // assume ROCM_ROOT key
                        hcc_prefix = new std::string(values[i]);
                        break;
                    default: // ignore
                        break;
                }
            }
            setpathimpl::validate(rocm_root);
            setpathimpl::validate(hcc_prefix);
            return 1;
        }
    }

#ifdef __cplusplus
}
#endif

namespace setpathimpl {
    // private impl
    int validate(std::string *s)
    {
        struct stat buf;
        if (s == NULL) {
            std::cout << "NUll Path\n" << std::endl;
            return 0;
        }
        if (stat(s->c_str(), &buf)) {
            std::cout << "Path: " << *s << " does not exist\n" << std::endl;
            std::cout << strerror(errno) << std::endl;
            return -1;
        }
        std::cout << "Path: " << *s << " exists\n" << std::endl;
        return 0;
    }

}


