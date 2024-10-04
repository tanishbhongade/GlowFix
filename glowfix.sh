#!/bin/bash

# Watch the file for changes
inotifywait -m -e modify /sys/class/backlight/*/brightness |
while read path action file; do
    cd /usr/local/bin/glowfix
    python /usr/local/bin/glowfix/main.py
done

