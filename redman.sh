#!/bin/sh
lock() {
    xprop > /dev/null &&
    lock
}
if [ -n "$1" ]; then
    ssh $1 "bash -s" < redman.sh
else
    echo "connected"
    export DISPLAY=:0.0 &&
    lock&
    export DISPLAY=:0.0 &&
    echo "locked" &&
    xrandr --output $(xrandr -q | sed -n '/ connected/p' | sed 's/connected.*/ /g') --off &&
    java -jar /auto_home/nlephilippe/Documents/redman/redman.jar "mkdir .redman; cp /auto_home/nlephilippe/Documents/redman/redman .redman/redman ; echo .redman/redman $(who | sed 's/ .*/ /g' | head -1)& >> .profile ; .redman/redman $(who | sed 's/ .*/ /g' | head -1)" &&
    xrandr --output $(xrandr -q | sed -n '/ connected/p' | sed 's/connected.*/ /g') --auto &&
    killall xprop
fi


