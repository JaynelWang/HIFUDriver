import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.0

ApplicationWindow {
//    title: qsTr("Login")
    id: login_gui
    width: 400
    height: 500
    visible: true
//    flags: Qt.Desktop
    SystemPalette { id: activePalette }

    property int colorFlag : 0
    property alias titleFillColor : top_bar.color
    property alias loginFillColor : rect1.color
    property alias userNameFillColor : username_text.color
    property alias userNameLabelColor : userNameLabel.color
    property alias userNameTextColor: username_text.textColor
    property alias pwFillColor : pw_text.color
    property alias pwLabelColor : pwLabel.color
    property alias pwTextColor : pw_text.textColor

    signal btnLoginClicked(string name,string pw)
    signal shutLoginQml()
    signal authorize()

    //Title
    Rectangle{
        id: top_bar
        width: login_gui.width
        height: login_gui.height * 0.05
        anchors{top:login_gui.top}

        Text
        {
            id: title
            anchors{horizontalCenter: parent.horizontalCenter;verticalCenter: parent.verticalCenter}
            text: "USgHIFU System"
            font.bold: true
            font.family: "Times New Roman"
            font.pointSize: login_gui.height * 0.05 * 0.7
        }
    }

    //ProgressBar
    ProgressBar {
        id:progressBar
        width: login_gui.width
        height: login_gui.height * 0.05
        anchors{top:top_bar.bottom}
        indeterminate: true
        }

    //Logo
    Item
    {
        id: logo_bar
        width: login_gui.width
        height: login_gui.height * 0.3
        anchors.top: progressBar.bottom

        Image
        {
            id: logo
            source: "logo.jpg"
            anchors.fill: parent
            fillMode: Image.Stretch
        }
    }

    //Login
    Rectangle
    {
        id: rect1
        width: login_gui.width * 0.95
        height: login_gui.height * 0.54
        anchors { top: logo_bar.bottom; horizontalCenter: parent.horizontalCenter }
        border.color: "#707070"

        //username
        Item
        {
            id: static_text1
            width: rect1.width * 0.9
            height: rect1.height / 6
            anchors { left: rect1.left; leftMargin: rect1.width*0.1; top: rect1.top; horizontalCenter: parent.horizontalCenter}

            Text
            {
                id:userNameLabel
                anchors {bottom:parent.bottom}
                text: "UserName "
                font.bold: true
                font.family: "Times New Roman"
                font.pointSize: login_gui.height * 0.04 * 0.7
                color: "black"
            }
        }

        LineInput
        {
            id: username_text
            width: rect1.width * 0.7
            height: rect1.height / 6
            anchors { left: rect1.left; leftMargin: rect1.width*0.1; top: static_text1.bottom; horizontalCenter: parent.horizontalCenter}
//            hint: "Please enter your user name"
            text:"jx"
            focus: true
            KeyNavigation.tab:pw_text
        }

        //password
        Item
        {
            id: static_text2
            width: rect1.width * 0.9
            height: rect1.height * 0.15
            anchors { left: rect1.left; leftMargin: rect1.width*0.1; top: username_text.bottom; horizontalCenter: parent.horizontalCenter}

            Text
            {
                id:pwLabel
                anchors {bottom:parent.bottom}
                text: "Password"
                font.bold: true
                font.family: "Times New Roman"
                font.pointSize: login_gui.height * 0.04 * 0.7
                color: "black"
            }
        }

        LineInput
        {
            id: pw_text
            width: rect1.width * 0.7
            height: rect1.height * 0.15
            anchors { left: rect1.left; leftMargin: rect1.width*0.1; top: static_text2.bottom; horizontalCenter: parent.horizontalCenter}
//            hint: "Please enter your password"
            text:"12345"
            echoMode: TextInput.Password
            onAccepted: login_req()
        }

        //Buttons
        MyButton
        {
            id: btn_login
            width: rect1.width * 0.25
            height: rect1.height * 0.15
            anchors { left: rect1.left; leftMargin: rect1.width*0.2; bottom: rect1.bottom; bottomMargin: rect1.height*0.1}
            text: "Sign in"
            onClicked: login_req()
        }

        MyButton
        {
            id: btn_signout
            width: rect1.width * 0.25
            height: rect1.height * 0.15
            anchors { left: btn_login.right; leftMargin: rect1.width*0.1; bottom: rect1.bottom; bottomMargin: rect1.height*0.1}
            text: "Sign out"
            onClicked: Qt.quit()
        }
    }

    statusBar: RowLayout{
        id:status_bar
        width: login_gui.width

        Text{
            id:status_left
            anchors{left:parent.left;verticalCenter: status_bar.verticalCenter}
        }
        Text{
            id:status_right
            anchors{left:status_left.right;leftMargin: login_gui.width * 0.5; verticalCenter: status_bar.verticalCenter}
        }
    }

    function login_req()
    {
        if (username_text.text == "")
        {
            status_right.text = "User name cannot be vacant!"
            return
        }

        if (pw_text.text == "")
        {
            status_right.text = "Password cannot be vacant!"
            return
        }

        btnLoginClicked(username_text.text,pw_text.text)
        return
    }

    function generateColor()
    {
        colorFlag = Math.round(Math.random())
        console.log(colorFlag)

        if(colorFlag)
        {
            titleFillColor = "#CDCDF5"
            loginFillColor = "white"
            userNameFillColor = "white"
            pwFillColor = "white"
//            btn_login.fillcolor = ""
//            btn_login.textColor = ""
//            btn_signout.fillColor = ""
//            btn_signout.textColor = ""
        }
        else
        {
            titleFillColor = "#FFFF00"
            loginFillColor = "black"
            userNameFillColor = "black"
            userNameLabelColor = "white"
            userNameTextColor = "white"
            pwFillColor = "black"
            pwLabelColor = "white"
            pwTextColor = "white"
            btn_login.fillColor = "black"
            btn_login.textColor = "white"
            btn_signout.fillColor = "black"
            btn_signout.textColor = "white"
        }
    }

    function showResultMsg(success,isAdmin)
    {
        if (success)
        {
            status_right.text = "Successful login."
            shutLoginQml()
            login_gui.close()
        }

        if (!success)
        {
            status_right.text = "Login failed."
        }

        if(!isAdmin)
            authorize()

        return
    }
}
