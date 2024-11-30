`faust -lang c -o flanger.h flanger.dsp`
`make CHIP=bl616 BOARD=bl616dk && make flash CHIP=bl616 COMX=/dev/cu.usbmodem1401`