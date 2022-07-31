#!/bin/sh

expected=$(nm "$@")
actual=$(../main/ft_nm "$1")

if [ "$expected" = "$actual" ]; then
	echo "OK"
else
	echo "KO"
	echo "EXPECTED:"
	echo "$expected"
	echo "ACTUAL:"
    echo "$actual"
fi