#!/bin/bash

ARG=$1

if [ ! -x ../push_swap ]; then
	make -C ../
fi
.././push_swap $ARG
printf "\nmovements: " 
.././push_swap $ARG | wc -l | tr " " "\0"
.././push_swap $ARG | ./42checker_Mac.dms $ARG
