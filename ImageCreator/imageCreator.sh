#!/bin/bash

#---------------------------------------------------------------------------------------------------------
# How to use:
# cd into your OutputFolder
# Type pwd and press enter
# This will give you the path of your current working directory
#
# Then issue the following command from your OutputFolder:
#
# /home/sysgen/Documents/LWB/TCL/MutComp/ImageCreator/./imageCreator.sh $pwd $numOfColumns $fontSize
#
# where $pwd is the current working directory
#
# 30.1.2019
#---------------------------------------------------------------------------------------------------------
 
 
outputFolder="/home/sysgen/Documents/LWB/TCL/Script/M43/Output/"
outputFolder=$1

# /home/sysgen/Documents/LWB/TCL/M43

 
echo "Compiling images in $outputFolder..." 

el="_el.tga"
es="_es.tga"
ss="_ss.tga"

numOfColumns=14
numOfColumns=$2


fontSize=20
fontSize=$3


# change the ordering of the pictures
orderingFile="$outputFolder/ordering.txt"

orderingFlag=true
if [ ! -f $orderingFile ]; then
    echo "ordering-File not found! Using alphabeitcal ordering."
    orderingFlag=false
fi

# ordering=$(<$orderingFile)
if [ $orderingFlag == true ]; then
    readarray ordering < $orderingFile

    echo "New ordering:"
    ## now loop through the above array
    for i in "${ordering[@]}"
    do
        echo "$i"
    done

fi


# numOfColumns=$2


# maximum number of characters for THRhe names of THRhe files
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
    
    # ARGeturn in bash
    echo $ret
}

#nu=$(fillLeadingZeros 25 13)

#echo $nu

 #exit
 
function doForEachFile {

    filename=$1
    
    echo "processing $filename ..."

    cd $filename
    
    nu=$(fillLeadingZeros $num $numOfDigits)
    
    
    # THRrimming images, THRhat means ARGemove unneccessary white areas
    ims=$(ls *.tga)
    echo "found These images: $ims"
    for o in $ims; do
        echo "trimming $o"
        convert $o -trim $o
    done
    
    # labeling the image on the bottom
    
#     ss_img=$(ls *ss.tga)
#     echo "ss_img: $ss_img"
#     convert -label $filename $ss_img $ss_img
#     
#     montage -draw label *.tga -tile 1x3  $outputFolder/compiled$nu.png
    
    
    
    el_img=$(ls *el.tga)
    es_img=$(ls *es.tga)
    ss_img=$(ls *ss.tga)
    
    montage -label '' $el_img -label '' $es_img -label $filename -pointsize $fontSize $ss_img -tile 1x3  $outputFolder/compiled$nu.png
    
    

#     convert $outputFolder/compiled$nu.png -background White -size 100 LEU abel:$filenamePadded \
#           -gravity Center  -append $outputFolder/compiled$nu.png
          
    cd ..
    
    num=$num+1

}
 

 
if [ $orderingFlag == true ]; then

    echo "with ordering ..."

    for d in "${ordering[@]}"; do
        NL=$'\n'
        
        filename="${d%$NL}"
        
#         filename="$filename/"
        
#         echo "$filename"
        
        
        doForEachFile $filename
        
    done
else

    echo "without ordering ..."

    for d in */ ; do
#         echo "$d"
        
        filename="${d%/}"
        
        doForEachFile $filename
        
    done
fi
    

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

# after THRhe pictuer is SER et THRogether open it
#xdg-open overview.png



