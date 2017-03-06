[![Build Status](https://travis-ci.org/qwertyboy/nsynth.svg?branch=master)](https://travis-ci.org/qwertyboy/nsynth)
## nsynth - teensy 3.2 based noise maker

This project also serves as a repository for useful functions and simple libraries
for the Kinetis K20 microcontrollers. The Teensy 3.2 uses a MK20DX256VLH7 so
everything contained in here is tailored to that, but minimal changes should be
required for other devices.

--------------------------------------------------------------------------------

This project is built using [PlatformIO][pio-home]. Follow the
instructions at the link [here][pio-start] to get started.

Once setup, either upload using the PlatformIO dropdown menu or from the terminal.

![Dropdown Menu][img-dropdown]

or

```
# Build project and upload firmware to the all devices specified in platformio.ini
platformio run --target upload
```

## Useful links
* [K20 Reference Manual][k20-manual]
* [MK20DX256VLH7 Datasheet][mcu-manual]
* [Teensy 3.2 Info][teensy]

[pio-home]: http://platformio.org/
[pio-start]: http://platformio.org/get-started/ide?install
[img-dropdown]: https://github.com/qwertyboy/nsynth/raw/master/img/dropdown.png
[k20-manual]: http://www.nxp.com/assets/documents/data/en/reference-manuals/K20P64M72SF1RM.pdf
[mcu-manual]: http://www.nxp.com/assets/documents/data/en/data-sheets/K20P64M72SF1.pdf
[teensy]: https://www.pjrc.com/teensy/teensy31.html
