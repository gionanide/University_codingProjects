#ifndef MAIN_CPP
#define MAIN_CPP


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlEngine>
#include "datastore.h"
#include <QtQuick>
#include "datastore.h"
#include <string>
#include <map>
#include <iterator>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDir>
#include <iostream>
#include <QCoreApplication>
#include <QtQuick/QQuickView>
#include <QQmlContext>
#include <object.h>
#include <QVariant>
#include <list.h>
#include <QQuickItem>
#include <QSize>
 QQmlContext* context;
 DataStore dt;

int main(int argc, char *argv[])
{


    QGuiApplication app(argc, argv);













qmlRegisterType<Object>("my_object",1,0,"Object");


    QQmlApplicationEngine engine;
  context  = engine.rootContext();




 // list.ondelete(0);
    //   context->setContextProperty("object",&ob);

  context->setProperty("width", qApp->screens()[0]->size().width());
  context->setProperty("height", qApp->screens()[0]->size().height());

   context->setContextProperty("datastore",&dt);




     engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

void resizeEvent(QResizeEvent * ev){

    context->setProperty("width", qApp->screens()[0]->size().width());
    context->setProperty("height", qApp->screens()[0]->size().height());
}

#endif // DATASTORE_H
