# VMD for LINUXAMD64, version 1.9.3 (November 30, 2016)
# Log file '/home/sysgen/Documents/LWB/TCL/MutComp/TclScripts/mutate3.tcl', created by user sysgen
menu files off
menu files on
display resetview
mol addrep 0
display resetview
mol new {/home/sysgen/Documents/LWB/TCL/M43/Input/pdb/1fov-01-M43A.pdb} type {pdb} first 0 last -1 step 1 waitfor 1
animate style Loop
menu files off
menu tkcon off
menu tkcon on

# step 4
# change output-dir here
animate write pdb {ubqp.pdb} beg 0 end 0 skip 1 0
# step 5 delete mol missing

# step 6 ubq.TclScripts
# step 7 
