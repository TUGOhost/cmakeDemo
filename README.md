## 前言

本文算是对[官方文档](https://cmake.org/cmake/help/v3.18/guide/tutorial/index.html)的翻译内容吧，不算多么深的技术。也将其中的代码发布到[Github](https://github.com/TUGOhost/cmakeDemo)。跟官网一样，也是一步步的来。

## 开始（Step 1）

大部分基础项目都是从源代码文件编译成可执行文件。对于一个简单的项目来说，`CMakeLists.txt`只需要三行就可以解决。

创建一个`CMakeLists.txt`文件，在`Step1` 的文件夹中：

```cmake
# 设置cmake最低的版本号
cmake_minimum_required(VERSION 3.10)

# 设置项目名
project(Tutorial)

# 添加可执行的文件
add_executable(Tutorial tutorial.cc)
```

**注意**在这个例子中使用了小写的命令。大写、小写或者大小写都用的命令在`CMake`中都是被支持的。

`tutorial.cc`的源代码是一个能够计算一个数的平方根。

### 添加版本号和头文件

第一个功能是我们给可执行文件和项目添加版本号。尽管我们可以在源代码中这样操作，但是使用`CMake`可以提供更大的灵活性。

首先，修改`CMakeLists.txt`文件以使用`project()`命令设置项目名称和版本号：

```cmake
# 设置项目名和版本号
project(Tutorial VERSION 1.0) 
```

之后，配置头文件将版本号传给源代码：

```cmake
configure_file(tutorial.h.in tutorial.h)
```

由于已配置的文件将被写入二叉树，因此我们必须将该目录添加到路径列表中以搜索包含文件。将代码添加到`CMakeLists.txt`文件的末尾：

```cmake
target_include_directories(Tutorial PUBLIC
             "${PROJECT_BINARY_DIR}"
             )
```

在源目录中创建`tutorial.h.in`：

```c
#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
```

当`CMake`配置头文件的时候，`@Tutorial_VERSION_MAJOR@`和`@Tutorial_VERSION_MINOR@`都会被替换掉。

下一步，修改`tutorial.cc`，包含头文件`tutorial.h`。

最后，通过更新`tutorial.cc`来打印版本号：

```cc
  if (argc < 2) {
    // 打印版本号
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }
```

### 指定C++标准

```cmake
# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

### 编译并且测试

通过运行`cmake`程序或者`cmake-gui`来配置项目，然后使用配所选的构建工具进行构建。

```
mkdir Step1_build && cd Step1_build
cmake ../Step1
cmake --build
```

```shell
./Tutorial 25
the sqrt of 25 is 5
```

