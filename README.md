## Infectious Diesease Modeling Library

This C++ library can be used to model infectious diseases using both stochastic and deterministic systems with support for known scientific models including SIR/SEIR/SIS as well as the ability to create custom models. As well as the ablility for custom containers to be ceated and used in models.

## Code Example

Show what the library does as concisely as possible, developers should be able to figure out **how** your project solves their problem by looking at the code example. Make sure the API you are showing off is obvious, and that your code is short and concise.

## Installation

Compiling the library can be done by running `make lib` in the stochastic folder.
The sample program can be compiled by running `make` in the stochastic folder.

## Reference
#### Creating a Model
Available pre-packed compartments are S, I, R, and E. We recommend using these to create the SIR, SIRS, and SEIR models, but any combiniation is usable. These can be created by calling the model constructor with a string containing the compartment combininations as a name. Here are some examples:
```
Model sir("SIR");
Model seir("SEIR");
Model other("SRIES");
```

#### Creating Custom Models
To creat a custom model, create a vector using a shared_ptr to hold the Compartments. Push desired compartments to the vector in the order they should be used. Here is an example:
```
std::vector<std::shared_ptr<Compartment>> model;
model.push_back(std::shared_ptr<Compartment>(new S));
model.push_back(std::shared_ptr<Compartment>(new I));
model.push_back(std::shared_ptr<Compartment>(new S));
Model m_custom("SIR", model); //String name, vector of the model
```

#### Creating Custom Compartments 
To create a new custom Compartment, a new class needs to be written that inherits the State class. The take_step function must be defined for the new Compartment, as well as a unique character to represent the Compartment on a Map.

#### Collecing Data From The Model / Exporting to a CSV
To record your iteration data, initialize a counter for your model and pass in your map. To export the data, call the single argument function 'export_counters' on your model object, and pass in a file name.

## API

INPROGRESS

## Contributors

Let people know how they can dive into the project, include important links to things like issue trackers, irc, twitter accounts if applicable.

https://docs.google.com/presentation/d/16KkOZWPbrZJvsBUbHZHHWpwsA_D2TFLOCbWqj9dr534/edit#slide=id.g1a11fe49bf_0_9
