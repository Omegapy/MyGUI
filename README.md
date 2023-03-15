-----------------------------------------------------------------------------------------------------------------------------
MyGui     Gui-Button-Menu 
-----------------------------------------------------------------------------------------------------------------------------

MyGui a C++ program using the raylib library which features buttons and a menu for graphical user interface (GUI). 
Named MyGui, the program offers a wide range of functions while keeping the coding process simple.

Alejandro (Alex) Ricciardi  
created date: 02/08/2023  
Initialized with MyRaylibTemplate  
https://github.com/Omegapy/MyRaylibTemplate  

-----------------------------------------------------------------------------------------------------------------------------
Requirements:  

c and c++ 17 or later    
MS Windows 10 or later   
Raylib library: https://www.raylib.com  

<p align="left">
  <img width="75" height="75" src="https://user-images.githubusercontent.com/121726699/215234958-2659b12a-4181-4f6b-a757-3e868244192e.png">
  <img width="200" height="100" src="https://user-images.githubusercontent.com/121726699/215234968-9f5961e4-8ca0-4f4e-acdc-53c1817547dd.png">
</p>

-----------------------------------------------------------------------------------------------------------------------------
Project description:

The project contains My Gui-Button-Menu classes in c++ and the raylib library.

<p align="center">
 <img width="443" height="519"src="https://user-images.githubusercontent.com/121726699/225176364-845df742-e397-4d19-8815-b6afbe207293.PNG">
</p>

-----------------------------------------------------------------------------------------------------------------------------
Buttons

~~~c++
/*
   -- ButtonR --

    The ButtonR class creates a rectangle-shaped static-size button, window-resized-not-responsive button.

    The button size is computed from the font size and length of the text;
    the text is automatically centered on the button.
    See mutators to modify the button’s position, the text’s position in the button, and the button’s size.

    The button's border can be turned on and off.
    the border's size is computed from the font size and length of the text;
    modifying the button's size, we also modify the border's size.

    The button's shadow can be turned on and off.
    The shadow size is computed from the font size and length of the text;
    modifying the button's size, we also modify the shadow's size..

    The default font is raylib font.

    Parent class to the ButtonO class
   
*/
ButtonR button;
~~~
~~~c++
/*
    -- ButtonO --

    The ButtonO class creates a rounded edges rectangle shaped static-size button, window-resized-not-responsive button.

    The button size is computed from the font size and length of the text;
    the text is automatically centered on the button.
    See mutators to  modify the button’s position, the text’s position in the button, and the button’s size.

    The button's border can be turn on and off.
    the border's size is computed from the font size and length of the text;
    modifying the button's size, we also modify the border's size.

    The button's shadow can be turn on and off.
    The shadow size is computed from the font size and length of the text;
    modifying the button's size, we also modify the shadow's size.
    See mutators for modifying specifically the shadow's size and position.

    The default font is raylib font.

    Child class of ButtonR class
    
*/
ButtonO button;
~~~
~~~c++
/*
    -- ButtonP --

    The ButtonP class creates a responsive button from an image.
    (The button resizes with the window)

    The button size is computed from the font size and length of the text;
    the text is automatically centered on the button.
    See mutators to modify the button’s position, the text’s position in the button, and the button’s size.

    The button's shadows can be turned on and off. It is off by default.
    The sizes of the shadows are computed from the font size and length of the bar with the longest text;
    modifying the bars’ sizes will also modify the shadows’ sizes.
    The default font is raylib font.

    The default font is raylib font.
    
*/
ButtonP button;
~~~

-----------------------------------------------------------------------------------------------------------------------------
Menus

~~~c++
/*
    -- MenuR --

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

    The bars' shadows can be turned on and off.
    The sizes of the shadows are computed from the font size and length of the bar with the longest text;
    modifying the bars’ sizes will also modify the shadows’ sizes.

    The default font is raylib font.

    The menu bars untilize the ButtonR class.

*/
MenuR menu;
~~~

~~~c++
/*
    --- MenuO ---

    The MenuO class creates static-size menu objects,
    window-resized-not-responsive menus.
    The MenuR objects consist of rounded edges rectangle shaped bars.

    The menu object can contain one menu bar or several menu bars,
    the menu can be automatically positioned on the left, center, or right side of the screen.
    See mutators to modify the menu position.

    The bars’ sizes are computed from the font size and length of the bar with the longest text;
    the texts can be positioned on the left, center, or right side of the bars.

    The bars’ borders can be turned on and off.
    The sizes of the borders are computed from the font size and length of the bar with the longest text;
    modifying the bars’ sizes will also modify the borders’ sizes.

    The bars' shadows can be turned on and off.
    The sizes of the shadows are computed from the font size and length of the bar with the longest text;
    modifying the bars’ sizes will also modify the shadows’ sizes.

    The default font is raylib font.

    The menu bars untilize the ButtonO class.

*/
MenuO menu;
~~~
~~~c++
/*
    --- MenuP ---

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
    
    The menu bars untilize the ButtonP class.

*/
MenuP menu;
~~~

Link: <a href='https://github.com/Omegapy/MyButtonClasses/wiki/Image-How-To-ButtonP-Class'>Image How To ButtonP Class</a>


-----------------------------------------------------------------------------------------------------------------------------

Links  :  
Project GitHub: https://github.com/Omegapy/MyGUI  
GitHub: https://github.com/Omegapy   
YouTube: YouTube: https://www.youtube.com/@omegapy  
Facebook: https://www.facebook.com/profile.php?id=100089638857137  
Twitter: https://twitter.com/RicciardiAlex  

-----------------------------------------------------------------------------------------------------------------------------
Credits:

Example button image:  
<a href='https://pngtree.com/so/icons'>icons png from pngtree.com</a>

