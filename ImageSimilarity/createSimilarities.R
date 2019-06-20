#!/usr/bin/env Rscript

# This script reads in the files in /Output/<protein>/rotations/
# The images in the folder /rotations/ are images of the same molecule viewed from
# different rotations.


# 00_1fov/rotations/

library(stringr)

findAllRotatedImages <- function(output, prefix){
  
  directories = list.dirs(path = output, full.names = TRUE, recursive = FALSE)
  
  images = vector("list", length(directories))
  k = 1
  for(i in directories){
    subFolders = list.dirs(path = i, full.names = TRUE, recursive = FALSE)
    
    for(j in subFolders){
      if(grepl("rotations", j)){
        print(j)
        
        rotatedImages = list.files(path=j)
        
        rotatedImagesWOE = tools::file_path_sans_ext(rotatedImages)
        
        rotatedImagesWOE = paste(prefix, rotatedImagesWOE, sep = "")
        
        #rotatedImagesWOE = paste(substring(j,nchar(output)+1),rotatedImagesWOE, sep = "/")
        print(rotatedImagesWOE)
        
        images[[k]] = rotatedImagesWOE
        k = k+1
      }
    }
  }
  
  # fileConn<-file(fName)
  # writeLines(lines, fileConn)
  # close(fileConn)
  
  return(images)
}

createPairwiseSimilarity <- function(imagesFromSame){
  lines = c()
  for(i in 1:(length(imagesFromSame)-1)){
    for(j in (i+1):length(imagesFromSame)){
      lines = c(lines, paste(imagesFromSame[i], imagesFromSame[j], 0, 0, 0, 0, 1, 1, sep = " "))
    }
  }
  return(lines)
}

createTrainingsSet <- function(images){
  
  lines = c()
  for(i in 1:length(images)){
    lines = c(lines, createPairwiseSimilarity(images[[i]]))
  }
  return(lines)
}

writeTrainingsSet <- function(fName, ts, toBePredicted){
  ts = c(paste("#idim1(1) idim2(2) catim1(3) catim2(4) crap(5) crap(6) labpair[0,1](7) islearn[0,1](8)"),ts)
  ts = c(ts, toBePredicted)
  
  # create the comparison with the dummy
  ts = c(ts, paste("dummy " ,word(ts[2], 2,(length(ts)-4)), " 0 1", sep = ""))
  # ts = c(ts, paste("dummy " ,word(ts[2], 2,(length(ts)-4)), " 0 1", sep = ""))
  
  fileConn<-file(fName)
  writeLines(ts, fileConn)
  close(fileConn)
}

createPredictionSet <- function(images){
  
  lines = c()
  for(i in 1:(length(images)-1)){
    for(j in (i+1):(length(images)-0)){
      print(paste(i, j, sep = " "))
      lines = c(lines, paste(images[[i]], images[[j]], 0, 0, 0, 0, 1, 0, sep = " "))
    }
  }
  
  return(lines)
}

#------------------------------------------------------------------------

path2MutComp = "/home/sysgen/Documents/LWB/TCL/MutComp/"
OutputFolder = "/home/sysgen/Documents/LWB/TCL/100Red2/Output/"
system(paste("rm -r ", OutputFolder,"/similarityImages", sep = ""))

# we need something other than numbers in the beginning of the name otherwise the image-similarity-programm will 
# not find the images
prefix = ""    # added this to the tcl-script

images = findAllRotatedImages(OutputFolder, prefix)
l = createTrainingsSet(images)
pred = createPredictionSet(images)

#word(l[2], 1, (length(l[2])-3))



writeTrainingsSet(paste(OutputFolder,"pairs.txt",sep = ""),l,pred)

#--------------------------------------------------------------------
# copy images in one folder and convert them to png


directories = list.dirs(path = OutputFolder, full.names = TRUE, recursive = FALSE)
system(paste("mkdir ",OutputFolder,"/similarityImages", sep = ""))

for(i in 1:length(directories)){
  for(j in 1:length(images[[i]])){
    system(paste("cp ", directories[i] , "/rotations/", images[[i]][j], ".tga ", OutputFolder, "/similarityImages/", images[[i]][j], ".tga", sep = ""))
    system(paste("convert ", OutputFolder, "/similarityImages/", images[[i]][j], ".tga ",
                              OutputFolder, "/similarityImages/", images[[i]][j], ".png", sep = ""))
    system(paste("rm ", OutputFolder, "/similarityImages/*.tga", sep = ""))
  }
}

system(paste("cp ", path2MutComp, "/ImageSimilarity/dummy.png ", OutputFolder, "/similarityImages/dummy.png", sep = ""))



