#!/bin/bash
# ------------------------------------------------------------------
# [y29lin] Jetson CAN interface loopback configure
#         setup the CAN loopback interface
# .sh Template: https://github.com/RenatGilmanov/shell-script-template
# ------------------------------------------------------------------

VERSION=0.0.1
SUBJECT=ENABLE_LOOPBACK
USAGE="Usage: bash set_loopback.sh  [-r default:500000] [-i default:can0] [-v] [-h]"

# --- Options processing -------------------------------------------
if [ $# == 0 ] ; then
    echo "This program requires root previleges"
    echo $USAGE
    exit 1;
fi

while getopts ":r:i:vh" optname
  do
    case "$optname" in
      "v")
        echo "Version $VERSION"
        exit 0;
        ;;
      "r")
	RATE=$OPTARG
        ;;
      "i")
        CAN=$OPTARG
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

# --- Body --------------------------------------------------------
#  SCRIPT LOGIC GOES HERE
if ["$RATE"="100000"] && ["$RATE"="125000"] && ["$RATE"="250000"] && ["$RATE"="500000"] && ["$RATE"="1000000"]; then
    RATE=500000
    echo $RATE
fi
# -----------------------------------------------------------------
 
