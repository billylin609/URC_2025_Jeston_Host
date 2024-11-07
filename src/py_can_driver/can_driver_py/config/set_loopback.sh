#!/bin/bash
# ------------------------------------------------------------------
# [y29lin] Jetson CAN interface loopback configure
#         setup the CAN loopback interface
# .sh Template: https://github.com/RenatGilmanov/shell-script-template
# ------------------------------------------------------------------

VERSION=0.0.1
SUBJECT=ENABLE_LOOPBACK
USAGE="Usage: command -ihv args"

# --- Options processing -------------------------------------------
if [ $# == 0 ] ; then
    echo $USAGE
    exit 1;
fi

while getopts ":i:vh" optname
  do
    case "$optname" in
      "v")
        echo "Version $VERSION"
        exit 0;
        ;;
      "i")
        echo "-i argument: $OPTARG"
        ;;
      "h")
        echo $USAGE
        exit 0;
        ;;
      "?")
        echo "Unknown option $OPTARG"
        exit 0;
        ;;
      ":")
        echo "No argument value for option $OPTARG"
        exit 0;
        ;;
      *)
        echo "Unknown error while processing options"
        exit 0;
        ;;
    esac
  done

shift $(($OPTIND - 1))

param1=$1
param2=$2

# --- Body --------------------------------------------------------
#  SCRIPT LOGIC GOES HERE
echo $param1
echo $param2
# -----------------------------------------------------------------
 
