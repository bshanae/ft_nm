#!/bin/sh

docker rmi -f ft_nm
docker image build -t ft_nm -f vm/Dockerfile .
