#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <QObject>
#include <map>
#include <iterator>
#include <QFile>
#include <iostream>

class Object : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString prize READ prize WRITE setPrize NOTIFY prizeChanged)
public:
 explicit Object(QObject *parent = nullptr);
 explicit Object(QString s1,QString s2){
       m_name=s1;
       m_prize=s2;
       emit nameChanged();
       emit prizeChanged();
    }


    void setName(const QString &n){
     m_name=n;
      emit nameChanged();
    }
    void setPrize(const QString &p){
        m_prize=p;
        emit prizeChanged();
    }
    QString name() const{
        return m_name;
    }
    QString prize() const{
        return m_prize;
    }
signals:
    void nameChanged();
    void prizeChanged();
private:
    QString m_name;
    QString m_prize;
};

#endif // OBJECT_H
