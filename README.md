# MutComp
A shell script for automized processing of pdb-files with vmd http://www.ks.uiuc.edu/Research/vmd/ and APBS http://www.ks.uiuc.edu/Research/vmd/plugins/apbsrun/.

## Features:
* pdb files are converted to pqr-files.
* the electrostatics are calculated
* creates one big picture containing the es,el,ss pictures of all the input molecules 
* creates a gif containing all el -pictures

# Getting started
Copy the Folder /ExampleHierarchy/ to your desired location.
Rename the folder as you wish.
Copy your pdb-files into /ExampleHierarchy/Input/pdb/

After setting up the folder hierarchy omit the following call from the folder containing Input and Output

    <pathToMutComp>./process.sh

where pathToMutComp is the path to the local repository on your machine.
    
An example is included in M43Copy.
To run the example with you can do:

        cd /M43Copy
        .././process.sh

the results will be stored in /M43Copy/Output.

![](/ImageCreator/overviewM43.png)


# Ordering
If you want to have your pictures appear in a specific ordering add a file **ordering.txt** in the output-folder.
This file has to contain the names of the proteins in the order that you want them to apper in the file **overview.png**.

# Authors
Willy Bruhn, MD Faruq Hossain
