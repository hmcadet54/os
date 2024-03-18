#!/bin/bash

name="abdullah"
echo $name

age=18

if [ $age -eq 18 ] && [ $name == "abdullah1" ]; then
	echo "Yes"
else
	echo "no"
fi

#-eq=equals to
#-ne= not equals to
#-gt= greater than
#-lt= less than
# if [ -f $filename ]
	# echo exist
# if [ -d $foldername ]
	# echo exist
