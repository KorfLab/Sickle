Sickle
======

In order to get the following project to work properly.  You'll also need the current
distribution of StochHMM (http://github.com/KorfLab/StochHMM).

After building HMMER, copy the 3 Libraries (libeasel.a, libhmmer.a, and libhmmerimpl.a)
int the libraries folder.  

After building StochHMM, symbolically link the header files from ./src directory to 
Libraries/includes/StochHMM folder

Open Xcode, and drag the StochHMM static library from the src folder to Xcode (Link Binary
With Libraries window.  This can be found on the Build Phase information page for your 
intended Target.  (ie Sickle)   This will symbolically link the library into your Xcode
project.

Using the symbolic links will ensure that updated versions of StochHMM are imported directly
into your Xcode project. 