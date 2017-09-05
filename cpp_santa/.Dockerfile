FROM antoinebaudrand/blinux:latest
MAINTAINER Valentin Pichard <valentin.pichard@epitech.eu>

# Add local sources
COPY . /cpp_santa
WORKDIR /cpp_santa

RUN make re

ENTRYPOINT ["./bonus/run-tests.sh"]
