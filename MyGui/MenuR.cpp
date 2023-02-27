///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  MyGui                         *         MenuR Class Definition       *                                 |
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

    The menu bars are untilizing the ButtonR class

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "MenuR.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------- Class MenuR ---------------------------------------------------
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
    for (ButtonR &bar : bars) bar.borderThickness = 2.0f;
}

//--------------------------------------------------------------------- Constructor-1
/*---------------------------------------------------

    Constructor-1
    - raylib default font
    texts

 ----------------------------------------------------*/
MenuR::MenuR(vector<string> &texts)
{
    this->texts = texts;
    buildMenu();
    for (ButtonR &bar : bars) bar.borderThickness = 2.0f;
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
MenuR::MenuR(vector<string> &texts, unsigned menuPos)
{
    this->texts = texts;
    this->menuPos = menuPos;
    buildMenu();
    for (ButtonR &bar : bars) bar.borderThickness = 2.0f;
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
MenuR::MenuR(vector<string> &texts, unsigned menuPos, unsigned textsPos)
{
    this->texts = texts;
    this->menuPos = menuPos;
    this->textsPos = textsPos;
    buildMenu();
    for (ButtonR &bar : bars) bar.borderThickness = 2.0f;
}

//--------------------------------------------------------------------- Constructor-4
/*---------------------------------------------------

    Constructor-4
    - raylib default font
    texts, font, font size

 ----------------------------------------------------*/
MenuR::MenuR(vector<string> &texts, Font &font, float fontSize)
{
    this->texts = texts;
    this->font = font;
    this->fontSize = fontSize;
    isRayFont = false;
    buildMenu();
    for (ButtonR &bar : bars) bar.borderThickness = 2.0f;
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
MenuR::MenuR(vector<string> &texts, unsigned menuPos, Font &font, float fontSize)
{
    this->texts = texts;
    this->menuPos = menuPos;
    this->font = font;
    this->fontSize = fontSize;
    isRayFont = false;
    buildMenu();
    for (ButtonR &bar : bars) bar.borderThickness = 2.0f;
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
MenuR::MenuR(vector<string> &texts, unsigned menuPos, unsigned textsPos, Font &font, float fontSize)
{
    this->texts = texts;
    this->menuPos = menuPos;
    this->textsPos = textsPos;
    this->font = font;
    this->fontSize = fontSize;
    isRayFont = false;
    buildMenu();
    for (ButtonR &bar : bars) bar.borderThickness = 2.0f;
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Accessors Methods
//----------------------------------------------------------------------------------

//--------------------------------------------------------------------- Method draw()
/*----------------------------------------------------

    Draws menu
    Not inherited by child classes

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
    Not inherited by child classes
    
 -----------------------------------------------------------*/
void MenuR::buildMenu()
{
    //---- Builds Bar
    numBars = (unsigned)texts.size(); // the number of bars is computed from the size of the vector texts
    //-- Bars' texts
    if (!isTxtMod)
    {
        // Init. bars vectoct
        bars.clear();
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
    }
    // Computes the bars width and menu width
    // The bars’ sizes are computed from the font size and length of the longest text
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
                bar.setTextPosition(bar.rect.x + txtMargine, bar.textPos.y);
                break;
            case TXT_RIGHT:
                bar.setTextPosition(bar.rect.x - txtMargine + (bar.rect.width - bar.textSize.x), bar.textPos.y);
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
    
} // buildMenu()

//--------------------------------------------------------------------------------------------------------- Menu 

// --------------------------------------------------------------------- Method setMenuPosition()
/*----------------------------------------------------------

    Sets menu position

    menu position:
    CENTER, CENTER_TOP, CENTER_BOTTOM,
    LEFT, LEFT_TOP, LEFT_BOTTOM,
    RIGHT, RIGHT_TOP, RIGHT_BOTTOM

 -----------------------------------------------------------*/
void MenuR::setMenuPosition(unsigned menuPos)
{
    this->menuPos = menuPos;
}

/*----------------------------------------------------------

    Sets Bar spacing

 -----------------------------------------------------------*/
void MenuR::setBarSpacing(float barSpacing)
{
    this->barSpacing = barSpacing;
    buildMenu();
}

//--------------------------------------------------------------------------------------------------------- Bars

// --------------------------------------------------------------------- Method setBarsColorIdle()
/*----------------------------------------------------------

    Sets bars color idle

 -----------------------------------------------------------*/
void MenuR::setBarsColorIdle(vector<Color> barsIdle)
{
    for (unsigned i = 0; i < bars.size(); i++) bars[i].btnIdle = barsIdle[i];
}

// --------------------------------------------------------------------- Method setBarsColorPressed()
/*----------------------------------------------------------

    Sets bars color pressed

 -----------------------------------------------------------*/
void MenuR::setBarsColorPressed(vector<Color> barsPressed)
{
    for (unsigned i = 0; i < bars.size(); i++) bars[i].btnPressed = barsPressed[i];
    
}

// --------------------------------------------------------------------- Method setBarsColorHover()
/*----------------------------------------------------------

    Sets bars color hover

 -----------------------------------------------------------*/
void MenuR::setBarsColorHover(vector<Color> barsHover)
{
    for (unsigned i = 0; i < bars.size(); i++) bars[i].btnHover = barsHover[i];
}

//--------------------------------------------------------------------- Method setMenuBarsSize()
/*----------------------------------------------------

    Sets sizes of the bars,
    does not resise fonts

 -----------------------------------------------------*/
void MenuR::setBarsSize(float barWidth, float barHeight)
{
    for (ButtonR &bar : bars) bar.setBtnSize(barWidth, barHeight);
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
void MenuR::setShadowsColor(Color shadowColor)
{
    for (ButtonR &bar : bars) bar.shadowColor = shadowColor;
}

// --------------------------------------------------------------------- Method AddToShadowPos()
/*----------------------------------------------------------

    Adds to shadow position relative to bars

 -----------------------------------------------------------*/
void MenuR::AddToShadowsPos(float AddToX, float AddToY)
{
    for (ButtonR &bar : bars) bar.setShadowPos(bar.shadow.x + AddToX, bar.shadow.y + AddToY);
}

// --------------------------------------------------------------------- Method AddToShadowSize()
/*----------------------------------------------------------

    Add to shadow size 

 -----------------------------------------------------------*/
void MenuR::AddToShadowsSize(float AddToWidth, float AddToHeight)
{
    for (ButtonR &bar : bars) bar.setShadowSize(bar.shadow.width + AddToHeight, bar.shadow.height + AddToHeight);
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

// --------------------------------------------------------------------- Method setBordersColorIdle()
/*----------------------------------------------------------

    Sets borders color idle

 -----------------------------------------------------------*/
void MenuR::setBordersColorIdle(vector<Color> bordersIdle)
{
    for (unsigned i = 0; i < bars.size(); i++) bars[i]. borderIdle = bordersIdle[i];
}

// --------------------------------------------------------------------- Method setBordersColorPressed()
/*----------------------------------------------------------

    Sets borders color pressed

 -----------------------------------------------------------*/
void MenuR::setBordersColorPressed(vector<Color> bordersPressed)
{
    for (unsigned i = 0; i < bars.size(); i++) bars[i].borderPressed = bordersPressed[i];
}

// --------------------------------------------------------------------- Method setBordersColorHover()
/*----------------------------------------------------------

    Sets borders color hover

 -----------------------------------------------------------*/
void MenuR::setBordersColorHover(vector<Color> bordersHover)
{
    for (unsigned i = 0; i < bars.size(); i++) bars[i].borderHover = bordersHover[i];
}

// --------------------------------------------------------------------- Method setBordersThickness()
/*----------------------------------------------------------

    Sets borders thickness

 -----------------------------------------------------------*/
void MenuR::setBordersThickness(float borderThickness)
{
    for (ButtonR &bar : bars) bar.borderThickness = borderThickness;
}

//--------------------------------------------------------------------------------------------------------- Text and font

//--------------------------------------------------------------------- Method setFont()
/*----------------------------------------------------

    Sets font and
    Resizes button to fit text
    isRayFont = false;

 -----------------------------------------------------*/
void MenuR::setFont(Font font)
{
    this->font = font;
    for (ButtonR &bar : bars) bar.setFont(font);
    isTxtMod = true;
    isRayFont = false;
    buildMenu();
}

//--------------------------------------------------------------------- Method setFontSize()
/*----------------------------------------------------

     Sets font size and
     Resizes menu bars to fit text

 -----------------------------------------------------*/
void MenuR::setFontSize(float fontSize)
{
    this->fontSize = fontSize;
    for (ButtonR &bar : bars) bar.setFontSize(fontSize);
    isTxtMod = true;
    buildMenu();
}

//--------------------------------------------------------------------- Method setFontSizeNoResize()
/*----------------------------------------------------

     Sets font size and
     does NOT resizes bars to fit text

 -----------------------------------------------------*/
void MenuR::setFontSizeNoResize(float fontSize)
{
    this->fontSize = fontSize;
    for (ButtonR &bar : bars) bar.setFontSizeNoResize(fontSize);
    isTxtMod = true;
    buildMenu();
}

//--------------------------------------------------------------------- Method setTextsBars()
/*----------------------------------------------------

     Sets text to a bar and
     if need it,
     resizes the bar and the menu lenght to fit text
     but not the heights.

     the bars indexes start at 0

 -----------------------------------------------------*/
void MenuR::setTextBar(string text, unsigned barIndex)
{
    float barHeight = bars[barIndex].rect.height;
    bars[barIndex].setText(text);
    bars[barIndex].rect.height = barHeight;
    texts[barIndex] = text;
    isTxtMod = true;
    buildMenu();
}

// --------------------------------------------------------------------- Method setTextPosition()
/*----------------------------------------------------------

    Sets texts position

    texts position:
    TXT_CENTER, TXT_LEFT, TXT_RIGHT

 -----------------------------------------------------------*/
void MenuR::setTxtPosition(unsigned textsPos)
{
    this->textsPos = textsPos;
    isTxtMod = true;
    buildMenu();
}

// --------------------------------------------------------------------- Method setFontsColor()
/*----------------------------------------------------------

    Sets fonts color

 -----------------------------------------------------------*/
void MenuR::setFontsColor(vector<Color> fontsColor)
{
    for (unsigned i = 0; i < bars.size(); i++) bars[i].fontColor = fontsColor[i];
    isTxtMod = true;
    buildMenu();
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Class Methods Operations (private)
//---------------------------------------------------------------------------------

