// SpliteString.cpp : 定义控制台应用程序的入口点。
//
#include <stdio.h>

void splite(const char* str) {
   const char *start = NULL, *next = str;
   for ( ; ; next++ ) {
     switch (*next) {
       case '\0':
          goto end;
       case '\r':
       case '\n':
       case '\t':
       case ' ':
         if (start) {
           printf("%.*s\n", (next - start), start);
           start = NULL;
         }
       break;
       default:
        if (!start) start = next;
     }
   }
end:
  return;
}

int main(int argc, char *argv[])
{
    const char* test1 = "\r\n12312\thaha ggg \r\n\t";
    splite(test1);
    const char* test2 = "12sdfsd       \r\n\t           \r\n     sdfsd \n \n         asdf";
    splite(test2);
    getchar();
    return 0;
}

