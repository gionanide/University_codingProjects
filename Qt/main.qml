import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.10

Window {
     title: "MY STORE"
    visible: true
    width: Screen.width
    height:Screen.height
    color: "#6060df"


    Component
    {
        id:start;
        SelectStore{}
    }
    StackView{
        initialItem: start
        id:stack
        focus: true
      /*
  Keys.onReleased:   if (event.matches(StandardKey.Back)) {
                               stack.pop();
                               event.accepted = true;
                           }
                           */
        Keys.onReleased: {
            if (event.key == Qt.Key_Back) {

                stack.pop()
                event.accepted = true
            }
        }

    }



}
