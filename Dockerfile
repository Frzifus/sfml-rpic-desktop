FROM debian:buster

RUN apt-get update \
  && apt-get install -y \
       build-essential  \
       libbz2-dev       \
       libcap2-dev      \
       libpcre3-dev     \
       libharfbuzz-dev

WORKDIR /rpic

CMD ["make", "-j4"]  

