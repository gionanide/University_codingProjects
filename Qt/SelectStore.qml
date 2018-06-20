import QtQuick 2.0
import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2
import my_object 1.0


Rectangle {

ListModel {
    id:nameModel
}

function readfromdata(){


var i;
    for(i=0;i<datastore.showamountofitems();i++){
        nameModel.remove(0);
    }

    for(i=0;i<datastore.showamountofitems();i++){
        nameModel.append({name:datastore.showitemname(i),prize:datastore.showitemprize(i)});
    }


}
    color: "#6868c9"
id: rect
    width: Screen.width
   height: Screen.height

Component{
    id:tostore
    NewStore{}
 }
    FileDialog {
        id: fileDialog
        nameFilters: [""]//Txt files (*.txt)
        title: "Please choose a file"
        folder: shortcuts.documents
        selectFolder:false
        selectMultiple:false
        selectExisting:true
        onAccepted: {
            console.log(folder);


            datastore.readstore(fileDialog.fileUrls);
             readfromdata();

            stack.push(tostore,{storenametext:datastore.showname(),tablestext:datastore.showtables(),nameModel:nameModel});

            fileDialog.close();
        }
        onRejected: {
            fileDialog.close();
        }
        Component.onCompleted: visible = false
    }




ListModel{
  id:item
}
ListModel{
  id:store
}
    Text{
        id : header

        width:parent.width
        height: parent.height/10
        color: "#3b1616"
        text: "Create new Store or Select Existing"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

    }
        ToolBar{

           id : bar
        anchors.top: header.bottom

        anchors.left: parent.left
        anchors.right: parent.right


        RowLayout{
            clip: true
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0

            anchors.fill: parent

         ToolButton{
            Layout.alignment: Qt.AlignLeft
             text:"Create"
             id : create
            onClicked: {
                var i;
                    for(i=0;i<=datastore.showamountofitems();i++){
                        nameModel.remove(0);
                    }
               datastore.groundzero();
                stack.push(tostore,{storenametext:"",tablestext:"",nameModel:nameModel})
            }
         }
         ToolButton{
             Layout.alignment: Qt.AlignRight
             text:"Select"
             id :select
             onClicked: {
                 fileDialog.visible=true
             }
         }
        }



        }






}
