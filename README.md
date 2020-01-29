# exmodel
An example repository holding an external simulation model.

This repository is an example repository showing how to use SuperSim's "main" build target.
SuperSim is designed to easily integrate proprietary simulation models.
In this repository we introduce a continuous traffic pattern called "weird".
The BUILD file links with the supersim:main build target and adds the source code within this repository.
The result is that proprietary models can be easily used with the fully open-source version of SuperSim 
without modified any of the existing code and without maintaining a separate fork of the simulator.

To run the simulator with the weird traffic pattern, run the provided configuration file:
```sh
bazel build :supersim
bazel-bin/supersim config/torus_ioq_blast_weird.json
```
