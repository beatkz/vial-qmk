#! /bin/bash

if [ "$#" -ne 1 ]; then
    echo "usage: ./renewVialrepo.sh -amdg"
    echo "-a -> Update Debian based Distro(apt)"
    echo "-m -> Update MSYS(for Windows Build Environment)"
    echo "-d -> Update RHEL based Distro(dnf)"
    echo "-g -> Update Vial Git Repositry(add official repo as 'upstream' first)"

    exit 1
fi

UPD_APT=FALSE
UPD_MSYS=FALSE
UPD_DNF=FALSE
UPD_GIT=FALSE

OPT=
OPTIND=
while getopts adgm OPT ; do
    case $OPT in
        a) UPD_APT=TRUE; ;;
        m) UPD_MSYS=TRUE; ;;
        d) UPD_DNF=TRUE; ;;
        g) UPD_GIT=TRUE; ;;
    esac
done
shift $(expr $OPTIND - 1)

if [ $UPD_APT = "TRUE" ] ; then
    #Update for Debian based Distro
    sudo apt update && sudo apt -y upgrade
fi

if [ $UPD_MSYS = "TRUE" ] ; then
    #Update for QMK MSYS/MSYS
    pacman -Syu --noconfirm
fi

if [ $UPD_DNF = "TRUE" ] ; then
    #Update for RHEL based Distro
    sudo dnf -y update
fi

if [ $UPD_GIT = "TRUE" ] ; then
    #Update for Vial Repo
    git fetch --all
    git merge --no-edit upstream/vial
    make git-submodule
fi
