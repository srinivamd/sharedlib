#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

const char *keys[] = {"ROCM_ROOT", "HCC_PATH"};
const char *values[] = {"/opt/rocm", "/opt"};
int main(int argc, char **argv)
{
    if (argc < 1) {
        printf("Usage: %s <path_to_libsetpath.so>\n", argv[0]);
        return 0;
    }
    void *dlh = dlopen(argv[1], RTLD_LAZY);
    if (!dlh) {
        printf("dlopen of %s failed: %s\n", argv[1], dlerror());
        return -1;
    }
    /* look up setpath function symbol */
    int (*fn)(int, const char **, const char **) = (int (*)(int, const char **, const char **))dlsym(dlh, "setpath");
    if (!fn) {
        printf("setpath function not found!\n");
        dlclose(dlh);
        return -1;
    }
    /* call fn */
    (*fn)(sizeof(keys)/sizeof(keys[0]), keys, values);

    return 0;
}
