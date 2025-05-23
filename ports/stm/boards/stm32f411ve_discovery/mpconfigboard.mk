USB_VID = 0x239A
USB_PID = 0x805E
USB_PRODUCT = "STM32F411VE Discovery Board - CPy"
USB_MANUFACTURER = "STMicroelectronics"

INTERNAL_FLASH_FILESYSTEM = 1

MCU_SERIES = F4
MCU_VARIANT = STM32F411xE
MCU_PACKAGE = LQFP100_f4

OPTIMIZATION_FLAGS = -Os

LD_COMMON = boards/common_default.ld
LD_FILE = boards/STM32F411_fs.ld

# Too big for the flash
CIRCUITPY_AESIO = 0
CIRCUITPY_AUDIOCORE = 0
CIRCUITPY_AUDIOPWMIO = 0
CIRCUITPY_BITMAPFILTER = 0
CIRCUITPY_BITMAPTOOLS = 0
CIRCUITPY_BLEIO_HCI = 0
CIRCUITPY_CODEOP = 0
CIRCUITPY_MSGPACK = 0
CIRCUITPY_VECTORIO = 0
