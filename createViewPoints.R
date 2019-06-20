

createViewPoints <- function(fName, deltaX, deltaY, num){
  xVals = seq(-deltaX,deltaX,(deltaX*2)/(num-1))
  yVals = seq(-deltaY,deltaY,(deltaY*2)/(num-1))
  
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


createViewPoints("/home/sysgen/Documents/LWB/TCL/MutComp/ImageSimilarity/viewPoints.csv",15,15, 3)
