#!/bin/bash

# Répertoire contenant vos fichiers XPM
input_dir="./"  # Changez cela si vos fichiers ne sont pas dans le répertoire actuel

# Parcourir tous les fichiers XPM dans le répertoire
for file in "$input_dir"*.xpm; do
    echo "Redimensionnement de : $file"
    convert "$file" -resize 64x64 "$file"
done

echo "Tous les fichiers XPM ont été redimensionnés à 64x64 pixels."
