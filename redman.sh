#!/bin/sh

if [ -n "$1" ]; then
    ssh $1 "bash -s" < redman.sh
else
    export DISPLAY=:0.0 &&
    xrandr --output $(xrandr -q | sed -n '/ connected/p' | sed 's/connected.*/ /g') --off &&
    java -jar redman.jar "firefox" &&
    xrandr --output $(xrandr -q | sed -n '/ connected/p' | sed 's/connected.*/ /g') --auto
fi

