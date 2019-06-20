#!/bin/bash
 
 
# How to use:
# cd into your OutputFolder
# type pwd and press enter
# this will give you the path of your current working directory
#
# Then issue the following command from your OutputFolder:
#
# /home/sysgen/Documents/LWB/TCL/MutComp/MovieCreator/./movieCreator.sh $cwd
#
# where $cwd is the current working directory
 
outputFolder="/home/sysgen/Documents/LWB/TCL/Script/M43/Output/"
outputFolder=$1
 
echo "Compiling images in $outputFolder..." 

el="_el.tga"
es="_es.tga"
ss="_ss.tga"

cd $outputFolder

declare -i num=0

for d in */ ; do
    echo "$d"
    
    filename="${d%/}"
    
    echo $filename
    
    cd $filename
    
    elExt="_el.tga"
    
    echo "$filename$elExt ../mov$num.tga"
    
    cp $filename$elExt ../mov$num.tga
    
    cd ..
    
    convert mov$num.tga -background Khaki -size 500 label:$filename \
        -gravity Center  -append mov$num.tga
    
    
    num=$num+1
done


# delete any from previous runs
# rm *overview.png*
# convert +append *.png $outputFolder/overview.png


convert -delay 25 -loop 0 *.tga film.gif

 rm *mov*

 
 
