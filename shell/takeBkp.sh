#!/bin/sh
#VERSION=`cat include/version.h | awk -F: '{print $3}' | awk -F" " '{print $1}'`
VERSION=`cat include/version.h | awk -F\" '{print $2}'`
DIR=`pwd`

echo $#
if [ $# == 0 ];then
	echo " please pass commit msg about this version as arg within double quotes."
	echo " syntax: takeBkp \"comment about this version\" "
	exit
fi	

echo $VERSION
echo $DIR

echo " ">>changelog
echo $VERSION: >> changelog

for i in "$@"
do
echo $i >> changelog
done



tar -X $DIR/exclude -cvjf src_$VERSION.tar.bz2 $DIR/* 
mv src_$VERSION.tar.bz2 $DIR/.
cd $DIR
echo ""
echo ""
echo ""
echo "Backup finished. Please read changelog for more details."
exit
