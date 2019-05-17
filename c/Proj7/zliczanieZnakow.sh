#!/usr/bin/env bash

sizeA=$(cat producent/* 2>/dev/null | wc -c)
sizeB=$(cat konsument/* 2>/dev/null | wc -c)

if [ $sizeA -eq $sizeB ]; then
  echo "Producenci wyprodukowali: $sizeA znakow"
  echo "Konsumenci odebrali: $sizeB znakow"
  echo "Liczba znakow sie zgadza"
else
  echo "Producenci wyprodukowali: $sizeA znakow"
  echo "Konsumenci odebrali: $sizeB znakow"
  echo "Liczba znakow sie nie zgadza"
fi
