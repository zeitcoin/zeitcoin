#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/Zeitcoin.ico

convert ../../src/qt/res/icons/Zeitcoin-16.png ../../src/qt/res/icons/Zeitcoin-32.png ../../src/qt/res/icons/Zeitcoin-48.png ${ICON_DST}
