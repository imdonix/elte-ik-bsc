#!/bin/sh
echo -- ToolCheck --
lsb_release -a
g++ --version
clang-tidy-10 --version
echo -- ToolCheck -- OK

echo -- Build --
g++ -fsanitize=address,leak,undefined -O3 -Wall -Wextra -Werror mainUhU.cpp -o a.out
g++ -fsanitize=address,leak,undefined -O3 -Wall -Wextra -Werror iter.cpp -o b.out
echo -- Build -- OK

echo -- Run - mainUhu.cpp --
./a.out
echo -- Run - mainUhu.cpp -- OK


echo -- Run - iter.cpp --
./b.out
echo -- Run - iter.cpp -- OK

echo -- Tidy --
clang-tidy-10 mainUhU.cpp --
echo -- Tidy -- OK