 
package require psfgen 	 
topology top_all27_prot_lipid.inp 	 
pdbalias residue HIS HSE 	 
pdbalias atom ILE CD1 CD 	 
segment U {pdb ubqp.pdb} 	 
coordpdb ubqp.pdb U 	 
guesscoord 	 
writepdb ubq.pdb 	 
writepsf ubq.psf
