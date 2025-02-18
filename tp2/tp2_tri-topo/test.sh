#!/bin/bash

date 
echo 

for f in graphes_exemples/*.txt; do
    echo "*************** $f"
    ./tri-topo < "$f"
    echo
done
