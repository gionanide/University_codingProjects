import QtQuick 2.0
import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2

Rectangle {

    Component{
        id:tableedit
        EditTable{}
    }

   ListModel{
   id: pressedmodel
   }
   property ListModel allitemsmodel
    property ListModel tableModel
   property ListModel rowmodel
   property string moneycollected
   property string itemsoldtext
    visible:true
    id: rectangle

    width: Screen.width
    height: Screen.height
    color: "#6060df"

    MessageDialog {
        id: endapp
        title: "Store's overall"
        // "Money Collected = "+datastore.showincome()+"\n"+"Items sold= "+datastore.showitemssold()+"\n"+"Most sales item= "+datastore.mostsolditem()+"\n"+"Table with most income= "+datastore.mosttablesold() ;
        text:""
        onAccepted: {

 Qt.quit()
        }
        Component.onCompleted: visible = false
    }
    Button{
        y:Screen.height/15
        x:Screen.width/5
        width:Screen.width*3/5
        height:Screen.height/10

        id:end

        text:"CLOSE STORE"
        onClicked: {
           // stack.pop()
           endapp.setText("Money Collected = "+datastore.showincome()+"\n"+"Items sold= "+datastore.showitemssold()+"\n"+"Most sales item= "+datastore.mostsolditem()+"\n"+"Table with most income= Table "+datastore.mosttablesold() );
endapp.visible=true;

        }
    }




        GridView
        {

            id:grid

            anchors.rightMargin: parent.width/10
            anchors.bottomMargin: 0
            anchors.leftMargin: parent.width/10
            cellHeight:100
            cellWidth: grid.width

              anchors.topMargin: parent.height/3



            anchors.fill   :   rectangle
            model:tableModel
            delegate   :    tableDelegate
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


    Component{
        id:tableDelegate
        RowLayout{

            Text{

                horizontalAlignment: Text.AlignLeft
                Layout.fillHeight: true
                Layout.fillWidth: true
                text:tablename
             //   font.pixelSize: 100
                width: grid.cellWidth
                height: grid.cellHeight
            }
            MouseArea
            {

                anchors.fill: parent
                onClicked: {

                    grid.currentIndex=index
                }
                onDoubleClicked: {
                    var i;
                    var j=pressedmodel.count
                    for(i=0;i<=j;i++)
                    {
                        pressedmodel.remove(0);
                    }

                    for(i=0;i<datastore.showcurrenttableitems(grid.currentIndex);i++){
                        pressedmodel.append({currentitem:datastore.currentitemname(grid.currentIndex,i)+":"+
                                                         datastore.currentitemprize(grid.currentIndex,i)})
                    }

                    stack.push(tableedit,{rowmodel:rowmodel,tablenumber:(grid.currentIndex),currentitemModel:pressedmodel ,allitemModel:allitemsmodel,s1:"Table "+(grid.currentIndex+1),s2:"Current bill: "+datastore.returncurrenttablebill(grid.currentIndex)})
                }
            }
        }
    }

    GridView {
        id: gridView
        x: parent.width/5
        y: parent.height/5
        width: parent.width*4/5
        height: parent.height/10
        cellWidth: width
        model: rowmodel
        cellHeight: 60
        delegate: rowdelegate
    }
    Component{
        id:rowdelegate
        RowLayout{

            Text{

                horizontalAlignment: Text.AlignLeft
                Layout.fillHeight: true
                Layout.fillWidth: true
                text:rowtext
                font.pixelSize: 60
            }
        }
    }
}
