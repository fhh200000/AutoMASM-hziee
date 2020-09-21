#include "iniutil.h"
#include <QtCore>
#include <QApplication>
#include <cstdio>


QSettings* settings=nullptr;
int load_settings() {
    QString inifile_path = QApplication::applicationDirPath()+QString("/settings.ini");
    debug(inifile_path);
    FILE* f;
    //设置文件不存在，将会新建文件.
    #ifdef _WIN32
    fopen_s(&f,inifile_path.toStdString().c_str(),"ab+");
    #else
    f = fopen(inifile_path.toStdString().c_str(),"ab+");
    #endif
    fclose(f);
    inifile_path = QApplication::applicationDirPath()+QString("/settings.ini");
    settings = new QSettings(inifile_path,QSettings::IniFormat);
    settings->setIniCodec(QTextCodec::codecForName("UTF-8"));
    settings->sync();
    if(settings==nullptr) {
        return AUTOMASM_FAILURE;
    }
    return AUTOMASM_SUCCESS;
    /*
    QString inifile_path = QApplication::applicationDirPath()+QString("/settings.ini");
    debug(inifile_path);
    settings = new QSettings(inifile_path,QSettings::IniFormat);
    settings->sync();
    if(settings==nullptr) {
        debug(QString("File not found:%1.\n").arg(inifile_path));
        FILE* f;
        //设置文件不存在，将会新建文件.
        #ifdef _WIN32
        fopen_s(&f,inifile_path.toStdString().c_str(),"w");
        #else
        f = fopen(inifile_path.toStdString().c_str(),"w");
        #endif
        fclose(f);
        settings = new QSettings(inifile_path,QSettings::IniFormat);
        if(settings==nullptr) {
            return AUTOMASM_FAILURE;
        }
    }
    return AUTOMASM_SUCCESS;
    */
}
int unload_settings() {
    if(settings!=nullptr) {
        settings->sync();
        delete settings;
    }
    return AUTOMASM_SUCCESS;
}
QString get_settings(QString key) {
    return settings->value(key).toString();
}
int set_settings(QString key,QString val) {
    settings->setValue(key,val);
    settings->sync();
    return AUTOMASM_SUCCESS;
}
