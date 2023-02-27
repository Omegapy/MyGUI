///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program Buttons               *        MenuR Class Declarations      *                                 |
|                                *                                      *                                 |
---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

    The MenuR class creates static-size menu objects,
    window-resized-not-responsive menus.
    The MenuR objects consist of rectangle shaped bars.

    The menu object can contain one menu bar or several menu bars,
    the menu can be automatically positioned on the left, center, or right side of the screen.
    See mutators to modify the menu position.

    The bars’ sizes are computed from the font size and length of the bar with the longest text;
    the texts can be positioned on the left, center, or right side of the bars.

    The bars’ borders can be turned on and off.
    The sizes of the borders are computed from the font size and length of the bar with the longest text;
    modifying the bars’ sizes will also modify the borders’ sizes.

    The button's shadows can be turned on and off.
    The sizes of the shadows are computed from the font size and length of the bar with the longest text;
    modifying the bars’ sizes will also modify the shadows’ sizes.

    The default font is raylib font.

    The menu bars untilize the ButtonR class

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
#include "enums.hpp"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------- Class MenuR ---------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    float txtMargine = 10; // text margine left and right 
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
    MenuR(vector<string> &texts);

    /*------------------------------------------------------------

        Constructor-2
        - raylib default font
        texts, menu position

        CENTER, CENTER_TOP, CENTER_BOTTOM, 
        LEFT, LEFT_TOP, LEFT_BOTTOM, 
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

     -------------------------------------------------------------*/
    MenuR(vector<string> &texts, unsigned menuPos);

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
    MenuR(vector<string> &texts, unsigned menuPos, unsigned textsPos);

    /*---------------------------------------------------

        Constructor-4
        texts, font

     ----------------------------------------------------*/
    MenuR(vector<string> &texts, Font &font, float fontSize);

    /*---------------------------------------------------

        Constructor-5
        - raylib default font
        texts, menu position, font size

        menu position:
        CENTER, CENTER_TOP, CENTER_BOTTOM,
        LEFT, LEFT_TOP, LEFT_BOTTOM,
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

     ----------------------------------------------------*/
    MenuR(vector<string> &texts, unsigned menuPos, Font &font, float fontSize);

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
    MenuR(vector<string> &texts, unsigned menuPos, unsigned textsPos, Font &font, float fontSize);

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Accessors Methods
    //----------------------------------------------------------------------------------

    /*----------------------------------------------------

        draw bars
        Not inherited by child classes

     -----------------------------------------------------*/
    void virtual draw();


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Mutators Methods
    //---------------------------------------------------------------------------------


    /*----------------------------------------------------------

        Builds the Menu,
        computes size from the font size and length of the texts

     -----------------------------------------------------------*/
    void buildMenu();

    //---------------------------------------------------------------------------------- Menu 

    /*----------------------------------------------------------

        Sets menu position

        menu position:
        CENTER, CENTER_TOP, CENTER_BOTTOM,
        LEFT, LEFT_TOP, LEFT_BOTTOM,
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

     -----------------------------------------------------------*/
    void setMenuPosition(unsigned menuPos);

    /*----------------------------------------------------------

        Sets Bar spacing

     -----------------------------------------------------------*/
    void setBarSpacing(float barSpacing);

    //---------------------------------------------------------------------------------- Bar

    /*----------------------------------------------------------

        Sets bars color

     -----------------------------------------------------------*/
    void setBarsColorIdle(vector<Color> barsIdle);

    /*----------------------------------------------------------

        Sets bars color pressed

     -----------------------------------------------------------*/
    void setBarsColorPressed(vector<Color> barsPressed);

    /*----------------------------------------------------------

        Sets bars color hover

     -----------------------------------------------------------*/
    void setBarsColorHover(vector<Color> barsHover);

    /*----------------------------------------------------

        Sets sizes of the bars,
        does not resise fonts

     -----------------------------------------------------*/
    void setBarsSize(float barWidth, float barHeight);

    //---------------------------------------------------------------------------------- Shadow

    /*----------------------------------------------------------

        Sets shadow true or false

     -----------------------------------------------------------*/
    void setShadow(bool isShadow);

    /*----------------------------------------------------------

        Sets shadow color

     -----------------------------------------------------------*/
    void setShadowsColor(Color shadowColor);

    /*----------------------------------------------------------

        Adds to shadow position relative to bars

     -----------------------------------------------------------*/
    void AddToShadowsPos(float AddToX, float AddToY);

    /*----------------------------------------------------------

      Add to shadow size 

    -----------------------------------------------------------*/
    void AddToShadowsSize(float AddToWidth, float AddToHeight);

    //---------------------------------------------------------------------------------- Border

    /*----------------------------------------------------------

       Sets border true or false

    -----------------------------------------------------------*/
    void setBorder(bool isBorder);

    /*----------------------------------------------------------

        Sets border color

     -----------------------------------------------------------*/
    void setBordersColorIdle(vector<Color> bordersIdle);

    /*----------------------------------------------------------

        Sets border color pressed

     -----------------------------------------------------------*/
    void setBordersColorPressed(vector<Color> bordersPressed);

    /*----------------------------------------------------------

        Sets border color hover

     -----------------------------------------------------------*/
    void setBordersColorHover(vector<Color> bordersHover);

    /*----------------------------------------------------------

        Sets border thickness

     -----------------------------------------------------------*/
    void setBordersThickness(float borderThickness);


    //---------------------------------------------------------------------------------- Text and font

    /*----------------------------------------------------

        Sets font and
        Resizes button to fit text
        isRayFont = false;

     -----------------------------------------------------*/
    void setFont(Font font);

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
    void setTxtPosition(unsigned textsPos);

    /*----------------------------------------------------------

        Sets fonts color

     -----------------------------------------------------------*/
    void setFontsColor(vector<Color> fontsColor);

private:

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Classe Operation Functions (private)
    //---------------------------------------------------------------------------------

};

#endif