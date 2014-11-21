#!/bin/sh

lock() {
    xprop > /dev/null &&
    lock
}

lock
