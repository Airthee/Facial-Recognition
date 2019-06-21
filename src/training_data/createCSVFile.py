#!/bin/env python3

import os, re, sys

# Recover args
if len(sys.argv) < 2:
  raise Exception("Wrong parameters : 1 expected")
root = sys.argv[1]

# Collect data
for (dirpath, dirnames, filenames) in os.walk(root):
  for filename in filenames:
    path = os.path.join(dirpath, filename)
    match = re.search(r'\/s([0-9]+)\/', path)
    if match:
      # Write data
      print("training_data/{};{}".format(path.replace(root + '/', ''), match.group(1)))