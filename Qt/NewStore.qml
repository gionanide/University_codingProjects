import QtQuick 2.0
import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2
import my_object 1.0
Rectangle {
    property  ListModel nameModel
    property string  storenametext;
    property string  tablestext;
    ListModel{

      id:  rowmodel
    }
    Text{
        id:isedit
        visible: false;

    }
    ListModel{
        id:onworkmodel
    }
   ListModel{
       id:allitemsmodel
   }

Component{
    id:onwork
    OnWork{}
}

Component{
    id:edit
    EditItem{}
}
function confirmstore(){
    //nameModel.count!=0
    //datastore.isempty(storename.text.toString())
    //datastore.isint(tables.text.toString())
if(datastore.isint(tables.text.toString())&&
        !datastore.isempty(storename.text.toString())&&
        nameModel.count!=0){

        datastore.writestore(tables.text,storename.text)
    var i;
    for(i=0;i<datastore.showtables();i++){
      onworkmodel.append({"tablename":"Table "+(i+1)})
    }
    for(i=0;i<datastore.showamountofitems();i++){
        allitemsmodel.append({allitem:datastore.showitemname(i)+":"+datastore.showitemprize(i)})
    }
    rowmodel.append({rowtext:"Money collected 0"})
    rowmodel.append({rowtext:"Items sold 0"})
      stack.push(onwork,{rowmodel:rowmodel,allitemsmodel:allitemsmodel ,tableModel:onworkmodel});
  }
else{
 confirmmessageDialog.visible=true
}
}
MessageDialog {
    id: confirmmessageDialog
    title: "ERROR"
    text: "Please confirm only valid values"
    onAccepted: {


    }
    Component.onCompleted: visible = false
}
    visible:true
    id: rectangle

    width: Screen.width
    height: Screen.height
    color: "#6060df"


ToolBar{
    id:bar
    ToolButton{
        text:"Back"
        onClicked: stack.pop()
    }
}
    RowLayout {

        id: rowLayout
        x: parent.width/4
        anchors.top:bar.bottom

        width: parent.width/2
        height: parent.height/10

        Text {

            id: text1
            text: "Type the name of your store"
            font.pixelSize: 24
        }

        TextField{
            id:storename
            text:storenametext
            Layout.fillWidth: true
        }
    }
    RowLayout {

        id: rowLayout1
        x: parent.width/4
        anchors.top:rowLayout.bottom

        width: parent.width/2
        height: parent.height/10

        Text {

            id: text2
            text: "Type the amount of the tables"
            font.pixelSize: 24
        }

        TextField{
            id:tables
           text:tablestext
            Layout.fillWidth: true
        }
    }

    Button {
        id: addbutton
        x:rowLayout.x
        width: rowLayout.width/3
        height: rowLayout.height
        text: qsTr("Add Item")
        anchors.top: rowLayout1.bottom
        anchors.topMargin: 0
        onClicked:{

              isedit.text="false"
            stack.push(edit,{model:nameModel,name:" ",prize:" ",isedit:isedit})

}
        font.pixelSize: 24
    }
    Button {
        id: delbutton
        width: 186
        anchors.left: addbutton.right

        height: rowLayout.height
        text: qsTr("Delete Item")
        anchors.leftMargin: rowLayout.width/3
        leftPadding: 8
        anchors.top: rowLayout1.bottom
        anchors.topMargin: 0
        onClicked:{
               if(datastore.showamountofitems()>0){
              datastore.deleteitem(grid.currentIndex)
              nameModel.remove(grid.currentIndex)
               }

}
        font.pixelSize: 24
    }

    Button{
       anchors.top: addbutton.bottom
       x:rowLayout.x
       id:confirmbutton
       text: "Confirm store"
       anchors.topMargin: 10
       width:rowLayout.width
       height: rowLayout.height
       onClicked: {
           confirmstore()
       }
       font.pixelSize: 24
    }

    GridView
    {

        id:grid
        anchors.rightMargin:parent.width/6
        anchors.bottomMargin: -57
        anchors.leftMargin: parent.width/6
        cellHeight:50
        cellWidth: rowLayout.width


        anchors.topMargin: parent.height/2



        anchors.fill   :   parent
        model  :    nameModel
        delegate   :    nameDelegate
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
            id:mypath
            startX: 0; startY: 0
            PathQuad { x: 500; y: 0; controlX: 250; controlY: 250}
        }


    }
    Component
    {

        id    :    nameDelegate
        RowLayout
        {

            Text   {
                horizontalAlignment: Text.AlignLeft
                Layout.fillHeight: true
                Layout.fillWidth: true
                id    :    itemname
                text        :    "Item Name:";
                font.pixelSize   :   24
            }
            TextField{
                horizontalAlignment: Text.AlignLeft
                Layout.fillHeight: true
                Layout.fillWidth: true
                id:itemnameedit
                text: name
                font.pixelSize   :   24

            }
            Text   {
                Layout.fillHeight: true
                Layout.fillWidth: true
                id    :    itemprize
                text        :   "Prize:";
                font.pixelSize   :   24
            }
            TextField{
                horizontalAlignment: Text.AlignLeft
                Layout.fillHeight: true
                Layout.fillWidth: true
                id:itemprizeedit
                text: prize
                font.pixelSize   :   24
            }


            MouseArea
            {

                anchors.fill: parent
                onClicked: {

                    grid.currentIndex=index
                }
                onDoubleClicked: {
                     isedit.text="true"
                     stack.push(edit,{model:nameModel,name:itemnameedit,prize:itemprizeedit,isedit :isedit})
                  //  nameModel.remove(grid.currentIndex)
                }
            }

        }

    }





    }








