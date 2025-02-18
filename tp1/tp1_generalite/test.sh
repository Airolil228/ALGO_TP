#!/bin/bash

date 
echo 

for f in graphes_exemples/*.txt; do
    echo "*************** $f"
    ./graphe_oriente < "$f"
    echo
done
