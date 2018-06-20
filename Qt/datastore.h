#ifndef DATASTORE_H
#define DATASTORE_H


#include <string>
#include <QObject>
#include <map>
#include <iterator>
#include <QFile>
#include <iostream>
#include <QObject>
#include <QList>
#include <object.h>
#include <QGuiApplication>
class DataStore : public QObject
{
    Q_OBJECT

public:
 explicit DataStore(QObject *parent = nullptr);
    QString tables;
    int items;
    QString storename;
    QString itemmap [1000][2] ;
    QString path;
     QString folder;
    QList <QObject*> datalist1;
    QString currentitems[1000][50][2];
    int currentitemsamount[1000];
    double income;
    int itemsold;
    double tablemoney[1000];
    int quantityofitemsold[1000];
public slots:


   bool isempty(QString  str);
   bool isdouble(QString str);
   bool isint(QString str);
   void additem(QString name,QString prize);
   void updateitem(QString newname,QString newprize,int thesi);
   void deleteitem(int thesi);
   int finditem(QString name );
   void writestore(QString tab,QString name);
   void readstore(QString filepath);
   QString showpath();
   QString showname();
   QString showtables();
   int showamountofitems();
   QString  showitemname(int thesi);
   QString  showitemprize(int thesi);
   void append(QList <QObject*> store );
   QString returnoverall();
   void groundzero(){
       items=0;
   }
   QString currentitemprize(int table,int thesi){
       return currentitems[table][thesi][1];
   }

   QString currentitemname(int table,int thesi){
        return currentitems[table][thesi][0];
   }
   void additemsold(int adder){

       itemsold=itemsold+adder;
   }
   void addincome(double inc){
       income=income+inc;
   }
   void addcurrentitem(int table,QString text){
       QStringList list=text.split(":");
       QString name=list.value(0);
       QString prize=list.value(1);
       currentitems[table][currentitemsamount[table]][0]=name;
       currentitems[table][currentitemsamount[table]][1]=prize;
       currentitemsamount[table]++;
   }
   void removecurrentitem(int table,int thesi){
       for(int i=thesi;i<items-1;i++){
           currentitems[table][i][0]= currentitems[table][i+1][0];
            currentitems[table][i][1]= currentitems[table][i+1][1];

       }
       currentitemsamount[table]--;
   }
   int showcurrenttableitems(int thesi){
       return currentitemsamount[thesi];
   }
   double showincome(){
       return income;

   }
   int showitemssold(){
       return itemsold;
   }
   double returncurrenttablebill(int table){
       double amount=0;
       for(int i=0;i<currentitemsamount[table];i++){
           amount=amount+currentitems[table][i][1].toDouble();
       }
       return amount;
   }
   void endtable(int table){

       int j=currentitemsamount[table];
       for(int i=0;i<j;i++){

           tablemoney[table]=tablemoney[table]+currentitems[table][0][1].toDouble();

           quantityofitemsold[finditem(currentitems[table][0][0])]++;
           removecurrentitem(table,0);
       }


   }
   QString mostsolditem(){
      int s=-1,max=-1;

      for(int i=0;i<items;i++){
          if(quantityofitemsold[i]>max){
              max=quantityofitemsold[i];
              s=i;
          }
      }
      return itemmap[s][0];
   }
   int mosttablesold(){
       int s=-1,max=-1;

       for(int i=0;i<items;i++){
           if(tablemoney[i]>max){
               max=tablemoney[i];
               s=i+1;
           }
       }

       return s;
    }


};

#endif // DATASTORE_H
