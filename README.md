# SFML-Snake

This game was developed using SFML in C++. It has a basic game engine that controls the snake and has tools for managing background and timing, boundary detection and collisions, and of course sprites. The following was used to develop and play the game.

**Visual Studio Professional 2019:**

- Software can be downloaded from Microsoft are the following link:  [https://visualstudio.microsoft.com/vs/](https://visualstudio.microsoft.com/vs/)
- Note that this is licensed software and if the "Community" version is not selected, Microsoft will require payment for the licensing of the product

**SFML 2.5.1:**

- Downloaded this software from the SFML Dev website as shown below: [https://www.sfml-dev.org/download/sfml/2.5.1/](https://www.sfml-dev.org/download/sfml/2.5.1/)

After downloading the SFML 2.5.1 folder you will need to extract it and follow the next few steps to set up the rest of the project so that the dependencies will be linked correctly

1. Rename the SFML\_2.5.1 folder to SFML and move that folder to your main drive&#39;s root folder
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- The path should look something like this &quot;C:\SFML&quot;</br>
2. Create an &quot;Empty Project&quot; and name it something generic like &quot;sfml19&quot; in Visual Studio 2019 and then create a blank .cpp file to hold your main function.
3. In the Solution Explorer tab on the right pane of Visual Studio, right click on the project name (sfml19 if you used that in step 2) and choose the option properties from the context menu
4. Choose All Configurations from the drop-down menu in the upper left (Figure 1.1 below)
5. Choose &quot;General&quot; option under C/C++ in the panel on the left (Figure 1.1 below)
6. Add the directory where the SFML/include files are in the root of your main drive
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- For example, &quot;C:\SFML\include&quot; (Figure 1.1 below)</br>

![Figure 1](/images/Figure1.png "Figure 1")

<p align="center">
    Figure 1
</p>

1. Select the Linker option (may need to expand the subtree), and then the general option from the subree. (Figure 1.2 below)
2. Locate Additional Library Directories and then similarly to step 6, add the path to the lib directory within the SFML folder on your root drive
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- For example, &quot;C:\SFML\lib&quot; (Figure 1.2 below)</br>

![Figure 2](/images/Figure2.png "Figure 2")

<p align="center">
    Figure 2
</p>

1. Switch the option for configuration to &quot;Debug&quot; as shown below and go back to the Linker-\&gt;Input option, click the drop-down menu for additional dependencies and click edit. (Figure 3 Below)

![Figure 3](/images/Figure3.png "Figure 3")

<p align="center">
    Figure 3
</p>

1. Add the dependencies listed below to the front of the list
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-sfml-graphics-d; sfml-window-d.lib; sfml-system-d.lib; sfml-network-d.lib; sfml-audio-d.lib;
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- Make sure not to delete any of the dependencies that were there before
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- Click OK and complete this section of the set up</br>
2. Next copy all the .dll files from the C:\SFML\bin folder into your project directory with your main file.

![Figure 4](/images/Figure4.png "Figure 4")

<p align="center">
    Figure 4
</p>

1. The files are shown in separate folders above, you will need to add all the files in the right folder, to the one on the left
2. Now that you have done all of these steps, the final step is to take the code files, font files, and music files that were turned in and add them to the projects folder next to the .dll files

From here all you will need to do is click the Local Debugging Window button in the toolbar, or click on the Debug drop-down menu from the top toolbar and click local debugging window. You can also run it without debugging and using hot keys F5 (local window debugging) and Ctrl+F5 (run without debugging).
