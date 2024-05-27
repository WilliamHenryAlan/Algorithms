#include <iostream>
#include <ctime>
/*
time(0)从1970年到现在的秒数（配合随机数）
clock()
*/
#include <cctype>
/*
isdigit()
isalpha()
*/
int main() {
    int r = srand(time(0));
    
}

/*
在 C 语言中，你可以使用 `stdlib.h` 头文件提供的函数来生成随机数。下面是两种常见的方法：

1. 使用 `rand()` 函数结合 `srand()` 函数生成随机数。

   ```c
   #include <stdio.h>
   #include <stdlib.h>
   #include <time.h>

   int main() {
       // 使用 time 函数设置种子
       srand(time(NULL));

       // 生成随机数
       int randomNumber = rand();

       printf("Random Number: %d\n", randomNumber);

       return 0;
   }
   ```

   上述示例中，首先使用 `time(NULL)` 函数获取当前时间作为随机数生成器的种子，然后使用 `srand()` 函数设置种子。接下来，使用 `rand()` 函数生成一个随机数。

2. 使用 `random()` 函数结合 `srandom()` 函数生成随机数。

   ```c
   #include <stdio.h>
   #include <stdlib.h>
   #include <time.h>

   int main() {
       // 使用 time 函数设置种子
       srandom(time(NULL));

       // 生成随机数
       long randomNumber = random();

       printf("Random Number: %ld\n", randomNumber);

       return 0;
   }
   ```

   类似地，上述示例中，使用 `time(NULL)` 函数获取当前时间作为随机数生成器的种子，然后使用 `srandom()` 函数设置种子。接下来，使用 `random()` 函数生成一个随机数。

无论是使用 `rand()` 还是 `random()` 函数，都需要注意的是，它们生成的是伪随机数，而不是真正的随机数。为了生成更为随机的结果，你可以在设置种子之前调用 `time(NULL)` 函数，以确保每次生成的种子都不同。

希望这个回答对你有所帮助！如果你还有其他问题，请随时提问。
*/