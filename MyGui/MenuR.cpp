///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program Buttons               *         MenuR Class Definition       *                                 |
|                                *                                      *                                 |
---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

    The MenuR class creates static-size menu objects,
    window-resized-not-responsive menus.

    The menu object can contain one menu bar or several menu bars,
    the menu can be automatically positioned on the left, center, or right side of the screen.
    See mutators to modify the menu position.

    The bars’ sizes are computed from the font size and length of the bar text longest;
    the texts can be positioned on the left, center, or right side of the bars.
    See mutators to modify each individual bar position, the text’s position in each individual bar,
    and the each individual bar’s size.

    The bars’ borders can be turned on and off.
    The sizes of the borders are computed from the font size and length of the bar text longest bar;
    modifying the bars’ sizes will also modify the borders’ sizes.

    The button's shadows can be turned on and off.
    The sizes of the shadows are computed from the font size and length of the nar text longest;
    modifying the bars’ sizes will also modify the shadows’ sizes.

    The default font is raylib font.

    The menu bars are untilizing the ButtonR class


*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "MenuR.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------- Class ButtonR ---------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Constructors
//----------------------------------------------------------------------------------


//--------------------------------------------------------------------- Default constructor
/*---------------------------------------------------

    Default construtor
    - raylib default font

 ----------------------------------------------------*/
MenuR::MenuR()
{
    for (unsigned i = 0; i < 5; i++) texts.push_back("Menu");

    buildMenu();
}

//--------------------------------------------------------------------- Constructor-1
/*---------------------------------------------------

    Constructor-1
    - raylib default font
    texts

 ----------------------------------------------------*/
MenuR::MenuR(vector<string> texts)
{
    this->texts = texts;
    buildMenu();
}

//--------------------------------------------------------------------- Constructor-2
/*---------------------------------------------------

    Constructor-2
    - raylib default font
    texts, menu position

    CENTER, CENTER_TOP, CENTER_BOTTOM,
    LEFT, LEFT_TOP, LEFT_BOTTOM,
    RIGHT, RIGHT_TOP, RIGHT_BOTTOM

 ----------------------------------------------------*/
MenuR::MenuR(vector<string> texts, unsigned menuPos)
{
    this->texts = texts;
    this->menuPos = menuPos;
    buildMenu();
}

//--------------------------------------------------------------------- Constructor-3
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
MenuR::MenuR(vector<string> texts, unsigned menuPos, unsigned textsPos)
{
    this->texts = texts;
    this->menuPos = menuPos;
    this->textsPos = textsPos;
    buildMenu();
}

//--------------------------------------------------------------------- Constructor-4
/*---------------------------------------------------

    Constructor-4
    - raylib default font
    texts, font, font size

 ----------------------------------------------------*/
MenuR::MenuR(vector<string> texts, Font &font, float fontSize)
{
    this->texts = texts;
    this->font = font;
    this->fontSize = fontSize;
    isRayFont = false;
    buildMenu();
}

//--------------------------------------------------------------------- Constructor-5
/*---------------------------------------------------

    constructor-5
    - raylib default font
    texts, menu position, font size

    menu position:
    CENTER, CENTER_TOP, CENTER_BOTTOM,
    LEFT, LEFT_TOP, LEFT_BOTTOM,
    RIGHT, RIGHT_TOP, RIGHT_BOTTOM

 ----------------------------------------------------*/
MenuR::MenuR(vector<string> texts, unsigned menuPos, Font &font, float fontSize)
{
    this->texts = texts;
    this->menuPos = menuPos;
    this->font = font;
    this->fontSize = fontSize;
    isRayFont = false;
    buildMenu();
}

//--------------------------------------------------------------------- Constructor-6
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
MenuR::MenuR(vector<string> texts, unsigned menuPos, unsigned textsPos, Font &font, float fontSize)
{
    this->texts = texts;
    this->menuPos = menuPos;
    this->textsPos = textsPos;
    this->font = font;
    this->fontSize = fontSize;
    isRayFont = false;
    buildMenu();
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Accessors Methods
//----------------------------------------------------------------------------------

//--------------------------------------------------------------------- Method draw()
/*----------------------------------------------------

    Draws button

 -----------------------------------------------------*/
void MenuR::draw()
{
    for (ButtonR &bar : bars) bar.draw();
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Mutators Methods
//---------------------------------------------------------------------------------



//--------------------------------------------------------------------- Method buildMenu()
/*----------------------------------------------------------

    Builds the Menu,
    computes size from the font size and length of the texts
    
 -----------------------------------------------------------*/
void MenuR::buildMenu()
{
    //---- Builds Bar
    numBars =(unsigned)texts.size(); // the number of bars is computed from the size of the vector texts
    //-- Bars' texts
    if (isRayFont) // Default font
    {
        ButtonR bar; // empty bar, Default ButtonR
        for (unsigned i = 0; i < numBars; i++) bars.push_back(bar); 
        for (unsigned i = 0; i < numBars; i++) bars[i].setText(texts[i]); 
    }
    else // Loaded font
    {
        ButtonR bar("Empty", font, fontSize);
        for (unsigned i = 0; i < numBars; i++) bars.push_back(bar);
        for (unsigned i = 0; i < numBars; i++) bars[i].setText(texts[i]);
    }
    
    // Computes the bars width and menu width
    // The bars’ sizes are computed from the font size and length of the longest text
    float barsWidth = 0;
    for (ButtonR &bar : bars) if (bar.rect.width > barsWidth) barsWidth = bar.rect.width + 50;
    //-- Menu size
    menuWidth = barsWidth;
    menuHeight = numBars * bars[0].btnHeight + barSpacing * (numBars - 1);
    //-- sets bars size
    for (ButtonR &bar : bars) bar.setBtnSize(barsWidth, bar.rect.height);

    //---- Menu position
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    float screenMargin = 50.0f;
    try // Error handler
    {
        switch (menuPos) // Computes menu x and y position
        {
        case CENTER:
            menuX = (float)(screenWidth / 2) - (menuWidth / 2);
            menuY = (float)(screenHeight / 2) - (menuHeight / 2);
            break;
        case CENTER_TOP:
            menuX = (float)(screenWidth / 2) - (menuWidth / 2);
            menuY = screenMargin;
            break;
        case CENTER_BOTTOM:
            menuX = (float)(screenWidth / 2) - (menuWidth / 2);
            menuY = (float)(screenHeight - menuHeight - screenMargin);
            break;
        case LEFT:
            menuX = screenMargin;
            menuY = (float)(screenHeight / 2) - (menuHeight / 2);
            break;
        case LEFT_TOP:
            menuX = screenMargin;
            menuY = screenMargin;
            break;
        case LEFT_BOTTOM:
            menuX = screenMargin;
            menuY = (float)(screenHeight - menuHeight - screenMargin);
            break;
        case RIGHT:
            menuX = (float)(screenWidth - menuWidth - 2 * screenMargin);
            menuY = (float)(screenHeight / 2) - (menuHeight / 2);
            break;
        case RIGHT_TOP:
            menuX = (float)(screenWidth - menuWidth - 2 * screenMargin);
            menuY = screenMargin;
            break;
        case RIGHT_BOTTOM:
            menuX = (float)(screenWidth - menuWidth - 2 * screenMargin);
            menuY = (float)(screenHeight - menuHeight - screenMargin);
            break;
        case NONE:
            // The menu was repositioned using setMenuPosition()
            break;
        default:
            throw "   -- Error --\n   The entered menu position is not valid a valid entry.\n";
            break;
        }
    } catch (char const *ERROR) { cout << "\n " << ERROR; }// Catches the exception if it occurs

    //---- Bars positions
    float tempBarY = menuY;
    for (ButtonR &bar : bars)
    {
        bar.setBtnPosition(menuX, tempBarY);
        tempBarY += bar.btnHeight + barSpacing;
    }

    //---- Texts position
    for (ButtonR &bar : bars)
    {  
        try // Error handler
        {
            switch (textsPos)
            {
            case TXT_CENTER:
                // The ButtonR class centers the texts by default
                break;
            case TXT_LEFT:
                bar.setTextPosition(bar.rect.x + 10, bar.textPos.y);
                break;
            case TXT_RIGHT:
                bar.setTextPosition(bar.rect.x - 10 + (bar.rect.width - bar.textSize.x), bar.textPos.y);
                break;
            case TXT_NONE:
                // The texts were repositioned using setTextPos()
                break;
            default:
                throw "   -- Error --\n   The entered texts' position in menu is not a valid entry.\n";
                break;
            }
        } catch (char const *ERROR) { cout << "\n " << ERROR; }// Catches the exception if it occurs
    }
    
}

//--------------------------------------------------------------------------------------------------------- Shadow

//--------------------------------------------------------------------- Method setShadow()
/*----------------------------------------------------------

    Sets shadow true or false

 -----------------------------------------------------------*/
void MenuR::setShadow(bool isShadow)
{
    for (ButtonR &bar : bars) bar.isShadow = isShadow;
}

// --------------------------------------------------------------------- Method setShadowColor()
/*----------------------------------------------------------

    Sets shadow color

 -----------------------------------------------------------*/
void MenuR::setShadowColor(Color shadowColor)
{
    for (ButtonR &bar : bars) bar.shadowColor = shadowColor;
}

//--------------------------------------------------------------------------------------------------------- Border

//--------------------------------------------------------------------- Method setBorder()
/*----------------------------------------------------------

    Sets border true or false

 -----------------------------------------------------------*/
void MenuR::setBorder(bool isBorder)
{
    for (ButtonR &bar : bars) bar.isBorder = isBorder;
}

// --------------------------------------------------------------------- Method setBorderColorIdle()
/*----------------------------------------------------------

    Sets border color idle

 -----------------------------------------------------------*/
void MenuR::setBorderColorIdle(Color borderIdle)
{
    for (ButtonR &bar : bars) bar.borderIdle = borderIdle;
}

// --------------------------------------------------------------------- Method setBorderColorPressed()
/*----------------------------------------------------------

    Sets border color pressed

 -----------------------------------------------------------*/
void MenuR::setBorderColorPressed(Color borderPressed)
{
    for (ButtonR &bar : bars) bar.borderPressed = borderPressed;
}

// --------------------------------------------------------------------- Method setBorderColorHover()
/*----------------------------------------------------------

    Sets border color hover

 -----------------------------------------------------------*/
void MenuR::setBorderColorHover(Color borderHover)
{
    for (ButtonR &bar : bars) bar.borderHover = borderHover;
}

// --------------------------------------------------------------------- Method setBorderThickness()
/*----------------------------------------------------------

    Sets border thickness

 -----------------------------------------------------------*/
void MenuR::setBorderThickness(float borderThickness)
{
    for (ButtonR &bar : bars) bar.borderThickness = borderThickness;
}


//--------------------------------------------------------------------------------------------------------- Button rect.

// --------------------------------------------------------------------- Method setBtnColorIdle()
/*----------------------------------------------------------

    Sets button color idle

 -----------------------------------------------------------*/
void MenuR::setBtnColorIdle(Color borderIdle)
{
    for (ButtonR &bar : bars) bar.btnIdle = borderIdle;
}

// --------------------------------------------------------------------- Method setBtnColorPressed()
/*----------------------------------------------------------

    Sets button color pressed

 -----------------------------------------------------------*/
void MenuR::setBtnColorPressed(Color btnPressed)
{
    for (ButtonR &bar : bars) bar.btnPressed = btnPressed;
}

// --------------------------------------------------------------------- Method setBtnColorHover()
/*----------------------------------------------------------

    Sets button color hover

 -----------------------------------------------------------*/
void MenuR::setBtnColorHover(Color borderHover)
{
    for (ButtonR &bar : bars) bar.btnHover = borderHover;
}


// --------------------------------------------------------------------- Method setMenuPosition()
/*----------------------------------------------------------
    
    Sets menu possition

    menu position:
    CENTER, CENTER_TOP, CENTER_BOTTOM,
    LEFT, LEFT_TOP, LEFT_BOTTOM,
    RIGHT, RIGHT_TOP, RIGHT_BOTTOM

 -----------------------------------------------------------*/
void MenuR::setMenuPosition(unsigned menuPos)
{
    this->menuPos = menuPos;
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Class Methods Operations (private)
//---------------------------------------------------------------------------------

