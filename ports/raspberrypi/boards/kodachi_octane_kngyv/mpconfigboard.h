/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Scott Shawcroft for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*****
 * This is part of the support package for the Kodachi 6*14 Octane KnGYV
 * Dactyl Manuform keyboard.
 */

// The Octane is a Pawboard. All Pawboards are built on a Raspberry Pi RP2040,
// and the Octane model identifies itself as "Pawboard Octane KnGYV".
#define MICROPY_HW_BOARD_NAME "Pawboard Octane KnGYV"
#define MICROPY_HW_MCU_NAME "rp2040"

// When in development mode, the Octane's internal filesystem shows up as
// "OCTANE_L" or "OCTANE_R" depending on which half of the board you're looking
// at. We'll build it here as "OCTANE".
#define CIRCUITPY_DRIVE_LABEL "OCTANE"

// The Octane has a single Neopixel on GPIO25, since it's using a SparkFun Pro
// Micro RP2040 internally. We'll let CircuitPython use that for status --
// it's helpful for debugging.
#define MICROPY_HW_NEOPIXEL (&pin_GPIO25)
#define MICROPY_HW_NEOPIXEL_COUNT (1)

// We can't support I2C on this board, sadly. The only spare pins are GPIO28
// and GPIO29, which don't support I2C.
