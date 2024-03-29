/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*-------------------------------*****************************************----------------------------------
 |                                *                                      *                                 |
 |                                *		             MyGui               *                                 |
 |                                *                                      *                                 |
 ---------------------------------****************************************----------------------------------*/
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Alejandro (Alex) Ricciardi
created date: 02/8/2023

                                                   MyGui
                                            My Gui-Button-Menu 


MyGui is a c++ collection of classes that utilizes the raylib library; 
the classes feature buttons and menu-bars for graphical user interface (GUI).
MyGui offers a diverse set of methods that simplify and streamline the coding of buttons and menus.

Requirement
c and c++ 17 or later
Raylib library: https://www.raylib.com

****** Please see the README.txt file for more information about this project **********

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*-------------------------------*****************************************----------------------------------
 |                                *                                      *                                 |
 |                                *		          Headers                *                                 |
 |                                *                                      *                                 |
 ---------------------------------****************************************---------------------------------*/
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "myGui.hpp"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
 |                                *                                      *                                 |
 |                                *	            Classes                  *                                 |
 |                                *                                      *                                 |
 ---------------------------------****************************************---------------------------------*/
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*
   
    ------------------------------------------------------------------------------------------------------------

    -- ButtonR --

    The ButtonR class creates a rectangle-shaped static-size button, window-resized-not-responsive button.

    The button size is computed from the font size and length of the text;
    the text is automatically centered on the button.
    See mutators to modify the button�s position, the text�s position in the button, and the button�s size.

    The button's border can be turned on and off.
    the border's size is computed from the font size and length of the text;
    modifying the button's size, we also modify the border's size.

    The button's shadow can be turned on and off.
    The shadow size is computed from the font size and length of the text;
    modifying the button's size, we also modify the shadow's size..

    The default font is raylib font.

    Parent class to the ButtonO class

    ------------------------------------------------------------------------------------------------------------

    -- ButtonO --

    The ButtonO class creates a rounded edges rectangle shaped static-size button, window-resized-not-responsive button.

    The button size is computed from the font size and length of the text;
    the text is automatically centered on the button.
    See mutators to  modify the button�s position, the text�s position in the button, and the button�s size.

    The button's border can be turn on and off.
    the border's size is computed from the font size and length of the text;
    modifying the button's size, we also modify the border's size.

    The button's shadow can be turn on and off.
    The shadow size is computed from the font size and length of the text;
    modifying the button's size, we also modify the shadow's size.
    See mutators for modifying specifically the shadow's size and position.

    The default font is raylib font.

    Child class of ButtonR class

    ------------------------------------------------------------------------------------------------------------

    -- ButtonP --

    The ButtonP class creates a responsive button from an image.
    (The button resizes with the window)

    The button size is computed from the font size and length of the text;
    the text is automatically centered on the button.
    See mutators to modify the button�s position, the text�s position in the button, and the button�s size.

    The button's shadows can be turned on and off. It is off by default.
    The sizes of the shadows are computed from the font size and length of the bar with the longest text;
    modifying the bars� sizes will also modify the shadows� sizes.
    The default font is raylib font.

    The default font is raylib font.

    ------------------------------------------------------------------------------------------------------------
    ------------------------------------------------------------------------------------------------------------

    -- MenuR --

    The MenuR class creates static-size menu objects,
    window-resized-not-responsive menus.
    The MenuR objects consist of rectangle shaped bars.

    The menu object can contain one menu bar or several menu bars,
    the menu can be automatically positioned on the left, center, or right side of the screen.
    See mutators to modify the menu position.

    The bars� sizes are computed from the font size and length of the bar with the longest text;
    the texts can be positioned on the left, center, or right side of the bars.

    The bars� borders can be turned on and off.
    The sizes of the borders are computed from the font size and length of the bar with the longest text;
    modifying the bars� sizes will also modify the borders� sizes.

    The bars' shadows can be turned on and off.
    The sizes of the shadows are computed from the font size and length of the bar with the longest text;
    modifying the bars� sizes will also modify the shadows� sizes.

    The default font is raylib font.

    The menu bars utilize the ButtonR class.

    ------------------------------------------------------------------------------------------------------------

    --- MenuO ---

    The MenuO class creates static-size menu objects,
    window-resized-not-responsive menus.
    The MenuR objects consist of rounded edges rectangle shaped bars.

    The menu object can contain one menu bar or several menu bars,
    the menu can be automatically positioned on the left, center, or right side of the screen.
    See mutators to modify the menu position.

    The bars� sizes are computed from the font size and length of the bar with the longest text;
    the texts can be positioned on the left, center, or right side of the bars.

    The bars� borders can be turned on and off.
    The sizes of the borders are computed from the font size and length of the bar with the longest text;
    modifying the bars� sizes will also modify the borders� sizes.

    The bars' shadows can be turned on and off.
    The sizes of the shadows are computed from the font size and length of the bar with the longest text;
    modifying the bars� sizes will also modify the shadows� sizes.

    The default font is raylib font.

    The menu bars utilize the ButtonO class.

    ------------------------------------------------------------------------------------------------------------

    --- MenuP ---

    The MenuP class creates responsive menu objects, from images.

    The menu object can contain one menu bar or several menu bars,
    the menu can be automatically positioned on the left, center, or right side of the screen.
    See mutators to modify the menu position.

    The bars� sizes are computed from the font size and length of the bar with the longest text;
    the texts can be positioned on the left, center, or right side of the bars.

    The bars' shadows can be turned on and off. It is off by default.
    The sizes of the shadows are computed from the font size and length of the bar with the longest text;
    modifying the bars� sizes will also modify the shadows� sizes.
    
    The default font is raylib font.

    The menu bars utilize the ButtonP class.

    ------------------------------------------------------------------------------------------------------------


 */


 //////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |                                *	     Function Declarations        *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************---------------------------------*/
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*
    
    

  */

  /*--------------------------------------------------------------------

     Function descrption header comment

  --------------------------------------------------------------------*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
 |                                *                                      *                                 |
 |                                *		           Main                  *                                 |
 |                                *                                      *                                 |
 ---------------------------------****************************************---------------------------------*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    //--------------------------------------------------------------------------------------

    // variables
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1100;
    const int screenHeight = 950;

    //--------------------------------------------------------------------------------------

    // Initialization Window, OpenGL context, Texture Loads need to be call after this point 
    //--------------------------------------------------------------------------------------
    // 
    // Enable config flags for resizable window and vertical synchro
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "My Button Classes");


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //--------------------------------------------------------------------------------------

    // Initialize audio device and context
    //--------------------------------------------------------------------------------------
    InitAudioDevice();

    //--------------------------------------------------------------------------------------

    // 2D textures/ 3D textures / models
    //--------------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------

    // Sounds
    //--------------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------

    // Font
    //--------------------------------------------------------------------------------------
    // 
    Font font1 = LoadFont("resources/fonts/monofonto.otf");
    Font font2 = LoadFont("resources/fonts/segoeui.ttf");


    //--------------------------------------------------------------------------------------

    // Buttons
    //--------------------------------------------------------------------------------------
    // 
    //---------------------- Rectangle buttons
    ButtonR btnR1;
    //-- Shadow
    //btnR1.isShadow = false;
    //btnR1.shadowColor = GREEN;
    //btnR1.setShadowPos(btnR1.rect.x + 10, btnR1.rect.y + 10);
    //btnR1.setShadowSize(btnR1.rect.width + 10, btnR1.rect.height + 10);
    //-- Button
    //btnR1.btnIdle = PURPLE; // button idle
    //btnR1.btnHover = YELLOW; // button Hover
    //btnR1.btnPressed = GREEN; // button Pressed
    //btnR1.setBtnPosition(btnR1.rect.x + 25, btnR1.rect.y + 25);
    //-- Border
    //btnR1.isBorder = false;
    //btnR1.borderIdle = YELLOW; // border idle
    //btnR1.borderHover = PURPLE; // border Hover
    //btnR1.borderPressed = WHITE; // border Pressed
    //btnR1.borderThickness = 6;
    //-- Text and font
    //btnR1.setFont(font1);
    //btnR1.setText("Continue");
    //btnR1.setTextNoResize("up");
    //btnR1.setTextPosition(btnR1.rect.x + 10, btnR1.rect.y + 5);
    //btnR1.setFontSize(56);
    //btnR1.setFontSizeNoResize(34);
    //btnR1.fontColor = GRAY;

    ButtonR btnR2("Continue", 100, 225, font1);
    ButtonR btnR3("Play", 100, 300, font2);

    //----------------------  Rounded rectangle buttons
    ButtonO btnO1("Button", 450, 100);
    btnO1.roundness = 1.0f;
    ButtonO btnO2("Button", 450, 225, font1);
    ButtonO btnO3("Button", 450, 300, font2);

    //----------------------  Images buttons
    ButtonP btnP1;
    ButtonP btnP2("Button", 750, 225, "resources/images/bar2.png", font1);
    //-- Button
    //btnP2.isShadow = true;
    //btnP2.setHoverColor(YELLOW);
    //btnP2.setPressedColor(GREEN);
    //btnP2.setBtnPosition(btnP2.rect.x + 15, btnP2.rect.y + 15);
    //btnP2.setBtnSize(btnP2.rect.width + 15, btnP2.rect.height + 15);
    //-- Text and font
    //btnP2.setTextNoResize("up");
    //btnP2.setTextPosition(btnP2.rect.x + 15, btnP2.rect.y + 15);
    //btnP2.setFontSize(24);
    //btnP2.setFontSizeNoResize(24);
    //btnP2.fontColor = BLACK;

    ButtonP btnP3("Button", 750, 325, "resources/images/button1.png", font2);


    //--------------------------------------------------------------------------------------

    // Menus
    //--------------------------------------------------------------------------------------
    // 

    vector<string> menuTxt = { "START", "RESUME", "NEXT", "ABOUT", "EXIT"};
    vector<string> imgPaths = { "resources/images/bar1.png", "resources/images/bar2.png", "resources/images/bar3.png", "resources/images/bar4.png", "resources/images/bar5.png" };

    //----------------------  Menu Rectangle Bars
    //MenuR menuDefaultR;
    //menuDefaultR.setFont(font1);
    //menuDefaultR.setBarSpacing(25.0f);
    //MenuR menuR1(menuTxt);
    //MenuR menuR2(menuTxt, CENTER);
    //MenuR menuR3(menuTxt, CENTER, TXT_RIGHT);
    //MenuR menuR4(menuTxt, CENTER, font2, 32);
    MenuR menuR5(menuTxt, CENTER, TXT_LEFT, font1, 34);
    //menuR5.setBarsSize(300, 55);
    //-- Shadow
    //menuR5.setShadow(false);
    //menuR5.setShadowsColor(GREEN);
    //menuR5.AddToShadowsPos(5, 5);
    //menuR5.AddToShadowsSize(5, 5);
    //--- Border
    //menuR5.setBordersThickness(5);
    //menuR5.setBordersColorIdle({ GREEN, DARKGREEN, YELLOW, DARKBLUE, BLUE });
    //menuR5.setBordersColorPressed({ RED, RED, RED, RED, RED });
    //menuR5.setBordersColorHover({ YELLOW, BLUE, DARKBLUE, DARKGREEN, GREEN });
    //menuR5.setBorder(false);
    //--- Bar
    //menuR5.setBarsColorIdle({ GREEN, DARKGREEN, YELLOW, DARKBLUE, BLUE });
    //menuR5.setBarsColorPressed({ RED, RED, RED, RED, RED });
    //menuR5.setBarsColorHover({ YELLOW, BLUE, DARKBLUE, DARKGREEN, GREEN } );
    //--- Text and font
    //menuR5.setFontSize(58);
    //menuR5.setBarSpacing(100);
    //menuR5.setFontSizeNoResize(24);
    //menuR5.setTextBar("----------------------Mod.Text Bar------------------", 3);
    //menuR5.setTextBar("Mod.Text Bar", 3);
    //menuR5.setTxtPosition(TXT_CENTER);
    //menuR5.setFontsColor({ YELLOW, BLUE, DARKBLUE, DARKGREEN, GREEN });

    //----------------------  Menu Reounded Bars
    //MenuO menuDefaultO;
    //MenuO menuO1(menuTxt);
    //MenuO menuO2(menuTxt, CENTER);
    //MenuO menuO3(menuTxt, CENTER, TXT_RIGHT);
    //MenuO menuO4(menuTxt, CENTER, font2, 32);
    MenuO menuO5(menuTxt, CENTER, TXT_CENTER, font1, 32);
    menuO5.setBarsSize(300, 55);
    menuO5.setbBarsRoundness(1);
    //----------------------  Menu Image Bars
    //MenuP menuDefaultP;
    //MenuP menuP1(menuTxt, imgPaths);
    //MenuP menuP2(menuTxt, CENTER, imgPaths);
    //MenuP menuP3(menuTxt, CENTER, TXT_CENTER, imgPaths);
    //MenuP menuP4(menuTxt, font1, 24, imgPaths);
    //MenuP menuP5(menuTxt, CENTER, TXT_CENTER, font1, 24, imgPaths);
    MenuP menuP6(menuTxt, CENTER, TXT_CENTER, font1, 24, imgPaths);
    menuP6.setBarsSize(250, 65);
    //-- Shadow
    //menuP6.setShadow(true);
    //menuP6.setShadowsColor(GREEN);
    //menuP6.AddToShadowsPos(5, 5);
    //menuP6.AddToShadowsSize(5, 5);
    //--- Bar
    menuP6.setBarsColorPressed({ RED, RED, RED, RED, RED });
    menuP6.setBarsColorHover({ YELLOW, BLUE, DARKBLUE, DARKGREEN, GREEN } );
    //--- Text and font
    menuP6.setFontSize(58);
    menuP6.setBarSpacing(100);
    menuP6.setFontSizeNoResize(34);
    //menuP6.setTextBar("----------------------Mod.Text Bar------------------", 3);
    //menuP6.setTextBar("Mod.Text Bar", 3);
    //menuP6.setTxtPosition(TXT_LEFT);
    //menuP6.setFontsColor({ LIGHTGRAY, DARKGRAY, WHITE, DARKGREEN, DARKBROWN });

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //--------------------------------------------------------------------------------------

        // Update
        //-------------------------------------------------------------------------------------- 
        
        
                                         
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------

        BeginDrawing();

            ClearBackground(BLACK);

            //---------------------- Rectangle buttons
            //btnR1.draw();
            //btnR2.draw();
            //btnR3.draw();
            //---------------------- Round buttons
            //btnO1.draw();
            //btnO2.draw();
            //btnO3.draw();
            //---------------------- Image buttons
            //btnP1.draw();
            //btnP2.draw();
            //btnP3.draw();

            //---------------------- Rectangle menu
            //menuDefaultR.draw();
            //menuR1.draw();
            //menuR2.draw();
            //menuR3.draw();
            //menuR4.draw();
            //menuR5.draw();
            //---------------------- Round Menu
            //menuDefaultO.draw();
            //menuO1.draw();
            //menuO2.draw();
            //menuO3.draw();
            //menuO4.draw();
            //menuO5.draw();
            //---------------------- Image buttons
            //menuDefaultP.draw();
            //menuP1.draw();
            //menuP2.draw();
            //menuP3.draw();
            //menuP4.draw();
            //menuP5.draw();
            menuP6.draw();

        EndDrawing();

        //----------------------------------------------------------------------------------

        // Update buttons
        //----------------------------------------------------------------------------------

        switch (btnP1.update())
        {
        case MOUSE_BUTTON_LEFT:
            cout << "\n---- The mouse left button was pressed, exit program ----\n";
            exit(0); // exists program
            break;
        case MOUSE_BUTTON_RIGHT:
            cout << "\n---- The mouse right button was pressed, exit program  ----\n";
            exit(0); // exists program
            break;
        case MOUSE_BUTTON_MIDDLE:
            cout << "\n---- The mouse middle button was pressed, exit program  ----\n";
            exit(0); // exists program
            break;
        default:
            break;
        }

        //----------------------------------------------------------------------------------

        // Update menus
        //----------------------------------------------------------------------------------
 
        switch (menuP6.bars[4].update())
        {
        case MOUSE_BUTTON_LEFT:
            cout << "\n---- The menu bar mouse left button was pressed, exit program  ----\n";
            exit(0); // exists program
            break;
        case MOUSE_BUTTON_RIGHT:
            cout << "\n---- The menu bar mouse right button was pressed, exit program  ----\n";
            exit(0); // exists program
            break;
        case MOUSE_BUTTON_MIDDLE:
            cout << "\n---- The menu bar mouse middle button was pressed, exit program  ----\n";
            exit(0); // exists program
            break;
        default:
            break;
        }
    }

    //--------------------------------------------------------------------------------------

    // De-Initialization
    //--------------------------------------------------------------------------------------
    
    
    CloseWindow();        // Close window and OpenGL context

    //--------------------------------------------------------------------------------------

    return 0;
}