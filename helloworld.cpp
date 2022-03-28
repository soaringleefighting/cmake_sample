#include <stdio.h>

int main(int argc, char* argv[])
{
#ifdef _TEST
   printf("Hello world! This is a CMake Project! \n __TEST defined!\n");
#else
   printf("Hello world! This is a CMake Project! \n __TEST undefined!\n");
#endif
}
