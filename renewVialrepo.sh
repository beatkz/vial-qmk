#! /bin/bash

if [ "$#" -ne 1 ]; then
    echo "usage: ./renewQMKrepo.sh -mcg"
    echo "-m -> Update MSYS(for Windows Build Environment)"
    echo "-c -> Update QMK CLI"
    echo "-g -> Update Vial Git Repositry"

    exit 1
fi

UPD_MSYS=FALSE
UPD_CLI=FALSE
UPD_GIT=FALSE

OPT=
OPTIND=
while getopts cgm OPT ; do
    case $OPT in
        c) UPD_CLI=TRUE; ;;
        g) UPD_GIT=TRUE; ;;
        m) UPD_MSYS=TRUE; ;;
    esac
done
shift $(expr $OPTIND - 1)

if [ $UPD_MSYS = "TRUE" ] ; then
    #Update for QMK MSYS/MSYS
    pacman -Syu
fi

if [ $UPD_CLI = "TRUE" ] ; then
    #Update for QMK CLI
    pip install -U -r requirements.txt
fi

if [ $UPD_GIT = "TRUE" ] ; then
    #Update for QMK Repo
    git fetch --all
    git merge upstream/vial
    make git-submodule
fi
