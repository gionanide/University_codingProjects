#ifndef HELP_H
#define HELP_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class HelpData;

class Help
{
public:
    Help();
    Help(const Help &);
    Help &operator=(const Help &);
    ~Help();

private:
    QSharedDataPointer<HelpData> data;
};

#endif // HELP_H