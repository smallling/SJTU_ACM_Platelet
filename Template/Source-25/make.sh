#!/bin/sh

for i in $(seq 1 $1)
do
    echo $i Starting...
    xelatex -shell-escape -interaction=nonstopmode source.tex >> make.log
    echo $i Done.
done
