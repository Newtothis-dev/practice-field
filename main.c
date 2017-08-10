#include <stdio.h> 

#ifdef __DEBUG__
#define HelloWorld 1
#endif

#ifdef __OTHR___
#define AA 1
#endif

int main()
{
  if (HelloWorld && AA)
    {
      printf("hello world\n\r");
    }
}
