#include <errno.h>
#include <stdio.h>
//#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h> // for posix_memalign()
void test()
{
    char* buf;
    int ret;
    int align = 4096;
    uintptr_t align2 = 4096;
    int alc_size = 17;
    ret = posix_memalign((void**)&buf, align, 4096);
    char* buf2 = (char*)malloc(alc_size);
    if(ret){
        errno = ret;
        perror("posix_memalign");
        return ;
    }
    printf("%p %p\n", buf, buf2);
    printf("%llu %llu\n", (unsigned long long)buf % align, (unsigned long long)buf2 % align);
    printf("%08" PRIdPTR ":" "%08" PRIdPTR "\n", (uintptr_t)buf % align2, (uintptr_t)buf2 % align2);
    
    free(buf);
    free(buf2);
}
int main()
{
    test();
    return 0;
}