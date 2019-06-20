puts "There are $argc arguments to this script"
puts "Starting $argv0"

set inputFolder "/inputFolder/"
set outputFolder "/outputFolder/"
set file_current "current_file"

set apbsParametersFolder "/home/sysgen/Documents/LWB/TCL/Script/M43/Input/apbsParameters/"
set apbsFileName "apbsReference.in"

 
package require psfgen 	 
topology top_all27_prot_lipid.inp 	 
pdbalias residue HIS HSE 	 
pdbalias atom ILE CD1 CD 	 
segment U {pdb ubqp.pdb} 	 
coordpdb ubqp.pdb U 	 
guesscoord 	 
writepdb ubq.pdb 	 
writepsf ubq.psf 
