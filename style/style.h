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



/////////////////////////// -- commonPage
inline QString COMMON_PAGE_PLAYBTN = R"(
    #playBtn{
        border-radius: 5px;
        background-color: #8fb2c9;
    }

    #playBtn:hover
    {
        background-color: rgb(163,198,221);
    }
)";

inline QString COMMON_PAGE_TITLESTYLE = R"(
    #pageTitle{
        color: #000000;
        font-size: 16px;
        font-weight: bold;
        padding: 3px;
    }
)";

inline QString LIST_ITEM_VIP_LABEL = R"(
    #vipLabel{
        border: 1px solid #1ECD96;
        color: #1ECD96;
        border-radius: 2px;
    }
)";

inline QString LIST_ITEM_SQ_LABAL = R"(
    #sqLabel{
        border: 1px solid #FF6600;
        color: #FF6600;
        border-radius: 2px;
    }
)";

inline const QString LISTITEM_STYLE = R"(
    #ListItem{
        background-color: #FFFFFF;
    }


    #ListItem:hover{
        background-color: rgb(241,147,156);
    }
)";

inline const QString MUSIC_SLIDER = R"(
    #inLine{
        background-color: #EBEEF5;
    }
    #outLine{
        background-color: #1ECC94;
    }

)";


inline const QString  VOLUME_TOOL = R"(

    #volumeBox{
        background-color: #F5F5F5;
        border-radius: 5px;
        border: 2px solid #1d242b;
    }

    #slienceBtn{
        border: none;
    }

    #slienceBtn:hover{
        border: 2px solid #1d242b;
        background-color: #FFFFFF;
    }

    #inLine{
        background-color: #ECECEC;
    }

    #outLine{
        background-color: #1ECC94;
    }

    #sliderBtn{
        border: none;

        border-radius: 2px;
        background-color: #1ECC94;
    }

)";











