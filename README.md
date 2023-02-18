-----------------------------------------------------------------------------------------------------------------------------
My Gui-Button-Menu 
-----------------------------------------------------------------------------------------------------------------------------

Button classes in c++ and the raylib library.

 Alejandro (Alex) Ricciardi  
 created date: 02/08/2023  
 Initialized with MyRaylibTemplate  
 https://github.com/Omegapy/MyRaylibTemplate  

-----------------------------------------------------------------------------------------------------------------------------
Requirements:  

c and c++ 20 or later    
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
 <img width="150" height="75"src="https://user-images.githubusercontent.com/121726699/215300372-34bd2249-3a93-49cf-a213-71ddeb2f0a62.png">
</p>

~~~c++
/*
    The ButtonR class creates a rectangle shaped static-size button, window-resized-not-responsive button.
      
    The button size is computed from the font size and length of the text; 
    the text is automatically centered on the button.
    See mutators to  modify the button’s position, the text’s position in the button, and the button’s size.

    The button's border can be turn on and off.
    the border's size is computed from the font size and length of the text;
    modifying the button's size, we also modify the border's size.

    The button's shadow can be turn on and off.
    The shadow size is computed from the font size and length of the text;
    modifying the button's size, we also modify the shadow's size.

    The default font is raylib font.
      
    Parent class to the ButtonO class
*/
ButtonR button;
~~~
~~~c++
/*
    The ButtonO class creates a rounded edges rectangle shaped static-size button, 
    window-resized-not-responsive button.

    The button size is computed from the font size and length of the text;
    the text is automatically centered on the button.
    See mutators to  modify the button’s position, the text’s position in the button, and the button’s size.

    The button's border can be turn on and off.
    the border's size is computed from the font size and length of the text;
    modifying the button's size, we also modify the border's size.

    The button's shadow can be turn on and off.
    The shadow size is computed from the font size and length of the text;
    modifying the button's size, we also modify the shadow's size.

    The default font is raylib font.
      
    Child class of ButtonR class
*/
ButtonO button;
~~~
~~~c++
/*
    The ButtonP class creates a responsive button from an image.
    (The button resizes with the window)

    The button size is computed from the font size and length of the text;
    the text is automatically centered on the button.
    See mutators to modify the button’s position, the text’s position in the button, and the button’s size.

    The default font is raylib font.
*/
ButtonP button;
~~~
~~~c++
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
MenuR menu;
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

