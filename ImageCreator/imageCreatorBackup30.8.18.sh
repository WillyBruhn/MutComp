#!/bin/bash
 
# How to use:
# cd into your OutputFolder
# type pwd and press enter
# this will give you the path of your current working directory
#
# Then issue the following command from your OutputFolder:
#
# /home/sysgen/Documents/LWB/TCL/MutComp/ImageCreator/./imageCreator.sh $cwd
#
# where $cwd is the current working directory

 
 
outputFolder="/home/sysgen/Documents/LWB/TCL/Script/M43/Output/"
outputFolder=$1
 
echo "Compiling images in $outputFolder..." 

el="_el.tga"
es="_es.tga"
ss="_ss.tga"

numOfColumns=15

# maximum number of characters for the names of the files
# charMax=10

cd $outputFolder

declare -i num=0
#rm *compiled*


declare -i numOfFolders=0
numOfFolders=$(ls -l . | grep -c ^d)

echo $numOfFolders

numOfDigits=${#numOfFolders}

echo $numOfDigits

function fillLeadingZeros {
    num=$1
    numOfDigits=${#num}
    
    numOfTotalDigits=$2
    
    printf -v ret "%0${numOfTotalDigits}d" $num
    
    # return in bash
    echo $ret
}

#nu=$(fillLeadingZeros 25 13)

#echo $nu

 #exit
 

for d in */ ; do
    echo "$d"
    
    filename="${d%/}"
    
    cd $filename
    
    nu=$(fillLeadingZeros $num $numOfDigits)
    
    
    ims=$(ls *.tga)
    
    echo "found these images: $ims"
    
    for o in $ims; do
        echo "trimming $o"
        convert $o -trim $o
    done
    
    
    
    montage *.tga -tile 1x3   $outputFolder/compiled$nu.png
    
#     montage *.tga   $outputFolder/compiled$nu.png
    
    
    
    # before 30.8.18
#     convert -append *.tga $outputFolder/compiled$nu.png
    

    filenamePadded=$(printf "%-10s" $filename)

    
    echo "filenamePadded: $filenamePadded ..."
    
    filenamePadded=$(printf "$filenamePadded" | tr ' ' a)
    
    
    echo "filenamePadded: $filenamePadded ..."

    convert $outputFolder/compiled$nu.png -background White -size 100 label:$filenamePadded \
          -gravity Center  -append $outputFolder/compiled$nu.png
          
          
    
    
    
    
    
    cd ..
    
    num=$num+1
done


# Creating the rows of length numOfColumns
c=0
rowCount=0
list=""


# might be problematic if we want to have more than 10 rows
# need to padd with 0s just like in the loop above

for d in compiled*.png ; do
    echo "$d"
    ((c++))
    list="$list $d"
    if [ $c == $numOfColumns ]
    then
        convert +append $list row$rowCount.png
        list=""
        ((rowCount++))
        c=0
    fi
done
convert +append $list row$rowCount.png


# delete any from previous runs
rm *overview.png*
convert -append row*.png overview.png



rm *compiled*
rm row*.png
