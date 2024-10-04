#!/bin/bash

# Watch the file for changes
inotifywait -m -e modify /sys/class/backlight/*/brightness |
while read path action file; do
    # Run your script or command
    # /usr/local/bin/my-brightness-adjuster/smart-brightness-adjuster
    cd /usr/local/bin/my-brightness-adjuster
    python /usr/local/bin/my-brightness-adjuster/main.py
done

