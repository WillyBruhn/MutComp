puts "There are $argc arguments to this script"
puts "Starting $argv0"

set inputFolder "/inputFolder/"
set outputFolder "/outputFolder/"
set file_current "current_file"

set apbsParametersFolder "/home/sysgen/Documents/LWB/TCL/Script/M43/Input/apbsParameters/"
set apbsFileName "apbsReference.in"


set x_shift 0
set y_shift 0
set z_shift 0

set x_rot 0
set y_rot 0
set z_rot 0

set parametersFile "parameters"

# --------------------------------------------------------------------------------------
# Process Arguments
# --------------------------------------------------------------------------------------


if {$argc > 2} {
    puts "processing $argv argc is $argc"

	set parametersFile [lindex $argv 0 ]

} else {
    puts "Too few arguments. Need input-dir output-dir file\n"
    exit
} 

# Fixed Bug on 16.2.18
# This was also removing p q r letters from the end of a file
# example: 05_2khp.pqr -> 05_2kh
# set trimmed [string trim $file_current ".pqr"]

# This works though
set trimmed [file rootname [file tail $file_current]]


# --------------------------------------------------------------------------------------
# load settings from .vmdrc
# --------------------------------------------------------------------------------------
# set pathToRc "/home/sysgen"
# puts "loading from .vmdrc..."
# source "$pathToRc/.vmdrc"

set pathToRcBak "/home/sysgen"
puts "loading from .vmdrc.bak..."
source "$pathToRcBak/.vmdrc.bak"

display resize 1175 1012
# --------------------------------------------------------------------------------------
# --------------------------------------------------------------------------------------
# color Display Background white
# axes location Off

# --------------------------------------------------------------------------------------
# Read in Parameters
# --------------------------------------------------------------------------------------

set xTrans 0
set yTrans 0
set zTrans 0

proc readParameters {path} {
    puts "reading parameters from $path ..."
    
    #  Slurp up the data file
    set fp [open $path r]
    set file_data [read $fp]
    close $fp
    
    set count 0

    #  Process data file
    set data [split $file_data "\n"]
    foreach line $data {
        # do some line processing here

        set columns [split $line ";"]
     
        set parameter [lindex $columns 0]
        set value [lindex $columns 1]
        
		if {$parameter == "xTrans"}{
			set xTrans $value
		} else if {$parameter == "yTrans"}{
			set yTrans $value
		} else if {$parameter == "zTrans"}{
			set zTrans $value
		}
        
    }
}

puts "using the following parameters in TCL-script exectuted by VMD:"

puts "xTrans: $xTrans"
puts "yTrans: $yTrans"
puts "zTrans: $zTrans"

# --------------------------------------------------------------------------------------
# Load pqr-file
# --------------------------------------------------------------------------------------

# color Display Background white
# axes location Off

mol new "$inputFolder$file_current" type {pqr} first 0 last -1 step 1 waitfor 1


# --------------------------------------------------------------------------------------
# APBS
# --------------------------------------------------------------------------------------

mol modcolor 0 0 Structure
mol modstyle 0 0 NewCartoon

file mkdir "$outputFolder$trimmed/"

animate write pqr "$outputFolder$trimmed/$trimmed.pqr" beg 0 end 0 skip 1 0




# --------------------------------------------------------------------------------------
# An examplory apbs.in-file might look like this:
# ------------------------------------------
#     read
#   mol pqr /home/sysgen/Documents/LWB/TCL/Script/M43/Output/1fov-01-M43A/1fov-01-M43A.pqr
# end
# elec
#   mg-auto
#   dime 129 129 129
#   cglen 52.35749816894531 44.17500114440918 48.77399969100952
#   cgcent mol 1
#   fglen 52.35749816894531 44.17500114440918 48.77399969100952
#   fgcent mol 1
#   mol 1
#   lpbe
#   bcfl sdh
#   srfm smol
#   chgm spl2
#   ion 1 0.150 2.0
#   ion -1 0.150 2.0
#   pdie  1.0
#   sdie  78.54
#   sdens  10.0
#   srad  1.4
#   swin  0.3
#   temp  298.15
#   gamma  0.105
#   calcenergy no
#   calcforce no
#   write pot dx /home/sysgen/Documents/LWB/TCL/Script/M43/Output/1fov-01-M43A/1fov-01-M43A_pot
# end
# quit
# --------------------------------------------------------------------------------------


apbs "$outputFolder$trimmed/apbs.in"

# display resetview





#save_vp 1


animate style Loop
# menu apbsrun off

# --------------------------------------------------------------------------------------
# Loading dx-files produced with APBS
# --------------------------------------------------------------------------------------

# animate write pqr "/usr/tmp/apbs.52610/$file_current" beg 0 end 0 skip 1 0
# display resetview

set fileName "$outputFolder$trimmed/$trimmed"
append fileName "_pot.dx"

puts $fileName

mol addfile $fileName type dx first 0 last -1 step 1 waitfor 1 0

mol selection all

# rotate y by 10
# rotate y by 30
# rotate z by -10
 
# menu files off
# menu files on
display resetview


# added this on 5.2.18
# display distance -3
#
# display projection Orthographic




puts "$outputFolder$trimmed/$trimmed""_pot.dx\n"


animate style Loop

# --------------------------------------------------------------------------------------
# Loading one reference-molecule in order to have the same boxsize for all molecules
# --------------------------------------------------------------------------------------
 
display resetview
mol addrep 1
display resetview
mol new {/home/sysgen/Documents/LWB/TCL/100Red/Input/pqr/000_DsbC.pqr} type {pqr} first 0 last -1 step 1 waitfor 1

# mol new {/home/sysgen/Documents/MFH/projects/all_Grx/Renamed_all/Input/pqr/02_1fov.pqr} type {pqr} first 0 last -1 step 1 waitfor 1


animate style Loop
mol off 1

# --------------------------------------------------------------------------------------


mol addrep 0
mol modcolor 1 0 Volume 0
mol modstyle 1 0 Surf 1.4 0
mol scaleminmax 0 1 -4 4


mol addrep 0
mol modcolor 2 0 ColorID 0
mol modstyle 2 0 Isosurface 1 0 0 0 1 1

mol addrep 0
mol modcolor 3 0 ColorID 1
mol modstyle 3 0 Isosurface -1 0 0 0 1 1

mol showrep 0 0 1
mol showrep 0 1 0
mol showrep 0 2 1
mol showrep 0 3 1


# --------------------------------------------------------------------------------------
# Render images
# --------------------------------------------------------------------------------------

# reads from a file rotations
# #x;y;z
# 10;0;0
# 0;100;0
# ^ This will render one snapshot with the rotation of 10 
# along the x-axis and one snapshot with the rotation of 100
# along the y-axis.
# Also a subfolder "rotations" is created that contains the snapshots.
proc renderViewpoints {path outputFolder fName ext args} {
    puts "reading viewPoints from $path"
    
    #  Slurp up the data file
    set fp [open $path r]
    set file_data [read $fp]
    close $fp
    
    set count 0

    #  Process data file
    set data [split $file_data "\n"]
    foreach line $data {
        # do some line processing here
        
        if { [string first # $line] == 0 } {
        
            puts "Format is: $line"
        } else {

            set columns [split $line ";"]
         
            set x_rot [lindex $columns 0]
            set y_rot [lindex $columns 1]
            set z_rot [lindex $columns 2]
            
            mol selection all
            rotate x to 0
            rotate y to 0
            rotate z to 0
        
            mol selection all
            rotate x by $x_rot
            rotate y by $y_rot
            rotate z by $z_rot
            
            incr count
            
            
            set sep "_"
            set rotName "rotated"
            set prefix "img"
            
            render snapshot "$outputFolder/$fName/rotations/$prefix$fName$sep$x_rot$sep$y_rot$sep$z_rot$rotName$ext"
            
            
        }
    }
}


puts "rotating by $x_rot $y_rot $z_rot"

mol selection all
rotate x by $x_rot
rotate y by $y_rot
rotate z by $z_rot

puts "translating by $x_shift $y_shift $z_shift"

mol selection all
translate by $x_shift $y_shift $z_shift

set ext1 "_el.tga"
set f1 "$trimmed$ext1"

#------------------------------------------------------------------
# more rotated snapshots with viewPoints from file
#------------------------------------------------------------------
set viewPoints "/home/sysgen/Documents/LWB/TCL/MutComp/ImageSimilarity/viewPoints.csv"
# set viewPoints "/home/willy/RedoxChallenges/MutComp/ImageSimilarity/viewPoints.csv"

file mkdir "$outputFolder/$trimmed/rotations"

# set ext1_1 "_el.png"
set ext1_1 "_el.tga"
renderViewpoints $viewPoints $outputFolder $trimmed $ext1_1

#------------------------------------------------------------------


render snapshot "$outputFolder/$trimmed/$f1"
mol showrep 0 0 1
mol showrep 0 1 1
mol showrep 0 2 0
mol showrep 0 3 0

set ext2 "_es.tga"
set f2 "$trimmed$ext2"
 
render snapshot "$outputFolder/$trimmed/$f2"
mol showrep 0 0 1
mol showrep 0 1 0
mol showrep 0 2 0
mol showrep 0 3 0

set ext3 "_ss.tga"
set f3 "$trimmed$ext3"
render snapshot "$outputFolder/$trimmed/$f3"


# # --------------------------------------------------------------------------------------
# # Render images for imagesimilarity
# # 5.2.2018
# # --------------------------------------------------------------------------------------
# 
# 
# # mol showrep 0 0 1
# # mol showrep 0 1 0
# # mol showrep 0 2 1
# # mol showrep 0 3 1
# # 
# # 
# # set i 0
# # set extSim "simEl.png"
# # set placeHolder "_"
# # 
# # set f4 "$trimmed$placeHolder$i$placeHolder$extSim"
# # rotate y by 10
# # render snapshot "$outputFolder/$trimmed/$f4"
# # 
# # set i 1
# # set f4 "$trimmed$placeHolder$i$placeHolder$extSim"
# # rotate y by -20
# # render snapshot "$outputFolder/$trimmed/$f4"
# # 
# # set i 2
# # set f4 "$trimmed$placeHolder$i$placeHolder$extSim"
# # rotate x by 10
# # render snapshot "$outputFolder/$trimmed/$f4"
# # 
# # set i 3
# # set f4 "$trimmed$placeHolder$i$placeHolder$extSim"
# # rotate x by -20
# # render snapshot "$outputFolder/$trimmed/$f4"
# 
# 
# 
quit


