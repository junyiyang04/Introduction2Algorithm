#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
  echo "Linux"
elif [[ "$OSTYPE" == "darwin"* ]]; then
  echo "Mac OSX"
elif [[ "$OSTYPE" == "cygwin" ]]; then
  echo "Windows/Cygwin"
elif [[ "$OSTYPE" == "msys" ]]; then
  echo "Windows/MinGW"
elif [[ "$OSTYPE" == "win32" ]]; then
  echo "Windows"
else
  echo "Unknown OS: $OSTYPE"
fi


# 在 Bash shell 中，`[[ ... ]]` 和 `[ ... ]` 都可以用于条件测试。然而，`[[ ... ]]` 是一个更强大的版本，提供了一些额外的功能。

# - `[[ ... ]]` 提供了模式匹配和正则表达式支持。
# - `[[ ... ]]` 支持字符串比较操作符（如 `==`, `!=`, `<`, `>`），而 `[ ... ]` 不支持。
# - 在 `[[ ... ]]` 中，你可以使用 `&&` 和 `||` 来进行逻辑操作，而在 `[ ... ]` 中则需要使用 `-a` 和 `-o`。
# - `[[ ... ]]` 不会进行单词拆分或路径名扩展，这使得它在处理包含空格或通配符的字符串时更安全。

# 因此，虽然 `[ ... ]` 在所有 POSIX shell 中都可用，但如果你正在编写 Bash 脚本，并且需要上述 `[[ ... ]]` 提供的额外功能，那么使用 `[[ ... ]]` 会更好。

build_folder="build"
if [ ! -d $build_folder ]; then
    if [[ "$OSTYPE" ==  "darwin"* || "$OSTYPE" ==  "linux-gnu"* ]]; then 
        mkdir ${build_folder}
    fi
fi
cd build

rm -rf CMakeFiles
rm -rf CMakeCache.txt
rm -rf cmake_install.cmake
rm -rf I2A*
rm -rf Makefile

cmake .. && make -j12 && ./I2A
