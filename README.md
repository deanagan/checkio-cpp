[![Build Status](https://travis-ci.com/deanagan/practice-cpp.svg?branch=master)](https://travis-ci.com/github/deanagan/practice-cpp)

# Practicing C++
A collection of C++ source code for popular coding platforms like Leetcode, Hackerrank, etc


# How To Run the Source
1. Solutions are divided into folders with the story name. Change directory to one of these folders.
2. To build only, enter `bazel build ...`
3. To build and execute the tests in the test folder, enter `bazel test ... --test_output=all`


# Notes
* When running on systems where you need to specify the exact C++ compiler version, you can add `--cxxopt=-std=c++14`
e.g.<br/>
    * Build Only: `bazel build ... --cxxopt=-std=c++17`
    * Build and Run Test: `bazel test ... --cxxopt=-std=c++17 --test_output=all`

* If you're on *nix type system and want to run valgrind, you can do it against the test:<br/>
`valgrind bazel-bin/test/tests`
