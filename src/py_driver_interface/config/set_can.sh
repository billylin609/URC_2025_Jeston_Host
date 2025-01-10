#!/bin/bash
# ------------------------------------------------------------------
# [y29lin] Jetson CAN interface configure
#         setup the CAN interface
# .sh Template: https://github.com/RenatGilmanov/shell-script-template
# ------------------------------------------------------------------

VERSION=0.0.1
SUBJECT=ENABLE_CAN
USAGE="Usage: bash set_loopback.sh  [-r default:500000] [-i default:can0] [-v] [-h]"

RATE=0
CAN=""

# --- Options processing -------------------------------------------
echo "This program requires root previleges"

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
if [ $RATE != 100000 ] && [ $RATE != 125000 ] && [ $RATE != 250000 ] && [ $RATE != 500000 ] && [ $RATE != 1000000 ]
then
    echo "Unable to find the matching CAN rate > SET to DEFAULT"
    RATE=500000
fi

if [ "$CAN" == "" ]
then
    CAN="can0"
else
    echo "$CAN" | tr '[:upper:]' '[:lower:]'
    if [ "$CAN" != "can0" ] && [ "$CAN" != "can1" ]; then
        CAN="can0"
    fi
fi

echo "CONFIG: Interface $CAN transmission rate $RATE"

ip link set $CAN down
ip link set $CAN type can bitrate $RATE
ip link set $CAN up
candump $CAN &
# -----------------------------------------------------------------
 
