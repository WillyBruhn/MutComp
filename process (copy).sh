#!/bin/bash


#----------------------------------------------------------------------------------------------------------
# date: 11/24/2017
# author: Willy Bruhn
# contact: willy.bruhn@gmx.de
#
# MutComp
# A shell script for automized processing of pdb-files with vmd http://www.ks.uiuc.edu/Research/vmd/ and APBS http://www.ks.uiuc.edu/Research/vmd/plugins/apbsrun/.
# 
# Features:
# * pdb files are converted to pqr-files.
# * the electrostatics are calculated
# * creates one big picture containing the es,el,ss pictures of all the input molecules 
# * creates a gif containing all el -pictures
#----------------------------------------------------------------------------------------------------------

#----------------------------------------------------------------------------------------------------------
# Command line arguments.
#----------------------------------------------------------------------------------------------------------

# Specifies by how much the frame should be translated before rendering
x_shift=0
y_shift=0
z_shift=0

x_shift=$1
y_shift=$2
z_shift=$3


# Specifies by how much the frame should be rotatetd before rendering
x_rot=0
y_rot=0
z_rot=0

x_rot=$4
y_rot=$5
z_rot=$6

#----------------------------------------------------------------------------------------------------------
# Path configuration
#----------------------------------------------------------------------------------------------------------

ABSOLUTE_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/"

# In case we have a symlink on the system, we can call the script with just process
# Need to get rid of the name of the script itself
repositoryPath=$(readlink -f $ABSOLUTE_PATH/process)
repositoryPath="${repositoryPath%process.sh}"


echo "repositoryPath = $repositoryPath"
echo $ABSOLUTE_PATH

currentWorkingDir=$ABSOLUTE_PATH

currentWorkingDir=$PWD

inputFolder="$currentWorkingDir/Input/"
OutputFolder="$currentWorkingDir/Output/"


#pathToTclScript="/home/sysgen/Documents/LWB/TCL/Script/TclScripts"
#pathToVmdExe="/home/sysgen/bin/VMD/"
#apbsParametersReference="/home/sysgen/Documents/LWB/TCL/Script/M43/Input/apbsParameters/apbsReference.in"
#pathToImageCreator="/home/sysgen/Documents/LWB/TCL/Script/ImageCreator/"
#pathToMovieCreator="/home/sysgen/Documents/LWB/TCL/Script/MovieCreator/"


pathToTclScript="$repositoryPath/TclScripts"
# pathToVmdExe="/home/sysgen/bin/VMD/"
pathToVmdExe=""
apbsParametersReference="$repositoryPath/APBS/apbsReference.in"
pathToImageCreator="$repositoryPath/ImageCreator/"
pathToMovieCreator="$repositoryPath/MovieCreator/"



pathToPdbs=""
pathToPqrs=""
OutputFolder=""
PathToMutComp=""
PathToVMD=""
VMDcall=""

doCreateTrainingsSet="true"
doImageCreator="true"
doMovieCreator="true"
doPdbToPqr="true"
doVMD="true"

MutCompLog=""

NumOfThreads=2


#----------------------------------------------------------------------------------------------------------
# Check if vmd-path is correctly configured.
# Abbort with error-message, if vmd is not under the specified path.
# TODO
#----------------------------------------------------------------------------------------------------------



#----------------------------------------------------------------------------------------------------------
# Read in all Parameters.
# There should be one parameters-file. ; separated
# The GUI modifies this file.
#----------------------------------------------------------------------------------------------------------
parametersFile="/home/willy/RedoxChallenges/MutComp/GUI/Parameters/parameters.txt"
echo "reading in parameters from $parametersFile"

echo "found the following parameters..."
echo "parmameter          value"
echo "-----------------------------------------------------------"
IFS=";"
while read parameter value
do
        echo "$parameter              $value"

	if [ "$parameter" == "MutCompInputFolder" ]; then
		inputFolder=$value
	fi

	if [ "$parameter" == "MutCompPdbs" ]; then
		pathToPdbs=$value
	fi

	if [ "$parameter" == "MutCompPqrs" ]; then
		pathToPqrs=$value
	fi

	if [ "$parameter" == "MutCompLog" ]; then
		MutCompLog=$value
	fi

	if [ "$parameter" == "MutCompOutputFolder" ]; then
		OutputFolder=$value
	fi

	if [ "$parameter" == "PathToMutComp" ]; then
		PathToMutComp=$value
	fi

	if [ "$parameter" == "PathToVMD" ]; then
		PathToVMD=$value
	fi

	if [ "$parameter" == "VMDcall" ]; then
		VMDcall=$value
	fi

	if [ "$parameter" == "doCreateTrainingsSet" ]; then
		doCreateTrainingsSet=$value
	fi

	if [ "$parameter" == "doImageCreator" ]; then
		doImageCreator=$value
	fi

	if [ "$parameter" == "doMovieCreator" ]; then
		doMovieCreator=$value
	fi

	if [ "$parameter" == "doPdbToPqr" ]; then
		doPdbToPqr=$value
	fi

	if [ "$parameter" == "doVMD" ]; then
		doVMD=$value
	fi

done < $parametersFile

#----------------------------------------------------------------------------------------------------------
# Check if folder-hierarchy is correct
#----------------------------------------------------------------------------------------------------------

#if [ ! -d "Input" ]; then
#  echo "Input folder not found. exiting ..."
#  exit 1
#fi

#if [ ! -d "./Input/pdb/" ]; then
#  echo "Folder /Input/pdb/ not found. exiting ..."
#  exit 1
#fi

#if [ ! -d "./Input/pqr/" ]; then
#  echo "Folder /Input/pqr/ not found. exiting ..."
#  exit 1
#fi

#----------------------------------------------------------------------------------------------------------
# Converting all files from pdb to pqr
#----------------------------------------------------------------------------------------------------------

if [ "$doPdbToPqr" == "true" ]; then
	echo "Converting pdb to pqr in $pathToPdbs ..."

	cd $pathToPdbs
	for i in *pdb; do
		[ -f "$i" ] || break
		
		filename="${i%.*}"
	 
		#pdb2pqr --ff amber $filename.pdb $pathToPqrs $filename.pqr

		pdb2pqr --ff amber $filename.pdb "$pathToPqrs/$filename.pqr" >> "$MutCompLog"
	  
	  
	#     echo pdb2pqr --ff amber $inputFolder"pdb/"$filename.pdb $inputFolder"pqr/"$filename.pqr

	#     pdb2pqr --ff amber 1fov-01-D34K.pdb /home/sysgen/Documents/LWB/TCL/Script/Input/pqr/1fov-01-D34K.pqr

	# pdb2pqr --ff amber /home/sysgen/Documents/LWB/TCL/Script/Input/pdb/1fov-01-D34K.pdb /home/sysgen/Documents/LWB/TCL/Script/Input/pqr/1fov-01-D34K.pqr
		
	done

	echo "...Done converting pdb2pqr"

else 

	echo "skipping to convert pdb to pqr"
	
fi


#----------------------------------------------------------------------------------------------------------
# Vmd and APBS
# Creates a .dx file for each pqr-file
# each molecule is orientated in a certain way 
# el
# es
# ss
# -pictures are generated from the specified orientation
#----------------------------------------------------------------------------------------------------------

if [ "$doVMD" == "true" ]; then

	cd $pathToPqrs

	#----------------------------------------------------------------------------------------------------------
	# Make sure there are any files
	#----------------------------------------------------------------------------------------------------------
	count=`ls -1 *.pqr 2>/dev/null | wc -l`
	if [ $count == 0 ]
	then 
		echo "No Pqrs found. in $PWD exiting..."
		exit 1
	fi 


	for i in *.pqr; do
		[ -f "$i" ] || break

		
		
		filename="${i%.*}"

		dirName=$OutputFolder/$filename/
		echo "creating dir $dirName"
		mkdir $dirName
		
		
		# This is the apbs that is going to be written into
		# outFileApbs=""
		
		# Read in the reference APBS-apbsParameters
		# change some lines that specify the name of the molecule
		# write the file in the newley created directory in "apbs.in"
		# start apbs with this new parameters file
		
		# since we append all the lines on-the-fly, first make sure we have a new 
		# file and don't append to an allready existing one
		[ -e "$dirName/apbs.in" ] && rm "$dirName/apbs.in"
		
		# read in the reference
		while read -r line
		do
		    # change the input filename accordingly
		    if [[ $line == *"mol pqr"* ]]; then
		        echo "Changed one line in $dirName/apbs.in"
		        line="mol pqr $dirName/$filename.pqr"
		    fi

		    # change the output filename accordingly
		    if [[ $line == *"write pot dx"* ]]; then
		        echo "Changed one line in $dirName/apbs.in"
		        p="_pot"
		        line="write pot dx $dirName/$filename$p"
		    fi
		    
		    
		    echo $line >> "$dirName/apbs.in"
		done < $apbsParametersReference
		
		echo "copied apbsReference from $apbsParametersReference to $dirName/apbs.in"
		
		
		echo "pathToVMD = $pathToVmdExe" 
		echo "Starting vmd..."
		echo "$PathToVMD$VMDcall $OutputFolder $PathToMutComp"
		#if [ ! $pathToVmdExe ] 
		#then
		#      vmd -startup $PathToMutComp/TclScripts/PQRprocess.tcl -args $parametersFile $i
		#else
		    $PathToVMD$VMDcall -startup $PathToMutComp/TclScripts/PQRprocess.tcl -args $parametersFile $i
		#fi
		
	done

	#----------------------------------------------------------------------------------------------------------
	# Correct the boxes for each pqr
	# TODO: do this on-the-fly
	#----------------------------------------------------------------------------------------------------------
	cd $pathToPqrs
	for i in *.pqr; do
		[ -f "$i" ] || break
		
		filename="${i%.*}"

		# extract the box-size from the dx-file.
		# We find the important lines by their number, so dont modify the dx-files!
		
	# # Data from 1.5
	# # 
	# # POTENTIAL (kT/e)
	# # 
	# # object 1 class gridpositions counts 129 129 129
	# # origin 2.665251e+00 -3.124950e+01 -2.517100e+01
	# # delta 4.090430e-01 0.000000e+00 0.000000e+00
	# # delta 0.000000e+00 3.451172e-01 0.000000e+00
	# # delta 0.000000e+00 0.000000e+00 3.810469e-01


		deltaX=0
		deltaY=0
		deltaZ=0
		
		ext="_pot.dx"
		
		declare -i num=1
		
		while read -r line
		do
		    # change the input filename accordingly
		    
		    arr=($line)
		    
		    if [ $num -eq 7 ]; then
		        deltaX=${arr[1]}
		        deltaX=`echo ${deltaX} | sed -e 's/[eE]+*/\\*10\\^/'`
		    elif [ $num -eq 8 ]
		    then
		        deltaY=${arr[2]}
		        deltaY=`echo ${deltaY} | sed -e 's/[eE]+*/\\*10\\^/'`
		    elif [ $num -eq 9 ]
		    then
		        deltaZ=${arr[3]}
		        deltaZ=`echo ${deltaZ} | sed -e 's/[eE]+*/\\*10\\^/'`
		    elif [ $num -gt 10 ]
		    then
		        break
		    fi
		    echo $num $line
		    
		    num=$num+1
		done < "$OutputFolder$filename/$filename$ext"
		
		echo $deltaX $deltaY $deltaZ
		    
		scale=2
		    
		boxX=$(bc -l <<< $deltaX*129*$scale)
		boxY=$(bc -l <<< $deltaY*129*$scale)
		boxZ=$(bc -l <<< $deltaZ*129*$scale)
		
		boxDim="$boxX $boxY $boxZ"
		
		echo "corrected boxDim: $boxDim"
		
		# This is the apbs that is going to be written into
		# outFileApbs=""
		
		# Read in the reference APBS-apbsParameters
		# change some lines that specify the name of the molecule
		# write the file in the newley created directory in "apbs.in"
		# start apbs with this new parameters file
		
		# since we append all the lines on-the-fly, first make sure we have a new 
		# file and don't append to an allready existing one
		

		

		cp "$OutputFolder/$filename/apbs.in" "$OutputFolder/$filename/apbsUncorrected.in"
		
		[ -e "$OutputFolder/$filename/apbs.in" ] && rm "$OutputFolder/$filename/apbs.in"
		
		# read in the reference
		while read -r line
		do
		    # change the input filename accordingly
		    if [[ $line == *"cglen"* ]]; then
		        line="cglen $boxDim"
		    fi

		    if [[ $line == *"fglen"* ]]; then
		        line="fglen $boxDim"
		    fi
		    
		    echo $line >> "$OutputFolder/$filename/apbs.in"
		done < "$OutputFolder/$filename/apbsUncorrected.in"
		
		echo "copied apbsReference from $OutputFolder/$filename/apbsUncorrected.in to $OutputFolder/$filename/apbs.in"
		
		
		echo "Starting vmd..."
		#if [ $pathToVmdExe == ""] 
		#then
		#      vmd -startup $PathToMutComp/TclScripts/PQRprocess.tcl -args $parametersFile $i
		#else
		    $PathToVMD$VMDcall -startup $PathToMutComp/TclScripts/PQRprocess.tcl -args $parametersFile $i
		#fi
		
	#     echo $pathToVmdExe./vmd -startup $pathToTclScript/PQRprocess.tcl -args $inputFolder $outputFolder $i 
	done
else
	echo "skipping vmd ..."
fi

#----------------------------------------------------------------------------------------------------------
# Compile all the output-images into one big one
# Carefull when trying to comnpile a ton of pictures
#----------------------------------------------------------------------------------------------------------

if [ "$doImageCreator" == "true" ]; then
	$pathToImageCreator./imageCreator.sh $OutputFolder
else
	echo "skipping calling imageCreator ..."
fi

#----------------------------------------------------------------------------------------------------------
# Make an animation of all the molecules
#----------------------------------------------------------------------------------------------------------

if [ "$doMovieCreator" == "true" ]; then
	$pathToMovieCreator./movieCreator.sh $OutputFolder
else 
	echo "skipping calling movieCreator ..."
fi

#----------------------------------------------------------------------------------------------------------
# Image-Similarity -> create Trainingsets
#----------------------------------------------------------------------------------------------------------
# create the pairs, create a folder "ImageSimilarity" and copy all images into this folder
# also copy a dummy.png so that we have at least one pair that is "not similar"

if [ "$doCreateTrainingsSet" == "true" ]; then
	$repositoryPath/ImageSimilarity/./createSimilarities.R
else
	echo "skipping creating TraininingsSets ..."
fi






