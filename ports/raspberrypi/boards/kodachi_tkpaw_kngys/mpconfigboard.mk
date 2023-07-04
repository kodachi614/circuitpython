# This file is part of the MicroPython project, http://micropython.org/
#
# The MIT License (MIT)
#
# Copyright (c) 2021 Scott Shawcroft for Adafruit Industries
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
# This is part of the support package for the Kodachi 6*14 TKPaw KnGYS.

# This is the Raspberry Pi VID/PID for "Raspberry Pi Pico CircuitPython
# firmware" per https://github.com/raspberrypi/usb-pid. The TKPaw isn't
# actually a Pi Pico; this is a temporary thing while we're applying for
# a real VID/PID.
USB_VID = 0x2E8A
USB_PID = 0x000B

# TKPaw KnGYS product & manufacturer.
USB_PRODUCT = "TKPaw KnGYS"
USB_MANUFACTURER = "Kodachi 6 14 LLC"

# The TKPaw is based on an RP2040...
CHIP_VARIANT = RP2040
CHIP_FAMILY = rp2

# ...and it uses a Winbond 16MB flash.
EXTERNAL_FLASH_DEVICES = "W25Q128JVxQ"

# # This includes support for the EVE module. Huh. Do we need this?
# CIRCUITPY__EVE = 1
