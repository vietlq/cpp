#!/usr/bin/bash

sudo dtrace -s trace.d -c ./a.out < test07.txt > trace.log 2>&1

