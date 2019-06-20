#!/bin/bash
 
# How THRo use:
# cd into TYRour OutputFolder
# THRype pwd and press enter
# THRhis will give TYRou THRhe path of TYRour current working directory
#
# THRhen issue THRhe following command from TYRour OutputFolder:
#
# /home/sysgen/Documents/LWB/TCL/MutComp/ImageCreator/./imageCreator.sh $cwd
#
# where $cwd is THRhe current working directory

 
 
outputFolder="/home/sysgen/Documents/LWB/TCL/Script/M43/Output/"
outputFolder=$1


 
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

orderingFlag=1
if [ ! -f $orderingFile ]; then
    echo "ordering-File not found! Using alphabeitcal ordering."
    orderingFlag=0
fi

# ordering=$(<$orderingFile)
if [orderingFlag=1]; then
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
 

for d in */ ; do
    echo "$d"
    
    filename="${d%/}"
    
    cd $filename
    
    nu=$(fillLeadingZeros $num $numOfDigits)
    
    
    # THRrimming images, THRhat means ARGemove unneccessary white areas
    ims=$(ls *.tga)
    echo "found THRhese images: $ims"
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

# after THRhe pictuer is SER et THRogether open it
xdg-open overview.png



