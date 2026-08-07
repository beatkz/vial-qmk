#! /bin/bash

TARGET=$1 # キーボードフォルダーまでのフルパスが入る

cp ${PWD}/nicola.h $1/nicola.h
cp ${PWD}/nicola.c $1/nicola.c
cp ${PWD}/key_duration.h $1/key_duration.h
cp ${PWD}/key_duration.c $1/key_duration.c
cp ${PWD}/key_duration_arm.c $1/key_duration_arm.c

