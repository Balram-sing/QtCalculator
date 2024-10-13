import QtQuick 2.6
import QtQuick.Window 2.2

import CalculatorModel 1.0

Window {
    // ID
    id: mainWindow
    // Visibility
    visible: true
    // Size
    minimumWidth: 480
    maximumWidth: 480
    minimumHeight: 400
    maximumHeight: 400
    // Title
    title: qsTr("Calculator")
    // Keyboard-Control
    Item {

        id: keyboardInputArea
        width: mainWindow.width
        height: mainWindow.height
        focus: true

        // Key-Input
        Keys.onReleased:
        {

            // Deubg-log
           // console.log( "Key pressed #" + event.text );

            // Logic
            if ( event.key === Qt.Key_Enter )
                resultText.text = logic.doMath( );
            else if ( event.key === Qt.Key_Plus )
                resultText.text = logic.setOperationType( "+" )
            else if ( event.key === Qt.Key_Minus )
                resultText.text = logic.setOperationType( "-" )
            else if ( event.text === "/" ) // Can be replaced with key-code.
                resultText.text = logic.setOperationType( "/" )
            else if ( event.text === "*" ) /// Numpad multiply-key not respond.
                resultText.text = logic.setOperationType( "*" )
            else if ( event.text === "." )
                resultText.text = logic.onDot( );
            else if ( event.text === "," )
                resultText.text = logic.onDot( );
            else
                resultText.text = logic.onKeyboardInput( event.text );

            // Mark Event as handled.
            event.accepted = true;

        } // Keys.onReleased

    } // Keyboard-Control

    // Logic
    CalculatorModel {
        id: logic
    }

    // Style-Model
    Style
    {
        id: guiStyle
    }

    // State-Machine

    // GUI
    Rectangle {
        // ID
        id: resultBox
        // Anchors
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        // Size
        //width: parent.width // Not required, because anchors left & right are set.
        height: 46
        //height: ( ( parent.height * 3 ) / 32 ) + 10 // (1/3 + 10px of Window-Height)
        // Border
        border.color: "white"
        border.width: 1
        // Color
       // color: "#46a2da"
color: "black"
        // Result-Text (Label)
        Text {
            // ID
            id: resultText
            // Anchors
            anchors.leftMargin: customButtons.implicitMargin
            anchors.rightMargin: customButtons.implicitMargin
            anchors.fill: parent
            // Text-Alignment
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
            // Default-Text
            text: qsTr( "0" )
            // Background-Color
            color: "white"
            // Text0Size
            font.pixelSize: 32
            // Font-Style
           // font.family: "Open Sans Regular"
            // Text Size-Mode
            fontSizeMode: Text.Fit
        }
    }

    // CustomButtons
    Item {
        // ID
        id: customButtons
        // Anchors
        anchors.top: resultBox.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        // MC
        CustomButton {
            x: guiStyle.margin
            y: 4
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            textHeight: 32
            id: mc_Btn
            text: "MC"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                logic.resetMemory( );
            } // onClicked
        }
        // MR
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 1 * ( width + guiStyle.margin ) )
            y: 4
            textHeight: 32
            id: mr_Btn
            text: "MR"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onMR( );
            } // onClicked
        }
        // MS
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 2 * ( width + guiStyle.margin ) )
            y: 4
            textHeight: 32
            id: ms_Btn
            text: "MS"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                logic.onMS( );
            } // onClicked
        }
        // C
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 3 * ( width + guiStyle.margin ) )
            y: 4
            textHeight: 32
            id: clear_Btn
            text: "C"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                logic.resetLogic( );
                resultText.text = "0";
            } // onClicked
        }
        // Erase
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 4 * ( width + guiStyle.margin ) )
            y: 4
            textHeight: 32
            id: erase_Btn
            text: "<"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onRemoveLastNumber( );
            } // onClicked
        }
        // 7
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 0 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 1 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_7
            text: "7"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onNumberInput( "7" );
            } // onClicked
        }
        // 8
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 1 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 1 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_8
            text: "8"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onNumberInput( "8" );
            } // onClicked
        }
        // 9
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 2 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 1 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_9
            text: "9"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onNumberInput( "9" );
            } // onClicked
        }
        // +
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 3 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 1 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_sum
            text: "+"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.setOperationType( "+" );
            } // onClicked
        }
        // -
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 4 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 1 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_sub
            text: "-"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.setOperationType( "-" );
            } // onClicked
        }
        // 4
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 0 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 2 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_4
            text: "4"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onNumberInput( "4" );
            } // onClicked
        }
        // 5
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 1 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 2 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_5
            text: "5"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onNumberInput( "5" );
            } // onClicked
        }
        // 6
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 2 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 2 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_6
            text: "6"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onNumberInput( "6" );
            } // onClicked
        }
        // / (÷)
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 3 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 2 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_div
            text: "÷"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.setOperationType( "/" );
            } // onClicked
        }
        // * (×)
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 4 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 2 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_mult
            text: "×"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.setOperationType( "*" );
            } // onClicked
        }
        // 1
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 0 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 3 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_1
            text: "1"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onNumberInput( "1" );
            } // onClicked
        }
        // 2
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 1 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 3 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_2
            text: "2"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onNumberInput( "2" );
            } // onClicked
        }
        // 3
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 2 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 3 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_3
            text: "3"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onNumberInput( "3" );
            } // onClicked
        }
        // sqrt
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 3 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 3 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_sqrt
            text: "√"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.setOperationType( "sqrt" );
            } // onClicked
        }
        // =
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 4 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 3 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_result
            text: "="
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.doMath( );
            } // onClicked
        }
        // -.--- (dot, separator)
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 0 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 4 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_dot
            text: "."
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onDot( );
            } // onClicked
        }
        // --0--
        CustomButton {
            width: guiStyle.btnWidth
            height: guiStyle.btnHeight
            x: guiStyle.margin + ( 1 * ( width + guiStyle.margin ) )
            y: guiStyle.margin + ( 4 * ( height + guiStyle.margin ) )
            textHeight: 32
            id: btn_0
            text: "0"
            color: guiStyle.btnColor
            anchors.leftMargin: guiStyle.margin
            onClicked: {
                resultText.text = logic.onNumberInput( "0" );
            } // onClicked
        }
    }

} // Main Window
