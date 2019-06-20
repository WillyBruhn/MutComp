# This script reads in the files in /Output/<protein>/rotations/
# The images in the folder /rotations/ are images of the same molecule viewed from
# different rotations.


# 00_1fov/rotations/


install.packages("lpSolve")

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
  
  fileConn<-file(fName)
  writeLines(ts, fileConn)
  close(fileConn)
}

createPredictionSet <- function(images){
  
  lines = c()
  for(i in 1:(length(images)-2)){
    for(j in (i+1):(length(images)-1)){
      print(i, j)
      lines = c(lines, paste(images[[i]], images[[j]], 0, 0, 0, 0, 1, 0, sep = " "))
    }
  }
  
  return(lines)
}

#------------------------------------------------------------------------
OutputFolder = "/home/sysgen/Documents/LWB/TCL/ExampleHierarchy2/Output/"

# we need something other than numbers in the beginning of the name otherwise the image-similarity-programm will 
# not find the images
prefix = ""    # added this to the tcl-script

images = findAllRotatedImages(OutputFolder, prefix)
l = createTrainingsSet(images)
pred = createPredictionSet(images)

writeTrainingsSet(paste(OutputFolder,"pairs.txt",sep = ""),l,pred)


