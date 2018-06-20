import QtQuick 2.0
import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2

Rectangle{
   property  ListModel model
    property TextField name
    property TextField prize
width:Screen.width
height:Screen.height
    id: rectangle
visible:true

    color: "#6060df"
    MessageDialog {
        id: confirmmessageDialogWrongValues
        title: "ERROR"
        text: "Please confirm only valid values"
        onAccepted: {


        }
        Component.onCompleted: visible = false
    }
    MessageDialog {
        id: confirmmessageDialogNameExists
        title: "ERROR"
        text: "An item with this name already exists"
        onAccepted: {


        }
        Component.onCompleted: visible = false
    }
    ToolBar{
        id:bar
        ToolButton{
            text:"Back"
            onClicked: {
                if(!datastore.isempty(itemnameedit.text)&&datastore.isdouble(itemprizeedit.text)
         ){
                if(isedit.text=="false"){
                    if(datastore.finditem(itemnameedit.text)==-1){

               model.append({name:itemnameedit.text,prize:itemprizeedit.text})
               datastore.additem(itemnameedit.text,itemprizeedit.text)

                    stack.pop()
                    }
                    else{
                        confirmmessageDialogNameExists.visible=true
                    }
                }
                else{

           datastore.updateitem(itemnameedit.text,itemprizeedit.text,datastore.finditem(name.text))
                    name.text=itemnameedit.text
                    prize.text=itemprizeedit.text
                    stack.pop();
                }


                }
                else{


                  confirmmessageDialogWrongValues.visible=true

                }
            }
        }
    }

    RowLayout{
        x:parent.width/3
        anchors.top:bar.bottom
        anchors.topMargin: 30
        id:row1
    Text   {

        horizontalAlignment: Text.AlignLeft
        Layout.fillHeight: true
        Layout.fillWidth: true
        id    :    itemname
        text        :    "Item Name:";
        font.pixelSize   :   50
    }
    TextField{
        horizontalAlignment: Text.AlignLeft
        Layout.fillHeight: true
        Layout.fillWidth: true
        id:itemnameedit
        text: name.text
        font.pixelSize   :   50

    }
    }
    RowLayout{
        anchors.topMargin: 30
        x:parent.width/3
         anchors.top:row1.bottom
         id:row2
    Text   {
        Layout.fillHeight: true
        Layout.fillWidth: true
        id    :    itemprize
        text        :   "Prize:";
        font.pixelSize   :   50
    }
    TextField{
        horizontalAlignment: Text.AlignLeft
        Layout.fillHeight: true
        Layout.fillWidth: true
        id:itemprizeedit
        text: prize.text
        font.pixelSize   :   50
    }
      }


}

