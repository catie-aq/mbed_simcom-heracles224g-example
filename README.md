# SIMCom Heracles 224G Example
SIMCom Heracles 224G LTE-M module mbed OS driver usage example.

## Requirements
### Hardware requirements
The following boards are required:
- [Zest_Radio_Heracles224G](https://gitlab.com/catie_6tron/zest-core-heracles224g-hardware)

### Software requirements
SIMCom Heracles 224G example makes use of the following libraries (automatically imported
by `mbed deploy` or `mbed import`):
- [SIMCom Heracles 224G](https://gitlab.com/catie_6tron/simcom-heracles224g)

## Usage
To clone **and** deploy the project in one command, use `mbed import` and skip to the
target and toolchain definition:
```shell
mbed import https://gitlab.com/catie_6tron/simcom-heracles224g-example.git simcom-heracles224g-example
```

Define your target (eg. `ZEST_CORE_STM32L4A6RG`) and toolchain:
```shell
mbed target ZEST_CORE_STM32L4A6RG
mbed toolchain GCC_ARM
```

Export to Eclipse IDE with:
```shell
mbed export -i eclipse_6tron
```

Or compile the project directly from command line:
```shell
mbed compile
```
