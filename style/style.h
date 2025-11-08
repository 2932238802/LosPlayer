#pragma once

#include<QString>


inline const QString GLOBAL_STYLE_SHEET = R"(
    * {
        color: black;
    }

    #background {
        background-color: #F5F5F5;
        border-radius: 10px;
    }

    #logo {
        background-color: #F0F0F0;
    }

    #searchEdit {
        background-color: #E3E3E3;
        border: none;
        border-radius: 10px;
        padding: 7px;
    }


    #setting QPushButton {
        border: none;
        background-color: rgb(129, 216, 207);
    }
    #setting QPushButton:hover {
        background-color: rgb(159, 246, 237);
    }

    BtFrom {

        background-color: #F5F5F5;
        border: 2px solid #F5F5F5;
        border-radius: 8px;
    }

    BtFrom QLabel
    {
        color: #DD7E81;
    }

    #line_1{
        background-color: #D9BCD6
    }
    #line_2{
        background-color: #D9BCD6
    }
    #line_3{
        background-color: #D9BCD6
    }
    #line_4{
        background-color: #D9BCD6
    }

    BtFrom:hover {
        background-color: #E0E0E0;
        border: 2px solid rgb(85, 255, 255);
    }


    BtFrom[clicked="true"] {
        background-color: #000000;
        border: 2px solid rgb(85, 255, 255);
    }
)";


inline const QString COMMAND_PAGE_STYLE = R"(
    #scrollAreaWidgetContentsForRecommandPage{
        background-color: white;
    }
)";


inline const QString RECBOX_BTN = R"(
    #leftBtn{
        border:none;
        background-color: #2E3A1F;
    }

    #leftBtn:hover{
        border:none;
        background-color: #87843b;
    }

    #rightBtn{
        border:none;
        background-color: #2E3A1F;
    }
    #rightBtn:hover{
        border:none;
        background-color: #87843b;
    }
)";








