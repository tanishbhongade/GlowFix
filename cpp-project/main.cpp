#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
	// // Do not mistake yourself with default backlight file. It is previous brightness file here
	// std::ifstream default_backlight_file_init("prev_brightness_val.txt");
	// string push_string_init;
	// float push_float_init;

	// default_backlight_file_init >> push_string_init;
	// push_float_init = 0.00415019763 * (stoi(push_string_init) - 255) + 1.25;
	// push_string_init = "xrandr --output eDP-1 --brightness " + to_string(push_float_init);

	// std::system(push_string_init.c_str());
	// default_backlight_file_init.close();

	while (true)
	{
		std::ifstream default_backlight_file("/sys/class/backlight/amdgpu_bl1/brightness");
		std::ifstream prev_brightness_file("prev_brightness_val.txt");
		float change, push_float;
		string push_string;

		// Variables for previous brightness values
		float previous_b_val;
		string previous_b_string;

		// Variables for current brightness values
		float current_b_val;
		string current_b_string;

		// DO NOT MODIFY THE CONTENT BELOW
		// These lines of code are responsible for getting the previous and new brightness values

		// Store the previous brightness value in current_b_string variable
		prev_brightness_file >> previous_b_string;
		// Convert the string into float using stof()
		previous_b_val = stof(previous_b_string);


		// Store the current brightness value in current_b_string variable
		default_backlight_file >> current_b_string;
		// Convert the string into float using stof()
		current_b_val = stof(current_b_string);

		// Close the previously opened files
		default_backlight_file.close();
		prev_brightness_file.close();
		// DO NOT MODIFY THE CONTENT ABOVE

		change = current_b_val - previous_b_val;
		
		// If the brightness value has changed then only execute the below code
		if (change != 0)
		{
			// Open the previous brightness file and to push the new brightness value to it
			std::ofstream prev_brightness_file_2("prev_brightness_val.txt");

			// Calculate the float required for xrandr
			push_float = 0.00415019763 * (current_b_val - 255) + 1.25;

			// Make a string of command to run
			push_string = "xrandr --output eDP-1 --brightness " + to_string(push_float);

			// Make the system execute my command
			std::system(push_string.c_str());

			// Push the changes to it
			prev_brightness_file_2 << to_string(current_b_val);

			// Close the file
			prev_brightness_file_2.close();
		}
	}

	return 0;
}
