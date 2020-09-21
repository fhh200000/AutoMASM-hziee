#ifndef INIUTIL_H
#define INIUTIL_H

#include <QSettings>
#include "vardefs.h"
extern QSettings* settings;

int load_settings();
int unload_settings();
QString get_settings(QString key);
int set_settings(QString key,QString val);
#endif // INIUTIL_H
