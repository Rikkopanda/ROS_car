#!/usr/bin/env python

import struct


infile_path = "/dev/input/js0"
EVENT_SIZE = struct.calcsize("LhBB")
file = open(infile_path, "rb")
event = file.read(EVENT_SIZE)
while event:
    print(struct.unpack("LhBB", event))
    (tv_msec,  value, type, number) = struct.unpack("LhBB", event)
    event = file.read(EVENT_SIZE)
