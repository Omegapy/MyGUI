///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program MyGui                 *        MenuP Class Definition        *                                 |
|                                *                                      *                                 |
---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
*
    The MenuP class creates responsive menu objects, from an image.
    (The button resizes with the window).

    The menu object can contain one menu bar or several menu bars,
    the menu can be automatically positioned on the left, center, or right side of the screen.
    See mutators to modify the menu position.

    The bars’ sizes are computed from the font size and length of the bar with the longest text;
    the texts can be positioned on the left, center, or right side of the bars.

    The default font is raylib font.

    The menu bars untilize the ButtonP class

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "MenuP.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------- Class MenuO ---------------------------------------------------
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
MenuP::MenuP()
{
    for (unsigned i = 0; i < 5; i++)
    {
        texts.push_back("Menu");
        imgPaths.push_back("resources/images/bar1.png");
    }

    buildMenu();
}

//--------------------------------------------------------------------- Constructor-1
/*---------------------------------------------------

    Constructor-1
    - raylib default font
    texts, image paths

 ----------------------------------------------------*/
MenuP::MenuP(vector<string> &texts, vector<string> &imgPaths)
{
    this->texts = texts;
    this->imgPaths = imgPaths;
    buildMenu();
}

//--------------------------------------------------------------------- Constructor-2
/*---------------------------------------------------

    Constructor-2
    - raylib default font
    texts, menu position, image paths

    CENTER, CENTER_TOP, CENTER_BOTTOM,
    LEFT, LEFT_TOP, LEFT_BOTTOM,
    RIGHT, RIGHT_TOP, RIGHT_BOTTOM

 ----------------------------------------------------*/
MenuP::MenuP(vector<string> &texts, unsigned menuPos, vector<string> &imgPaths)
{
    this->texts = texts;
    this->menuPos = menuPos;
    this->imgPaths = imgPaths;
    buildMenu();
}

//--------------------------------------------------------------------- Constructor-3
/*---------------------------------------------------

    Constructor-3
    - raylib default font
    texts, menu position, texts position, image path

    menu position:
    CENTER, CENTER_TOP, CENTER_BOTTOM,
    LEFT, LEFT_TOP, LEFT_BOTTOM,
    RIGHT, RIGHT_TOP, RIGHT_BOTTOM

    texts position:
    TXT_CENTER, TXT_LEFT, TXT_RIGHT

 ----------------------------------------------------*/
MenuP::MenuP(vector<string> &texts, unsigned menuPos, unsigned textsPos, vector<string> &imgPaths)
{
    this->texts = texts;
    this->menuPos = menuPos;
    this->textsPos = textsPos;
    this->imgPaths = imgPaths;
    buildMenu();
}

//--------------------------------------------------------------------- Constructor-4
/*---------------------------------------------------

    Constructor-4
    - raylib default font, image path
    texts, font, font size

 ----------------------------------------------------*/
MenuP::MenuP(vector<string> &texts, Font &font, float fontSize, vector<string> &imgPaths)
{
    this->texts = texts;
    this->font = font;
    this->fontSize = fontSize;
    isRayFont = false;
    this->imgPaths = imgPaths;
    buildMenu();
}

//--------------------------------------------------------------------- Constructor-5
/*---------------------------------------------------

    constructor-5
    - raylib default font
    texts, menu position, font size, image paths

    menu position:
    CENTER, CENTER_TOP, CENTER_BOTTOM,
    LEFT, LEFT_TOP, LEFT_BOTTOM,
    RIGHT, RIGHT_TOP, RIGHT_BOTTOM

 ----------------------------------------------------*/
MenuP::MenuP(vector<string> &texts, unsigned menuPos, Font &font, float fontSize, vector<string> &imgPaths)
{
    this->texts = texts;
    this->menuPos = menuPos;
    this->font = font;
    this->fontSize = fontSize;
    this->imgPaths = imgPaths;
    isRayFont = false;
    buildMenu();
}

//--------------------------------------------------------------------- Constructor-6
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
MenuP::MenuP(vector<string> &texts, unsigned menuPos, unsigned textsPos, Font &font, float fontSize, vector<string> &imgPaths)
{
    this->texts = texts;
    this->menuPos = menuPos;
    this->textsPos = textsPos;
    this->font = font;
    this->fontSize = fontSize;
    this->imgPaths = imgPaths;
    isRayFont = false;
    buildMenu();
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Destructor
//---------------------------------------------------------------------------------
MenuP::~MenuP()
{
    for (ButtonP &bar : bars)
    {
        //----------------------------------------------------------------------------------

        // De-Initialization Textures
        //----------------------------------------------------------------------------------
        UnloadTexture(bar.btnIdle);
        UnloadTexture(bar.btnHover);
        UnloadTexture(bar.btnPressed);
        UnloadTexture(bar.textIdle);
        UnloadTexture(bar.textHover);
        UnloadTexture(bar.textPressed);
    }
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Accessors Methods
//----------------------------------------------------------------------------------

//--------------------------------------------------------------------- Method draw()
/*----------------------------------------------------

    Draws menu

 -----------------------------------------------------*/
void MenuP::draw()
{
    for (ButtonP &bar : bars) bar.draw();
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
void MenuP::buildMenu()
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
            ButtonP bar; // empty bar, Default ButtonR
            for (unsigned i = 0; i < numBars; i++) bars.push_back(bar);
            for (unsigned i = 0; i < numBars; i++)
            {
                bars[i].imgPath = imgPaths[i];
                bars[i].setText(texts[i]);
               
            }
        }
        else // Loaded font
        {
            ButtonP bar("Empty", font, fontSize);
            for (unsigned i = 0; i < numBars; i++) bars.push_back(bar);
            for (unsigned i = 0; i < numBars; i++) 
            {
                bars[i].imgPath = imgPaths[i];
                bars[i].setText(texts[i]);
            }
        }
    }
    // Computes the bars width and menu width
    // The bars’ sizes are computed from the font size and length of the longest text
    float barsWidth = 0;
    for (ButtonP &bar : bars) if (bar.rect.width > barsWidth) barsWidth = bar.rect.width + 50;
    //-- Menu size
    menuWidth = barsWidth;
    menuHeight = numBars * bars[0].btnHeight + barSpacing * (numBars - 1);
    //-- sets bars size
    for (ButtonP &bar : bars) bar.setBtnSize(barsWidth, bar.rect.height);

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
    }
    catch (char const *ERROR) { cout << "\n " << ERROR; }// Catches the exception if it occurs

    //---- Bars positions
    float tempBarY = menuY;
    for (ButtonP &bar : bars)
    {
        bar.setBtnPosition(menuX, tempBarY);
        tempBarY += bar.btnHeight + barSpacing;
    }

    //---- Texts position
    for (ButtonP &bar : bars)
    {
        try // Error handler
        {
            switch (textsPos)
            {
            case TXT_CENTER:
                // The ButtonO class centers the texts by default
                break;
            case TXT_LEFT:
                bar.setTextPosition(bar.rect.x + txtMargine, bar.textPos.y);
                break;
            case TXT_RIGHT:
                bar.setTextPosition(bar.rect.x - txtMargine + (bar.rect.width - bar.textSize.x), bar.textPos.y);
                break;
            default:
                throw "   -- Error --\n   The entered texts' position in menu is not a valid entry.\n";
                break;
            }
        }
        catch (char const *ERROR) { cout << "\n " << ERROR; }// Catches the exception if it occurs
    }

} // buildMenu()

//--------------------------------------------------------------------------------------------------------- Menu bars

// --------------------------------------------------------------------- Method setMenuPosition()
/*----------------------------------------------------------

    Sets menu position

    menu position:
    CENTER, CENTER_TOP, CENTER_BOTTOM,
    LEFT, LEFT_TOP, LEFT_BOTTOM,
    RIGHT, RIGHT_TOP, RIGHT_BOTTOM

 -----------------------------------------------------------*/
void MenuP::setMenuPosition(unsigned menuPos)
{
    this->menuPos = menuPos;
}


// --------------------------------------------------------------------- Method setBarsColorPressed()
/*----------------------------------------------------------

    Sets bars color pressed

 -----------------------------------------------------------*/
void MenuP::setBarsColorPressed(Color barPressed)
{
    for (ButtonP &bar : bars) bar.setPressedColor(barPressed);
}

//--------------------------------------------------------------------- Method setBarsColorHover()
/*----------------------------------------------------

     Sets the hover color for bars

 -----------------------------------------------------*/
void MenuP::setBarsColorHover(Color barHoverColor)
{
    for (ButtonP &bar : bars) bar.setHoverColor(barHoverColor);
}


//--------------------------------------------------------------------- Method setMenuBarsSize()
/*----------------------------------------------------

    Sets sizes of the bars,
    does not resise fonts

 -----------------------------------------------------*/
void MenuP::setBarsSize(float barWidth, float barHeight)
{
    for (ButtonP &bar : bars) bar.setBtnSize(barWidth, barHeight);
}


//--------------------------------------------------------------------------------------------------------- Text

//--------------------------------------------------------------------- Method setFontSize()
/*----------------------------------------------------

     Sets font size and
     Resizes menu bars to fit text

 -----------------------------------------------------*/
void MenuP::setFontSize(float fontSize)
{
    this->fontSize = fontSize;
    for (ButtonP &bar : bars) bar.setFontSize(fontSize);
    isTxtMod = true;
    buildMenu();
}

//--------------------------------------------------------------------- Method setFontSizeNoResize()
/*----------------------------------------------------

     Sets font size and
     does NOT resizes bars to fit text

 -----------------------------------------------------*/
void MenuP::setFontSizeNoResize(float fontSize)
{
    this->fontSize = fontSize;
    for (ButtonP &bar : bars) bar.setFontSizeNoResize(fontSize);
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
void MenuP::setTextBar(string text, unsigned barIndex)
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
void MenuP::setTxtPosition(unsigned textsPos)
{
    this->textsPos = textsPos;
    isTxtMod = true;
    buildMenu();
}
