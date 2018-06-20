
import QtQuick 2.0
import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2
Rectangle {
    property int tablenumber
    property string s1
    property string s2
    property ListModel allitemModel
    property ListModel currentitemModel
    property ListModel rowmodel

    visible:true
    id: rectangle

    width: Screen.width
    height: Screen.height
    color: "#6060df"



    Button{
        x:parent.width/3
        id:end
        width: parent.width/3
        height: parent.height/15
        anchors.topMargin: parent.height/10
        text:"END TABLE"
        onClicked: {

            var i;
            for(i=0;i<2;i++){
                rowmodel.remove(0)
            }

            datastore.addincome(datastore.returncurrenttablebill(tablenumber))

                rowmodel.append({rowtext:"Money collected "+datastore.showincome()})
            datastore.additemsold(datastore.showcurrenttableitems(tablenumber))

            rowmodel.append({rowtext:"Items sold "+datastore.showitemssold()})
             datastore.endtable(tablenumber);


            stack.pop()

           // stack.push(endt,{moneycollected:datastore.showincome(),itemsoldtext:datastore.showitemssold()});
        }

    }

    RowLayout{

        width: 7*parent.width/12
        height: parent.height/6
 id:row
        x:parent.width*1/6
        anchors.top:end.bottom
        anchors.topMargin: parent.height/10

     Text{
         horizontalAlignment: Text.AlignLeft
         Layout.fillHeight: true
         Layout.fillWidth: true
         id:name
         text:s1
         font.pixelSize: 50
     }
     Text{
         horizontalAlignment: Text.AlignRight
         Layout.fillHeight: true
         Layout.fillWidth: true
         id:currentmoney
         text:s2
         font.pixelSize: 50
     }
    }
    Pane{
        id:pane1
        x:0
        anchors.top:row.bottom
        width: parent.width*3/7
        height: parent.height/15
        anchors.topMargin: parent.height/10
    Text{

anchors.centerIn: parent
    font.pixelSize: 35



        text:"All items"
    }
    }
    Pane{
        id:pane2
        x:parent.width*4/7
        anchors.top:row.bottom
        width: parent.width*3/7
        height: parent.height/15
      anchors.topMargin: parent.height/10
    Text{
        anchors.centerIn: parent

        font.pixelSize: 35

        text:"Current Table Items"
    }
    }
    Button{
        x:parent.width*3/7
        anchors.top: row.bottom
        id:confirm
        width: parent.width*1/7
        height: parent.height/15
        anchors.topMargin: parent.height/10
        text:"Confirm"
           onClicked: {
               stack.pop()
           }
           font.pixelSize: 35
    }
    GridView
    {

        id:grid

        anchors.rightMargin: parent.width*4/7
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        cellHeight:70
        cellWidth: parent.width


        anchors.topMargin: parent.height/2


        anchors.fill   :   rectangle
        model:allitemModel
        delegate   :   allitemDelegate
        clip    :    false



        header: Rectangle
        {
            width:parent.width;
            height:10
            color:"pink"
        }
        footer:
            Rectangle
        {
            width:parent.width
            height:10
            color:"lightblue"
        }
        highlight:Rectangle{
            width:parent.width
            color:"lightgray"
        }
        focus:true

        Path
        {
            id:mypath
            startX: 0; startY: 0
            PathQuad { x: 500; y: 0; controlX: 250; controlY: 250}
        }
    }
    Component{
        id: allitemDelegate
        RowLayout{

        Text{
          id:t
            horizontalAlignment: Text.AlignLeft
            Layout.fillHeight: true
            Layout.fillWidth: true
            text:allitem
        //    font.pixelSize: 70
            width: grid.width
            height:grid.cellHeight
        }
        MouseArea
        {

            anchors.fill: parent
            onClicked: {

                grid.currentIndex=index
            }
            onDoubleClicked: {
                 currentitemModel.append({currentitem:t.text});
                datastore.addcurrentitem(tablenumber,t.text);
           currentmoney.text="Current bill: "+datastore.returncurrenttablebill(tablenumber);
            }
        }
        }
    }
    GridView
    {

        id:grid2

        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: parent.width*4/7
        cellHeight:70
        cellWidth: parent.width

        anchors.topMargin: parent.height/2



        anchors.fill   :   rectangle

        model:currentitemModel
        delegate   :    currentitemDelegate
        clip    :    false



        header: Rectangle
        {
            width:parent.width;
            height:10
            color:"pink"
        }
        footer:
            Rectangle
        {
            width:parent.width;
            height:10
            color:"lightblue"
        }
        highlight:Rectangle{
            width:parent.width
            color:"lightgray"
        }
        focus:true

        Path
        {
            id:mypath2
            startX: 0; startY: 0
            PathQuad { x: 500; y: 0; controlX: 250; controlY: 250}
        }
    }
    Component{
        id: currentitemDelegate
        RowLayout{

        Text{

            horizontalAlignment: Text.AlignLeft
            Layout.fillHeight: true
            Layout.fillWidth: true
            text:currentitem
            //font.pixelSize: 70
            width: grid.width
            height:grid.cellHeight
        }
        MouseArea
        {

            anchors.fill: parent
            onClicked: {

                grid2.currentIndex=index
            }
            onDoubleClicked: {

                datastore.removecurrentitem(tablenumber,grid2.currentIndex);
                currentmoney.text="Current bill: "+datastore.returncurrenttablebill(tablenumber);
                currentitemModel.remove(grid2.currentIndex);
            }
        }
        }
    }
}
