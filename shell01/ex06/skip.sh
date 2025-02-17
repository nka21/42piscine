#!/bin/sh

ls -l | awk 'NR != 1 && NR % 2 == 1'
