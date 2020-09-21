# AutoMASM-hziee
A simple &amp; naive tool that integrates MASM(Dosbox) and Proteus together with editor.

一个将MASM/DosBox、Proteus与文本编辑器合而为一的巨型缝合怪#(滑稽)



Due to platform limitations, this tool is currently targeting Microsoft Windows (So sad...)

由于平台限制，目前该项目面向Windows编写TAT

But the author is trying to bring platform compatibility by using macro definitions as follows:

但作者正在尝试通过宏定义的方式挽救平台兼容性，如下：

```c++
#ifdef _WIN32   //Windows Platform.
bool file_exists(QString filename){.....}
#endif
#ifdef __linux__ //Linux Platform.
bool file_exists(QString filename){.....}
#endif
```

(但是后期Hook窗口的时候WIN32 API与X11 API差距实在是太大了，所以估计是要全部重写了TAT)



### 预期功能 / Expected components

1.文本编辑 / Text Editing（废话 / BS）

2.简单的汇编语言语法识别自动机 / BF Assembly Automata (还算简单 / Simple)

3.捕获Proteus窗口并且将其内置 / Hook Proteus window & integrate (有点难了 / a little difficult)

4.通过Proteus在线调试接口实现与汇编的联合单步调试 / single debug with Proteus via 'online' debug server (地狱难度 / hell)

