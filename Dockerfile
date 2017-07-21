FROM gcc:latest

# https://askubuntu.com/questions/355565/how-to-install-latest-cmake-version-in-linux-ubuntu-from-command-line
RUN mkdir ~/temp
WORKDIR ~/temp
RUN wget https://cmake.org/files/v3.9/cmake-3.9.0-rc5.tar.gz
RUN tar xzvf cmake-3.9.0-rc5.tar.gz
WORKDIR cmake-3.9.0-rc5
RUN ./bootstrap
RUN make -j4
RUN make install

COPY . /usr/src
WORKDIR /usr/src

RUN cmake . 
RUN make
#CMD ["./bt"]