
# creates numX*numY pictures stepping through -deltaX to deltaX evenly aswell as for deltaY
# deltaX, deltaY  ... rotations around X, Y -Axis
createViewPoints <- function(fName, deltaX, deltaY, numX, numY){
  xVals = c()
  yVals = c()
  if(numX == 1){
    xVals = c(deltaX)
  } else {
    xVals = seq(-deltaX,deltaX,(deltaX*2)/(numX-1))
  }
  if(numY == 1){
    yVals = c(deltaY)
  } else {
    yVals = seq(-deltaY,deltaY,(deltaY*2)/(numX-1))
  }
  
  # xVals = c(-deltaX:deltaX)
  # yVals = c(-deltaY:deltaY)
  
  lines = c("#x;y;z")
  for(i in xVals){
    for(j in yVals){
      lines = c(lines,paste(i,j,0,sep = ";"))
    }
  }
  
  fileConn<-file(fName)
  writeLines(lines, fileConn)
  close(fileConn)
}


# createViewPoints("/home/sysgen/Documents/LWB/TCL/MutComp/ImageSimilarity/viewPoints.csv",25,25, 4, 4)

createViewPoints("/home/sysgen/Documents/LWB/TCL/MutComp/ImageSimilarity/viewPoints.csv",0,0, 1, 1)
