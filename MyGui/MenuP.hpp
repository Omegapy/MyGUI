///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program MyGui                 *       MenuP Class Declaration        *                                 |
|                                *                                      *                                 |
---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    
    The MenuP class creates responsive menu objects, from images.

    The menu object can contain one menu bar or several menu bars,
    the menu can be automatically positioned on the left, center, or right side of the screen.
    See mutators to modify the menu position.

    The bars’ sizes are computed from the font size and length of the bar with the longest text;
    the texts can be positioned on the left, center, or right side of the bars.

    The bars' shadows can be turned on and off. It is off by default.
    The sizes of the shadows are computed from the font size and length of the bar with the longest text;
    modifying the bars’ sizes will also modify the shadows’ sizes.
    
    The default font is raylib font.

    The menu bars untilize the ButtonP class

    Requirement
    c and c++ 20 or later
    Raylib library: https://www.raylib.com
    ButtonP Class

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MENU_P_HPP
#define MENU_P_HPP

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "ButtonP.hpp"
#include "enums.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// --------------------------------------------- Class MenuP ---------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MenuP
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
    vector<ButtonP> bars;
    float barSpacing = 50.0f,
          barsHeight = 0.0f,
          barsWidth = 0.0f;
    // Images paths
    vector<string> imgPaths;

    //---- Menu texts
    vector<string> texts;
    // Texts postion in bars
    unsigned textsPos = TXT_LEFT;
    float txtMargine = 25; // text margine left and right 
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
    MenuP();

    /*---------------------------------------------------

        Constructor-1
        - raylib default font
        texts. image paths

     ----------------------------------------------------*/
    MenuP(vector<string> &texts, vector<string> &imgPaths);

    /*------------------------------------------------------------

        Constructor-2
        - raylib default font
        texts, menu position, image paths

        CENTER, CENTER_TOP, CENTER_BOTTOM,
        LEFT, LEFT_TOP, LEFT_BOTTOM,
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

     -------------------------------------------------------------*/
    MenuP(vector<string> &texts, unsigned menuPos, vector<string> &imgPaths);

    /*---------------------------------------------------

        Constructor-3
        - raylib default font
        texts, menu position, texts position, image paths

        menu position:
        CENTER, CENTER_TOP, CENTER_BOTTOM,
        LEFT, LEFT_TOP, LEFT_BOTTOM,
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

        texts position:
        TXT_CENTER, TXT_LEFT, TXT_RIGHT

     ----------------------------------------------------*/
    MenuP(vector<string> &texts, unsigned menuPos, unsigned textsPos, vector<string> &imgPaths);

    /*---------------------------------------------------

        Constructor-4
        texts, font, image paths

     ----------------------------------------------------*/
    MenuP(vector<string> &texts, Font &font, float fontSize, vector<string> &imgPaths);

    /*---------------------------------------------------

        Constructor-5
        - raylib default font
        texts, menu position, font size, image paths

        menu position:
        CENTER, CENTER_TOP, CENTER_BOTTOM,
        LEFT, LEFT_TOP, LEFT_BOTTOM,
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

     ----------------------------------------------------*/
    MenuP(vector<string> &texts, unsigned menuPos, Font &font, float fontSize, vector<string> &imgPaths);

    /*---------------------------------------------------

        constructor-6
        - raylib default font
        texts, menu position, font size, image paths

        menu position:
        CENTER, CENTER_TOP, CENTER_BOTTOM,
        LEFT, LEFT_TOP, LEFT_BOTTOM,
        RIGHT, RIGHT_TOP, RIGHT_BOTTOM

        texts position:
        TXT_CENTER, TXT_LEFT, TXT_RIGHT

     ----------------------------------------------------*/
    MenuP(vector<string> &texts, unsigned menuPos, unsigned textsPos, Font &font, float fontSize, vector<string> &imgPaths);


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Destructor
    //---------------------------------------------------------------------------------
    ~MenuP();


    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // Accessors Methods
    //----------------------------------------------------------------------------------

    /*----------------------------------------------------

        draw bars

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


    //---------------------------------------------------------------------------------- Text and Font

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