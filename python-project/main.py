import os

# get the brightness file
# you can create a symbolic link

display_name = "eDP"

while True:
    brightness_file = open("/sys/class/backlight/amdgpu_bl1/brightness", "r")
    prev_brightness_file = open("previous_brightness_val.txt", "r")

    prev_brightness_val = float(prev_brightness_file.read())
    current_brightness_val = float(brightness_file.read())

    if current_brightness_val - prev_brightness_val != 0:
        # equation:
        # push_float = 0.00415019763 * (current_brightness_val - 255) + 1.25;
        os.system(
            "xrandr --output "
            + display_name
            + " --brightness "
            + str(0.00415019763 * (current_brightness_val - 255) + 1.25)
        )

        prev_brightness_file = open("previous_brightness_val.txt", "w")
        prev_brightness_file.write(
            str(0.00415019763 * (current_brightness_val - 255) + 1.25)
        )

    brightness_file.close()
    prev_brightness_file.close()
