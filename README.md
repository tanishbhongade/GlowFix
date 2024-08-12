## Backlight Control Project   
The project is to control backlight on laptops which have brightness control issues running X11 windowing system \
I recommend using the Python project; Also give a read to the documentation on how this project works, it'll give you a good understanding of this small project.

Steps:
1. Copy the repository inside /usr/local/bin
2. Move the desktop file in /usr/share/applications
3. Edit the desktop file and add the file path in Exec variable in desktop file
4. Update the desktop database using the command sudo update-desktop-database
5. Add the new application to autostart (depending upon your desktop environment, the way to add the app to autostart list will change, or you can do that manually by moving desktop file to .config/autostart directory in home directory of user)
6. Reboot your system and make sure to login with xorg, as this will only work on xorg, not on wayland.
