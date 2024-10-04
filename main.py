import os
import sys

# This is my display name
display_name = "eDP-1"
if len(sys.argv) > 1:
    display_name = sys.argv[1]

# This is the file where brightness is stored
brightness_file = open("/sys/class/backlight/amdgpu_bl2/brightness", "r")
brightness_value = float(brightness_file.read())

# Execute the command to change the brightness
os.system(
    "xrandr --output "
    + display_name
    + " --brightness "
    + str(0.00415019763 * (brightness_value - 255) + 1.25)
)

brightness_file.close()