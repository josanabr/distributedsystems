#!/bin/bash
if [ $# == 0 ]; then
	echo "dummy execution"
        exit 1
fi
if [ ! -x $1 ]; then
	echo "${1} is not an executable file"
	exit 2
fi
for i in 1 2 3 4 5; do
	./$1
done
