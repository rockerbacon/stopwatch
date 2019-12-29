#!/bin/bash
apt-package/install.sh g++
apt-package/install.sh cmake
apt-package/install.sh make
git/install.sh https://github.com/rockerbacon/assertions-test.git 2166d534f1fe1e9e88b15383409ec073aebe3198 true "src/objs" "src/objs" ""
