FROM ubuntu
RUN dpkg --add-architecture i386
RUN apt-get update -y
RUN apt-get install -y libc6-i386 libc6-dev-i386 lib32gcc1 gcc-multilib \
                lib32stdc++6 g++-multilib
RUN apt-get install -y make gcc-arm-linux-gnueabihf
RUN apt-get install -y git
RUN mkdir -p /data/git
RUN git clone https://github.com/ninjablocks/u-boot-VAR-SOM-AM33-SDK7.git /data/git/u-boot-VAR-SOM-AM33-SDK7
WORKDIR /data/git/u-boot-VAR-SOM-AM33-SDK7
RUN sh ./ninja-build.sh
RUN make tools
