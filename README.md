# GlowFix   
The project is to control backlight on laptops which have brightness control issues running X11 windowing system

## Dependencies
<ul>
<li>xorg </>
<li>inotify-tools</li>
</ul>

## Installing the project
<ol>
<li>Run the installer.sh script</li>
<li>Add the app GlowFix to autostart section of your desktop environment</li>
</ol>

## Debugging the issues
<ul>
<li>
I've considered the directory under /sys/class/backlight to be amdgpu_bl2 <br>
Now you should change this directory to whatever it is in your laptop in the main.py file
</li>
<li>
There is also a display name variable in main.py <br>
Now based on your display, the value of variable will change <br>
Use the command xrandr in order to find the name of your display and put the name in python file <br>
You can also modify the glowfix.sh in the way that the display name parameter is passed itself while it runs main.py
</li>
</ul>
