PRE-PACKAGED COMPARTMENTS
==========================
Available pre-packed compartments are S, I, R, and E
We recommend using these to create the SIR, SIS, and SIRS models

MAKING NEW COMPARTMENTS 
=======================
Create the new compartment class and inherit the State class.
Must define the take_step function for your new compartment.
Must define the char representation for your new compartment.

CREATING CUSTOM MODELS
======================
Create a vector using a shared_ptr to hold the compartments. Add your desired compartments to the vector in the proper order. 

COLLECTING DATA FROM THE MODEL
=================================
To record your iteration data, initialize a counter for your model and pass in your map. 

EXPORTING TO A CSV
==================
To export the data, call the single argument function 'export_counters' on your model object, and pass in a file name.
