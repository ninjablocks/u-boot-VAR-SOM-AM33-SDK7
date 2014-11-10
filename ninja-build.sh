[ -d ./var_am335x ] && rm -rf ./var_am335x
make O=var_am335x CROSS_COMPILE=arm-linux-gnueabihf- ARCH=arm var-som-am33_config
make O=var_am335x CROSS_COMPILE=arm-linux-gnueabihf- ARCH=arm
