#ifndef VARDEFS_H
#define VARDEFS_H

#define AUTOMASM_SUCCESS 0
#define AUTOMASM_FAILURE 1


#define AUTOMASM_DEBUG

#ifdef AUTOMASM_DEBUG
#include <QDebug>
#define debug(x) (qDebug()<<(x))
#else
#define debug(x)
#endif

#ifdef _WIN32
#define DOSBOX_EXEC_NAME "Dosbox主程序(dosbox.exe)"
#else
#define DOSBOX_EXEC_NAME "Dosbox主程序(dosbox)"
#endif

#ifdef _WIN32
#define PROTEUS_EXEC_NAME "Proteus主程序(isis.exe;ISIS.exe)"
#else
#define PROTEUS_EXEC_NAME "Proteus主程序(isis.exe;ISIS.exe)"
#endif


#endif // VARDEFS_H
