#ifndef LIST_H
#define LIST_H

#include <string>
#include <QObject>
#include <map>
#include <iterator>
#include <QFile>
#include <iostream>
#include <object.h>

class List :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> list READ list WRITE setlist NOTIFY listChanged)

public:
 explicit List(QObject *parent = nullptr);



    void setlist( const QList<QObject*> &l){
     m_list=l;
      emit listChanged();
    }
    void append(QString name,QString prize){

        m_list.append(new Object(name,prize));
        emit listChanged();
    }

    QList<QObject*> list() const{
        return m_list;
    }

signals:
    void listChanged();

private:
    QList<QObject*> m_list;
public slots:
    void onappend(QString name,QString prize){
        m_list.append(new Object(name ,prize));
        emit listChanged();
    }
    void ondelete(int i){
        m_list.removeAt(i);
        emit listChanged();
    }

};

#endif // LIST_H
