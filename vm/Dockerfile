FROM --platform=linux/amd64 ubuntu

RUN apt-get update && apt-get install -y vim          \
                                         gcc          \
                                         gcc-multilib \
                                         g++          \
                                         g++-multilib \
                                         make         \
                                         python3

WORKDIR /ft_nm
COPY vm/vimrc /etc/vim/vimrc.local

CMD ["/bin/bash"]
