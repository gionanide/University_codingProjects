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
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <list.h>
#include <QStandardPaths>
 DataStore::DataStore(QObject *parent)
{


     folder=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);


items=0;
QDir dir;
//path="D:/User/Documents/QT/";
QStringList pieces=dir.absolutePath().split("/");
path="";
for(int i=0;i<pieces.length()-1;i++){
    path=path+pieces.value(i)+"/";
}


for(int i=0;i<1000;i++){
    tablemoney[i]=0;
    quantityofitemsold[i]=0;
    currentitemsamount[i]=0;
}

income=0;
itemsold=0;

}

bool DataStore:: isempty(QString str){
    if(str==""){
        return true;
    }
    else{
        return false;
    }

}
bool DataStore::isdouble(QString str){
bool  result=false;
str.toDouble(&result);
return result;

}
bool DataStore::isint(QString str){
bool  result=false;
str.toInt(&result);
return  result;
}

void DataStore:: additem(QString name,QString prize){

      items++;
    int tempprize=prize.toDouble();
    itemmap[items-1][0]=name;
    itemmap[items-1][1]=prize;

}
void DataStore::updateitem(QString newname,QString newprize,int thesi){
    itemmap[thesi][0]=newname;
    itemmap[thesi][1]=newprize;

}
void DataStore::deleteitem(int thesi){
    for(int i=thesi;i<items-1;i++){
        itemmap[i][0]=itemmap[i+1][0];
        itemmap[i][1]=itemmap[i+1][1];

    }
    items--;
}
int DataStore::finditem(QString name){
    for(int i=0;i<items;i++){
        if(itemmap[i][0]==name){
            return i;
        }
    }
    return -1;
}
void DataStore:: writestore(QString tab,QString name){
    storename=name;
    tables=tab;

    // QString filename=path+name;
QString filename= folder+"/"+name;

      QFile file(filename);
      if(!file.open(QFile::WriteOnly | QFile :: Text )){
          return;
      }
      QTextStream out(&file);
      out<<storename<<"\n"<<tables<<"\n";


      for(int i=0;i<items;i++){

          out<<itemmap[i][0]<<"|"<<itemmap[i][1]<<"\n";
      }
      file.flush();
      file.close();

}

void DataStore::readstore(QString filepath){
    QStringList pieces=filepath.split("/");
    items=0;

    path="";
    for(int i=3;i<pieces.length()-1;i++){
        path=path+pieces.value(i)+"/";
    }

    storename=pieces.value(pieces.length()-1);

   //  QFile file(path+storename);
       QFile file(folder+"/"+storename);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

         QTextStream in(&file);
         storename= in.readLine();
         tables= in.readLine();


         while (!in.atEnd()) {

             QString line = in.readLine();
             QStringList linesplit=line.split("|");
             additem(linesplit.value(0),linesplit.value(1));

           //   datalist1.append(new Object(linesplit.value(0),linesplit.value(1)));





         }













}
QString DataStore::showpath(){
    return path;
}
QString DataStore::showname(){
    return storename;
}
QString DataStore::showtables(){
    return tables;
}
int DataStore:: showamountofitems(){
    return items;
}
QString DataStore:: showitemname(int thesi){
    return itemmap[thesi][0];
}
QString DataStore:: showitemprize(int thesi){
    return itemmap[thesi][1];
}
void DataStore:: append(QList <QObject*> store){

   store.append(new Object("s","10"));


}
QString DataStore::returnoverall(){
        QString str="";

//"Money Collected = "+income+"\n"+"Items sold= "+itemsold+"\n"+"Most sales item= "+mostsolditem()+"\n"+"Table with most income= "+mosttablesold() ;

    return str;
}


