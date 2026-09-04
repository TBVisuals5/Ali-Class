#!/bin/bash

# Compile contacts.c
gcc ../c-programs/contacts.c -o contacts

# Run contacts program
./contacts

# Create backup of C programs
tar -czf contacts-backup.tar.gz ../c-programs/*

# Log output time
echo "Output logged at $(date)" >> project-log.txt
