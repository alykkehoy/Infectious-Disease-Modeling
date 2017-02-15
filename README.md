## Infectious Diesease Modeling Library

This C++ library can be used to model infectious diseases using both stochastic and deterministic systems with support for known scientific models including SIR/SEIR/SIS as well as the ability to create custom models. As well as the ablility for custom containers to be ceated and used in models.

## Code Example

Show what the library does as concisely as possible, developers should be able to figure out **how** your project solves their problem by looking at the code example. Make sure the API you are showing off is obvious, and that your code is short and concise.

## Installation

Compiling the library can be done by running `make lib` in the stochastic folder.
The sample program can be compiled by running `make` in the stochastic folder.

## Basic Options
#### Creating a Model
Available pre-packed compartments are S, I, R, and E. We recommend using these to create the SIR, SIRS, and SEIR models, but any combiniation is usable. These can be created by calling the model constructor with a string containing the compartment combininations as a name. Here are some examples:
```
Model sir("SIR");
Model seir("SEIR");
Model other("SRIES");
```

#### Creating a Disease
To creat a Disease, create a Disease object with a string for the name, a double representing 1/alpha, a double representing the beta value, and a double for the mortality rate. Additionaly you can add and integer for the range, default set to 1, and an integer for the time representing the incubation period. The range represents the number of spaces in all directions a Disease can infect. Here is an example of creating H1N1 using data from US National Library of Medicine:
```
Disease disease("H1N1", 3, 43, 10);
```

#### Creating a Map
Since Maps are represented as rectangles, to create a Map simply create a Map object with a width and a height. An example of a few maps with a population of 100 are:
```
Map map(10,10);
Map map2(25,4);
Map map3(20, 5);
```

#### Seeding the Map
To seed a Map, call the random_seed function on a Map passing in a Disease and an integer for the number of people to be seeded with the Disease. If a number is not provided the function defaults to 1 person.

#### Taking a Step
To take a step, call the take_step function from the Model and give it the Disease and Map. Multiple steps can be taken by also passing in the number of steps to take. Here are examples of both options:
```
map = sir.take_step(disease, map);
map = sir.take_step(disease, map, 10);
```

#### Printing the Map
To print the Map, call the function print_map on the map.
```
map.print_map();
```

#### Example of Everything Together
This is an example of modeling H1N1 using the SIR model for 50 steps.
```
Model sir("SIR");
Disease disease("H1N1", 3, 43, 10);
Map map(100, 100);
map.random_seed(disease, 2);

map = sir.take_step(disease, map, 50);
map.print_map();
```

## Advanced Options
#### Collecing Data From The Model / Exporting to a CSV
To record your iteration data, initialize a counter for your model and pass in your map. After the model is finished running, to export the data in a csv, call the function 'export_counters' on your model object and pass in a file name to be used.

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

## API

INPROGRESS

## Contributors

Let people know how they can dive into the project, include important links to things like issue trackers, irc, twitter accounts if applicable.

https://docs.google.com/presentation/d/16KkOZWPbrZJvsBUbHZHHWpwsA_D2TFLOCbWqj9dr534/edit#slide=id.g1a11fe49bf_0_9
