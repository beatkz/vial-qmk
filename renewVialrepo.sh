#! /bin/bash

if [ "$#" -ne 1 ]; then
    echo "usage: ./renewVialrepo.sh -mg"
    echo "-m -> Update MSYS(for Windows Build Environment)"
    echo "-g -> Update Vial Git Repositry"

    exit 1
fi

UPD_MSYS=FALSE
UPD_GIT=FALSE

OPT=
OPTIND=
while getopts gm OPT ; do
    case $OPT in
        g) UPD_GIT=TRUE; ;;
        m) UPD_MSYS=TRUE; ;;
    esac
done
shift $(expr $OPTIND - 1)

if [ $UPD_MSYS = "TRUE" ] ; then
    #Update for QMK MSYS/MSYS
    pacman -Syu
fi

if [ $UPD_GIT = "TRUE" ] ; then
    #Update for Vial Repo
    git fetch --all
    git merge upstream/vial
    make git-submodule
fi
