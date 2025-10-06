#! /bin/bash

TARGET=$1 # キーボードフォルダーまでのフルパスが入る

ln -s ${PWD}/nicola.h $1/keymaps/nicola_vial/nicola.h
ln -s ${PWD}/nicola.c $1/keymaps/nicola_vial/nicola.c
ln -s ${PWD}/key_duration.h $1/keymaps/nicola_vial/key_duration.h
ln -s ${PWD}/key_duration.c $1/keymaps/nicola_vial/key_duration.c

