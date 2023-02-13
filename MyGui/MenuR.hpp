///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program Buttons               *        MenuR Class Declarations      *                                 |
|                                *                                      *                                 |
---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

    The MenuR class creates rectangle-shaped static-size menu objects,
    window-resized-not-responsive menus.

    The menu object can contain one menu bar or several menu bars,
    the menu can be automatically positioned on the left, center, or right side of the screen.
    See mutators to modify the menu position.

    The bars’ sizes are computed from the font size and length of the text longest bar text;
    the texts can be positioned on the left, center, or right side of the bars.
    See mutators to modify each individual bar position, the text’s position in each individual bar, 
    and the each individual bar’s size.

    The bars’ borders can be turned on and off.
    The sizes of the borders are computed from the font size and length of the bar text longest;
    modifying the bars’ sizes will also modify the borders’ sizes.

    The button's shadows can be turned on and off.
    The sizes of the shadows are computed from the font size and length of the bar text longest;
    modifying the bars’ sizes will also modify the shadows’ sizes.

    The default font is raylib font.

    The menu bars are created untilizing the ButtonR class

    Requirement
    c and c++ 20 or later
    Raylib library: https://www.raylib.com
    ButtonR Class

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MENU_R_HPP
#define MENU_R_HPP

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "ButtonR.hpp"

// Menu position
const enum MENU_POSITION { CENTER = 0, CENTER_TOP, CENTER_BOTTOM, LEFT, LEFT_TOP, LEFT_BOTTOM, RIGHT, RIGHT_TOP, RIGHT_BOTTOM, NONE };
// Texts postion in bars
const enum TEXT_POSITION { TXT_CENTER = 0, TXT_LEFT, TXT_RIGHT, TXT_NONE };


class MenuR 
{
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // variables (Private)
    //----------------------------------------------------------------------------------




public:

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // variables (Public)
    //----------------------------------------------------------------------------------
    
    //---- Menu
    float menuWidth = 0.0f,
          menuHeight = 0.0f,
          menuX = 0.0f,
          menuY = 0.0f;

    // Menu position
    unsigned menuPos = LEFT;

    //---- Menu bars
    unsigned numBars = 0;
    vector<ButtonR> bars;
    float barSpacing = 50.0f,
          barsHeight = 0.0f,
          barsWidth = 0.0f;
    
    //---- Menu texts
    vector<string> texts;
    // Texts postion in bars
    unsigned textsPos = TXT_LEFT;
    // font
    Font font;
    float fontSize = 0.0f;
    bool isRayFont = true;
    bool isTxtMod = false;

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Constructors
    //---------------------------------------------------------------------------------


    /*---------------------------------------------------

        Default construtor 
        - raylib default font

     ----------------------------------------------------*/
    MenuR();

    /*---------------------------------------------------

        Constructor-1
        - raylib default font
        texts

     ----------------------------------------------------*/
    MenuR(vector<string> texts);

    /*------------------------------------------------------------

        Constructor-2
        - raylib default font
        texts, menu position

        CENTER, CENTER_TOP, CENTER_BOTTOM, 
        LEFT, LEFT_TOP, LEFT_BOTTOM, 
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

     -------------------------------------------------------------*/
    MenuR(vector<string> texts, unsigned menuPos);

    /*---------------------------------------------------

        Constructor-3
        - raylib default font
        texts, menu position, texts position

        menu position:
        CENTER, CENTER_TOP, CENTER_BOTTOM,
        LEFT, LEFT_TOP, LEFT_BOTTOM,
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

        texts position:
        TXT_CENTER, TXT_LEFT, TXT_RIGHT

     ----------------------------------------------------*/
    MenuR(vector<string> texts, unsigned menuPos, unsigned textsPos);

    /*---------------------------------------------------

        Constructor-4
        texts, font

     ----------------------------------------------------*/
    MenuR(vector<string> texts, Font &font, float fontSize);

    /*---------------------------------------------------

        Constructor-5
        - raylib default font
        texts, menu position, font size

        menu position:
        CENTER, CENTER_TOP, CENTER_BOTTOM,
        LEFT, LEFT_TOP, LEFT_BOTTOM,
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

     ----------------------------------------------------*/
    MenuR(vector<string> texts, unsigned menuPos, Font &font, float fontSize);

    /*---------------------------------------------------

        constructor-6
        - raylib default font
        texts, menu position, font size

        menu position:
        CENTER, CENTER_TOP, CENTER_BOTTOM,
        LEFT, LEFT_TOP, LEFT_BOTTOM,
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

        texts position:
        TXT_CENTER, TXT_LEFT, TXT_RIGHT

     ----------------------------------------------------*/
    MenuR(vector<string> texts, unsigned menuPos, unsigned textsPos, Font &font, float fontSize);

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Accessors Methods
    //----------------------------------------------------------------------------------

    /*----------------------------------------------------

        draw button
        Not inherited by child classes

     -----------------------------------------------------*/
    void draw();


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Mutators Methods
    //---------------------------------------------------------------------------------


    /*----------------------------------------------------------

        Builds the Menu,
        computes size from the font size and length of the texts

     -----------------------------------------------------------*/
    void buildMenu();

    //---------------------------------------------------------------------------------- Shadow

    /*----------------------------------------------------------

        Sets shadow true or false

     -----------------------------------------------------------*/
    void setShadow(bool isShadow);

    /*----------------------------------------------------------

        Sets shadow color

     -----------------------------------------------------------*/
    void setShadowColor(Color shadowColor);


    //---------------------------------------------------------------------------------- Boder

    /*----------------------------------------------------------

       Sets border true or false

    -----------------------------------------------------------*/
    void setBorder(bool isBorder);

    /*----------------------------------------------------------

        Sets border color

     -----------------------------------------------------------*/
    void setBorderColorIdle(Color borderIdle);

    /*----------------------------------------------------------

        Sets border color pressed

     -----------------------------------------------------------*/
    void setBorderColorPressed(Color borderPressed);

    /*----------------------------------------------------------

        Sets border color hover

     -----------------------------------------------------------*/
    void setBorderColorHover(Color borderHover);

    /*----------------------------------------------------------

        Sets border thickness

     -----------------------------------------------------------*/
    void setBorderThickness(float borderThickness);

    //---------------------------------------------------------------------------------- Button rect.

    /*----------------------------------------------------------

        Sets button color

     -----------------------------------------------------------*/
    void setBtnColorIdle(Color btnIdle);

    /*----------------------------------------------------------

        Sets button color pressed

     -----------------------------------------------------------*/
    void setBtnColorPressed(Color btnPressed);

    /*----------------------------------------------------------

        Sets button color hover

     -----------------------------------------------------------*/
    void setBtnColorHover(Color btnHover);

    //---------------------------------------------------------------------------------- Text

    /*----------------------------------------------------

         Sets font size and
         Resizes menu bars to fit text

     -----------------------------------------------------*/
    void setFontSize(float fontSize);

    /*----------------------------------------------------

         Sets font size and
         does NOT resizes bars to fit text

     -----------------------------------------------------*/
    void setFontSizeNoResize(float fontSize);

    /*----------------------------------------------------

         Sets text to a bar and
         if need it,
         resizes the bar and the menu lenght to fit text
         but not the heights.

         the bars indexes start at 0

     -----------------------------------------------------*/
    void setTextBar(string text, unsigned barIndex);

    /*----------------------------------------------------------

        Sets texts possition

        texts position:
        TXT_CENTER, TXT_LEFT, TXT_RIGHT

     -----------------------------------------------------------*/
    void MenuR::setTxtPosition(unsigned textsPos);

    /*----------------------------------------------------------

        Sets menu position

        menu position:
        CENTER, CENTER_TOP, CENTER_BOTTOM,
        LEFT, LEFT_TOP, LEFT_BOTTOM,
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

     -----------------------------------------------------------*/
    void setMenuPosition(unsigned menuPos);



private:

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Classe Operation Functions (private)
    //---------------------------------------------------------------------------------

};

#endif