#!/bin/bash

# Launch them all
for i in $(ls); do
    if [[ $i == *"santa"* ]]; then
        echo -e "\n<*** ! === TESTING $i ==== ! ***>\n"
        ./$i ;
    fi
done
